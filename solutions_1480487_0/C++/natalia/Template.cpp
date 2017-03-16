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

#define MAGIC 60

bool can(vector<int>& s, int id, double y)
{
    int sum = 0;
    forv(i, s) sum += s[i];
    double mn = s[id] + sum * y;

    double sumy = y;
    forv(i, s)
    {
        if (i == id) continue;
        if (s[i] < mn)
        {
            sumy += (mn - s[i]) / sum;            
        }
    } 

    return sumy > 1;
}
double calc(vector<int>& s, int i)
{
    double L = 0, R = 1.0;

    forn(it, MAGIC)
    {
        double mid = (L + R) / 2;
        if (can(s, i, mid))
        {
            R = mid;
        }
        else
        {
            L = mid;
        }
    }
    return L;
}
void solve(int test)
{
    printf("Case #%d:", test);

    int n; cin >> n;
    vector<int> s(n);

    forn(i, n) 
    {
        cin >> s[i];
    }

    forn(i, n)
    {
        printf(" %.6lf", 100.0 * calc(s, i));
    }
    printf("\n");
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