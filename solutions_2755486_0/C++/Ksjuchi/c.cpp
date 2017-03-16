#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
#include <stack>

using namespace std;

typedef unsigned long long u64;
typedef long long i64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;

const i64 INF = (i64) 1000 * 1000 * 1000 * 1000 * 1000 * 100;
const int MOD = 1000000007;

struct Attack
{
    int day, l, r, stress;

    bool operator< (Attack oth)
    {
        return day < oth.day;
    }
};

int height[1010];

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cnt = 1; cnt <= t; ++cnt)
    {
        vector<Attack> attacks;

        int n;
        cin >> n;

        int d, num, w, e, s, delta_d, delta_p, delta_s;
        for (int i = 0; i < n; ++i)
        {
            cin >> d >> num >> w >> e >> s >> delta_d >> delta_p >> delta_s;
            w *= 2;
            e *= 2;
            delta_p *= 2;
            Attack tmp;
            tmp.day = d;
            tmp.l = w;
            tmp.r = e;
            tmp.stress = s;
            for (int j = 0; j < num; ++j)
            {
                attacks.push_back(tmp);
                tmp.day += delta_d;
                tmp.l += delta_p;
                tmp.r += delta_p;
                tmp.stress += delta_s;
            }
        }

        sort(attacks.begin(), attacks.end());

        memset(height, 0, sizeof(height));
        int delta_x = 500;
        int count = 0;
        
        for (int i = 0; i < attacks.size();)
        {
            int j = i + 1;
            for (; j < attacks.size() && attacks[j].day == attacks[i].day; ++j);
            for (int k = i; k < j; ++k)
            {
                for (int x = attacks[k].l; x <= attacks[k].r; ++x)
                {
                    if (height[x + delta_x] < attacks[k].stress)
                    {
                        ++count;
                        break;
                    }
                }
            }
            for (int k = i; k < j; ++k)
            {
                for (int x = attacks[k].l; x <= attacks[k].r; ++x)
                {
                    height[x + delta_x] = max(height[x + delta_x], attacks[k].stress);
                }
            }

            i = j;
        }
        cout << "Case #" << cnt << ": " << count << endl;
    }
    
    // system("PAUSE");
    return 0;
}