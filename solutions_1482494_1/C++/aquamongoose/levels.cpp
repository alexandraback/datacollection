#include <vector>
#include <list>
#include <cassert>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef pair <int,int> ii;
const int INF = 0x3f3f3f3f;
const int MAXN = 1010;

struct level
{
    int rate, need, ind, other;
    level(int a, int b, int c, int d)
    {
        rate = a;
        need = b;
        ind = c;
        other = d;
    }
};

int n;
bool solved[MAXN*2], one[MAXN*2];
vector <level> levels;

void solve()
{
    memset(solved, false, sizeof(solved));
    memset(one, false, sizeof(one));
    levels.clear();
    int a,b,s=0;
    int stars = 0;
    int ret = 0;
    cin >> n;
    levels.reserve(2*n);
    for (int i=0; i<n; i++)
    {
        cin >> a >> b;
        levels.push_back(level(1,a,i,b));
        levels.push_back(level(2,b,i,a));
    }

    while (s < n)
    {
        level best = level(0,0,0,0);
        for (int i=0; i<levels.size(); i++)
        {
            if (solved[levels[i].ind] || (levels[i].rate == 1 && one[levels[i].ind])) continue;
            if (stars < levels[i].need) continue;

            if (levels[i].rate > best.rate) best = levels[i];
            else if (levels[i].rate == 2 && !one[levels[i].ind] && one[best.ind]) best = levels[i];
            else if (levels[i].rate == 1 && best.rate == 1 && levels[i].other > best.other) best = levels[i];
        }

        if (best.rate == 0)
        {
            cout << "Too Bad\n";
            return;
        }

        if (best.rate == 2)
        {
            s++;
            solved[best.ind] = true;
            stars += best.rate-one[best.ind];
        }
        else
        {
            one[best.ind] = true;
            stars++;
        }
        ret++;
    }
    cout << ret << endl;
}

int main()
{
    int t; cin >> t;
    for (int kase=1; kase<=t; kase++)
    {
        cout << "Case #" << kase << ": ";
        solve();
    }
    return 0;
}
