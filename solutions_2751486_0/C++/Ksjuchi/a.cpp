#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>

#pragma comment(linker, "/stack:64000000")

using namespace std;

typedef unsigned long long u64;
typedef long long int i64;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

const int MOD = 1000000007;
const int INF = 1000 * 1000 * 1000;
const double EPS = 1e-9;
const long double PI = acos(-1.0);
char s[1000500];
int conseq[1000500];

int main() 
{
    // std::ios_base::sync_with_stdio(false);
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int t;
    cin >> t;
    for (int cnt = 1; cnt <= t; ++cnt)
    {
        int n;
        scanf("%s%d", s, &n);
        int len = strlen(s);
        conseq[0] = 0;
        for (int i = 0; i < len; ++i)
            if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
            {
                conseq[i + 1] = conseq[i] + 1;
            }
            else
            {
                conseq[i + 1] = 0;
            }
        int l = 0, r = 0;
        i64 res = 0;
        while (r < len)
        {
            if (conseq[r + 1] >= n && r - l >= n - 1)
            {
                res += len - r;
                ++l;
            }
            else
            {
                ++r;
            }
        }
        cout << "Case #" << cnt << ": " << res << endl;
    }


    // system("PAUSE");
    return 0;	
}