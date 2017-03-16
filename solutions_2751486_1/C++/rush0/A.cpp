#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define OUT(x) cerr << #x << ": " << (x) << endl
#define SZ(x) ((int)x.size())
#define FOR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long LL;

int T;
char s[1000 * 1000 + 5];
int ls, n;

bool in_consonants(char x) {
    return !(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
}

int main() {
    scanf("%d", &T);
    for (int id = 1; id <= T; ++id) {
        scanf("%s%d", s, &n);
        ls = strlen(s);
        set<int> end;
        int cnt = 0;
        FOR(i, n) cnt += in_consonants(s[i]);
        for (int i = n; i <= ls; ++i) {
            if (cnt == n) {
                end.insert(i - n);
            }
            if (i == ls) break;
            cnt -= in_consonants(s[i - n]);
            cnt += in_consonants(s[i]);
        }

        LL ans = 0;
        for (int i = 0; i < ls; ++i) {
            set<int>::iterator it = end.lower_bound(i);
            if (it != end.end()) {
                ans += ls - (*it + n) + 1;
            }
        }
        cout << "Case #" << id << ": " << ans << endl;
    }
    return 0;
}
