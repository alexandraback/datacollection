#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SZ(v) ((int)(v).size())
#define FOR(i, a, b) for (typeof(a) i = (a); i < (b); ++i)
#define FORD(i, a, b) for(typeof(a) i = (a);i >= (b); --i)
#define FOREACH(iter, v) for (typeof((v).begin()) iter = (v).begin(); iter != (v).end(); ++iter)
#define REP(i, n) FOR(i, 0, n)

using namespace std;

#define SMALL 1

bool vowel(char ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main()
{

#if SMALL
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
#else
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
#endif

    int T;
    cin >> T;
    int n;
    string s;

    for (int tc = 1; tc <= T; ++tc) {
        cin >> s >> n;
        int ans = 0;
        int sz = SZ(s);
        for (int i = 0; i < sz; ++i)
            for (int j = i + n - 1; j < sz; ++j) {
                int c = 0;
                for (int k = i; k <= j; ++k) {
                    if (!vowel(s[k])) {
                        ++c;
                        if (c >= n) {
                            ++ans;
                            break;
                        }
                    }
                    else c = 0;
                }
            }
        printf("Case #%d: %d\n", tc, ans);
    }

	return 0;
}
