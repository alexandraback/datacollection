#include <iostream>
#include <algorithm>

using namespace std;

string s;

int main () {
    int testCases;
    cin >> testCases;
    for(int caseNumber = 1; caseNumber <= testCases; ++caseNumber) {
        cout << "Case #" << caseNumber << ": ";
        cin >> s;
        int answer = 0;
        for(int i = (int)s.length() - 1; i >= 0; i--) if (s[i] == '-') {
            for(int j = 0; j <= i; j++) if (s[j] == '-') s[j] = '+'; else s[j] = '-';
            ++answer;
        }
        cout << answer << endl;
    }
    return 0;
}