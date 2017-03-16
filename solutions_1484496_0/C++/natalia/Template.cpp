#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define SMAX 2000006

int mask[SMAX];

void outdata(vector<int> a, int m1, int m2)
{
    vector<int> s1, s2;
    forv(i, a)
    {
        if (m1 & (1 << i))
        {
            s1.pb(a[i]);
        }
        if (m2 & (1 << i))
        {
            s2.pb(a[i]);
        }
    }    

    forv(i, s1)
    {
        if (i) printf(" ");
        printf("%d", s1[i]);
    }
    printf("\n");

    forv(i, s2)
    {
        if (i) printf(" ");
        printf("%d", s2[i]);
    }
    printf("\n");
}
void solve(int test)
{
    printf("Case #%d:\n", test);

    int n;
    cin >> n;

    vector<int> a(n);
    forn(i, n) cin >> a[i];

    memset(mask, -1, sizeof(mask));

    forn(ms, (1 << n))
    {
        if (ms == 0) continue;
        int sum = 0;
        forn(i, n)
        {
            if (ms & (1 << i))
            {   
                sum += a[i];
            }
        }
        if (mask[sum] == -1) mask[sum] = ms;
        else
        {
            outdata(a, mask[sum], ms);
            return;
        }
    }

    cout << "Impossible\n";

}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc;
    scanf("%d\n", &tc);
    forn(it, tc) solve(it + 1);
    
    return 0;
}