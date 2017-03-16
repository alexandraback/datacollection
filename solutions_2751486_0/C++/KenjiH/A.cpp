#include <algorithm>
#include <iostream>
#include <climits>
#include <list>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>

using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  

bool isVowel(char c) {
    if (c == 'a') return true;
    if (c == 'i') return true;
    if (c == 'u') return true;
    if (c == 'e') return true;
    if (c == 'o') return true;
    return false;
}

void solve() {
    string s;
    int n;
    cin >> s >> n;

    int ret = 0;
    REP (i, s.length()) FOR (j, i, s.length()) {
        int cnt = 0;
        
        FOR (k, i, j+1) {
            if (isVowel(s[k]))
                cnt = 0;
            else
                cnt++;
            if (cnt >= n) {
                ++ret;
                break;
            }
        }
    }
    cout << ret << endl;
}

int main() {
    int T;
    cin >> T;
    REP (i, T) {
        printf("Case #%d: ", i+1);
        solve();
    }
    return 0;
}
