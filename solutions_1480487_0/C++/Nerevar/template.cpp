#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <cmath>
#include <cassert>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define for1(i, n) for (int i = 1; i <= (int)(n); i++)
#define forv(i, v) forn(i, v.size())

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const ld EPS = 1e-10;

#define NMAX 205

int s[NMAX];
int n;

void solve(int tc)
{
    cerr << tc << endl;
    printf("Case #%d:", tc);

    cin >> n;
    int x = 0;
    forn(i, n) 
    {
        cin >> s[i];
        x += s[i];
    }

    forn(i, n)
    {
        ld l = 0, r = 1;

        forn(it, 80)
        {
            ld mid = (l + r) / 2;

            ld sum = mid;

            forn(j, n)
            {
                if (j == i) continue;

                if (s[i] + x * mid - s[j] < EPS) continue;

                sum += (s[i] + x * mid - s[j]) / x;
                
                if (sum > 1 + EPS) break;
            } 

            if (sum > 1) r = mid; else l = mid;
        }

        printf(" %.10lf", (double)r * 100);
    }
    printf("\n");
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int tc;
    cin >> tc;
    forn(it, tc) solve(it + 1);
    return 0;
}
