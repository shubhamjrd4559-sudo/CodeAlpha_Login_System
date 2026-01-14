#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to check if username already exists
bool userExists(const string& username) {
    ifstream file("users.txt");//read mode
    string u, p;

    while (file >> u >> p) {//File se ek-ek karke username password read karta hai
        if (u == username) {
            return true;//Agar username match ho jaye → true return
        }
    }
    return false;
}

int main() {
    int choice;
    string username, password;

    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // REGISTER
        if (choice == 1) {
            cout << "Enter username: ";
            cin >> username;

            if (userExists(username)) {
                cout << "Username already exists!\n";
                continue;  // → wapas menu
            }

            cout << "Enter password: ";
            cin >> password;

            ofstream file("users.txt", ios::app);//ofstream(for write mode) and ios::app ye → purana data delete nahi hoga, new add hoga end me

            if (!file) {
                cout << "Error opening file!\n";
                continue;
            }

            file << username << " " << password << endl;
            file.close();

            cout << "Registration successful!\n";
        }

        // LOGIN
        else if (choice == 2) {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            ifstream file("users.txt");
            string u, p;
            bool found = false;  //→ batata hai login success hua ya nahi

            while (file >> u >> p) {
                if (u == username && p == password) {
                    found = true;
                    break;
                }
            }
            file.close();

            if (found)
                cout << "Login successful!\n";
            else
                cout << "Invalid username or password!\n";
        }

        // EXIT
        else if (choice == 3) {
            cout << "Program exited.\n";
            break;
        }

        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
