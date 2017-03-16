#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    for (int C=1; C<=cases; C++) {
        string word;
        string new_word = "";
        cin >> word;
        new_word += word[0];
        for (int i=1; i<word.length(); i++) {
            char w = word[i];
            if (w >= new_word[0]) {
                new_word = w + new_word;
            } else {
                new_word = new_word + w;
            }
        }
        cout << "Case #" << C << ": " << new_word << endl;
    }
}
