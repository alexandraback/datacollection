#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <cmath>

typedef long long ll;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forv(i, v) forn(i, v.size())

using namespace std;


string words[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

string letters = "ZWXURTFISO";
int digits[] = {0, 2, 6, 4, 3, 8, 5, 9, 7, 1};

void solveCase(int tc) {
    printf("Case #%d: ", tc);
    cerr << tc << endl;
    string str;
    cin >> str;
    vector<int> cnt(26);
    forv(i, str) {
        cnt[str[i] - 'A']++;
    }
    
    vector<int> cntDigit(10);
    
    forn(i, 10) {
        int d = digits[i];
        cntDigit[d] = cnt[letters[i] - 'A'];
        forv(j, words[d]) {
            cnt[words[d][j] - 'A'] -= cntDigit[d];
        }
    }
    
    forn(i, 10) {
        forn(j, cntDigit[i]) {
            cout << i;
        }
    }
    cout << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc; cin >> tc;
    forn(it, tc) solveCase(it + 1);
    return 0;
}
