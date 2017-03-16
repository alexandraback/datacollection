/*
 * =====================================================================================
 *
 *       Filename:  A.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12.05.2013 12:50:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andrey Timoshpolsky (shpolsky), shpolsky@yandex-team.ru (shpolsky@gmail.com)
 *        Company:  Russia, Yandex
 *
 * =====================================================================================
 */

#include <iostream>
#include <stdio.h>
#include <string>
#include <set>

using namespace std;

char vows[] = {'a', 'e', 'i', 'o', 'u'};
const set<char> vowels(vows, vows + 5);

void solve() {
    string s;
    int n;
    cin >> s;
    cin >> n;
    int start = 0, end = 0, lowBorder = 0;
    bool prevVowel = true;
    long long res = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (vowels.find(s[i]) == vowels.end()) {
            if (prevVowel) {
                start = i;
                end = i;
            } else {
                if (end - start + 1 < n) {
                    end += 1;
                } else {
                    start += 1;
                    end += 1;
                }
            }
            if (end - start + 1 == n) {
                int after = s.length() - end;
                int before = start - lowBorder + 1;
                //cout << "i: " << start << "; j: " << end << "; lowBorder: " 
                //    << lowBorder << "; before: " << before << "; after: " << after << endl;
                res += before * after;
                lowBorder = start + 1;
            }
            prevVowel = false;
        } else {
            prevVowel = true;
        }
    }
    cout << res;
}

int main( int argc, char *argv[] ) {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cout << "Case #" << i+1 << ": ";
        solve();
        cout << endl;
    }
}
