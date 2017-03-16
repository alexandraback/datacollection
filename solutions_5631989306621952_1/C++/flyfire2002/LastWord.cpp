#include <iostream>
#include <string>
using namespace std;

string construct(string original) {
    string res = "";
    for (int i = 0; i < original.length(); i++) {
        if (res.compare("") == 0) {
            res += original[i];
        } else {
            if (original[i] >= res[0]) {
                res.insert(0, 1, original[i]);
            } else {
                res += original[i];
            }
        }
    }

    return res;
}



int main () {
    int T;
    string dummy;
    cin >> T;
    getline(cin, dummy);
    for (int t = 1; t <= T; t++) {
        string letter;
        getline(cin, letter);
        cout << "Case #" << t << ": " << construct(letter) << endl;
    }
    return 0;
}
