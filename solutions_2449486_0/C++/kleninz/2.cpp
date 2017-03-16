#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define INF 2e9
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < n; i++)
#define MAXN 200

using namespace std;

typedef long long ll;

int t;
int a[MAXN][MAXN];
int n, m;

bool solve() {
    forn (i, n) {
        forn (j, m) {
            int flag1 = 1, flag2 = 1;
            forn (k, n) {
                if (a[k][j] > a[i][j]) {
                    flag1 = 0;
                }
            }
            forn (k, m) {
                if (a[i][k] > a[i][j]) {
                    flag2 = 0;
                }
            }

            if (!flag1 && !flag2) {
                //printf(">%d %d\n", i, j);
                return false;
            }
        }
    }
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    forn (it, t) {
        cin >> n >> m;
        forn (i, n) {
            forn (j, m) {
                cin >> a[i][j];
            }
        }
        printf("Case #%d: ", it + 1);
        if (solve()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
