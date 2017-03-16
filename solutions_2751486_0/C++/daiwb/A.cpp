#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long LL;

int len;

bool check(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void run() {
    string str;
    int n;
    cin >> str >> n;
    len = str.length();
    int res = 0;
    REP(i,len) {
        FOR(j,i,len-1) {
            int cnt = 0, mx = 0;
            FOR(k,i,j) {
                if (check(str[k])) {
                    mx = max(mx, cnt);
                    cnt = 0;
                } else {
                    ++cnt;
                }
            }
            mx = max(mx, cnt);
            if (mx >= n) ++res;
        }
    }
    cout << res << endl;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
