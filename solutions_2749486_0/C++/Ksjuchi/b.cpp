#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

typedef long long i64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<i64> vi64;
typedef vector< vector<i64> > vvi64;
typedef vector<bool> vb;

const int MOD = 1000000007;
const int INF = MOD;

int main()
{
    std::ios_base::sync_with_stdio(false);
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int t;
    cin >> t;
    for (int cnt = 1; cnt <= t; ++cnt)
    {
        int x, y;
        cin >> x >> y;
        bool px, py;
        if (x > 0)
        {
            px = true;
        }
        else
        {
            px = false;
        }
        if (y > 0)
        {
            py = true;
        }
        else
        {
            py = false;
        }
        
        string res;
        for (int i = 0; i < abs(y); ++i)
        {
            if (py)
            {
                res += "SN";
            }
            else
            {
                res += "NS";
            }
        }
        for (int i = 0; i < abs(x); ++i)
        {
            if (px)
            {
                res += "WE";
            }
            else
            {
                res += "EW";
            }
        }

        cout << "Case #" << cnt << ": " << res << endl;
    }
    // system("PAUSE");
    return 0;
}
