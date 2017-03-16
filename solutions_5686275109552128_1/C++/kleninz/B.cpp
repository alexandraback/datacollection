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

const int MAXN = 1010;
int a[MAXN];

int main()
{
    int tests;
    cin >> tests;
    forn (it, tests) {
        int n, ans = 1000;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int bound = 1; bound < MAXN; bound++) {
            int res = 0;
            for (int i = 0; i < n; i++) {
                res += a[i] / bound - 1;
                if (a[i] % bound) {
                    res++;
                }
            }
            ans = min(ans, res + bound);
        }

        cout << "Case #" << it + 1 << ": " << ans << endl;
    }
   
    return 0;
} 
