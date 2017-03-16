#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int testCase = 1; testCase <= t; ++ testCase) {
        string original;
        cin >> original;
        string result = "";
        char first = original.at(0);
        for (char c : original) {
            if (c >= first) {
                result = c + result;
                first = c;
            } else {
                result = result + c;
            }
        }
        cout << "Case #" << testCase << ": " << result << endl;
    }
    return 0;
}