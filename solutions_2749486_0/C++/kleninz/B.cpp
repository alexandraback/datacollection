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

using namespace std;

typedef long long ll;

int tests;
int x, y;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> tests;
    forn (it, tests) {
        cin >> x >> y;
        int j = 0;
        printf("Case #%d: ", it + 1);
        if (x > 0) {
            forn (i, x) {
                printf("WE");
            }
        }
        if (x < 0) {
            forn (i, -x) {
                printf("EW");
            }
        }
        if (y > 0) {
            forn (i, y) {
                printf("SN");
            }
        }
        if (y < 0) {
            forn (i, -y) {
                printf("NS");
            }
        }
        printf("\n");
    }
    return 0;
}
