#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <sstream>

using namespace std;

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()

#define pi 3.14159265358979323846

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

int table[4][4] = {
{1, 2, 3, 4},
{2, -1, 4, -3},
{3, -4, -1, 2},
{4, 3, -2, -1}
};

int sign(int x)
{
    if (x > 0) return 1;
    return -1;
}
int mult(int a, int b)
{
    int s = sign(a) * sign(b);
    return s * table[abs(a) - 1][abs(b) - 1];
} 
void solve(int test)
{
    printf("Case #%d: ", test + 1);

    int l, x; cin >> l >> x;
    string pt; cin >> pt;

    string s = "";
    forn(i, x) s += pt;

    int i = 0;
    int cur = 1;
    int v[3];
    v[0] = 2; v[1] = 3; v[2] = 4;
    int j = 0;

    for (; i < (int)s.size(); i++)
    {
        if (s[i] == 'i') cur = mult(cur, 2);
        if (s[i] == 'j') cur = mult(cur, 3);
        if (s[i] == 'k') cur = mult(cur, 4);
        if (cur == v[j])
        {
            if (j < 2)
            {
                j++;
                cur = 1;
            }
            else if (i == (int)s.size()-1)
            {
                cout << "YES\n";
                return;
            }
        }    
    } 

    cout << "NO\n";
}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc; cin >> tc;
    forn(it, tc) solve(it);

    return 0;
}

