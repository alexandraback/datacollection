#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int cases; cin >> cases;
    for (int cn = 1; cn <= cases; cn++) {
        cout << "Case #" << cn << ": ";

        string s; cin >> s;

        for (int turn = 0; ; turn++) {
            auto last = s.rfind('-');
            if (last == string::npos) {
                cout << turn << endl;
                break;
            }

            int ps = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == '+') ps = i + 1;
                else break;
            }

            if (ps > 0) {
                for (int i = 0; i < ps; i++) s[i] = '-';
                turn++;
            }

            for (int i = 0; i <= last; i++) {
                s[i] = s[i] == '+' ? '-' : '+';
            }

            for (int i = 0; i < last - i; i++) {
                swap(s[i], s[last - i]);
            }
        }
    }
    return 0;
}
