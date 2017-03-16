#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <map>
using namespace std;
using namespace std::tr1;

#define rep(i, n) for (int i = 0; i < n; ++i)
int ri() { int a; scanf( "%d", &a ); return a; }
long long rll() { long long a; scanf( "%lld" , &a ); return a ; }

struct ATTACK
{
    int s;
    int x;
    int y;
    ATTACK(int _s, int _x, int _y) : s(_s), x(_x), y(_y){} 
};

int wall[500];
int main()
{
    freopen("C:\\Users\\Administrator\\Desktop\\C-small-attempt1.in","rt",stdin);
    freopen("C:\\Users\\Administrator\\Desktop\\B-small-attempt0.out","wt",stdout);
	
    int T = ri();
    rep(t, T)
    {
        int N, d, n, w, e, s, dd, dp, ds;
        N = ri();
        map<int, vector<ATTACK>> wars;
        int x = INT_MAX, y = INT_MIN;
        rep(i, N)
        {
            cin>>d>>n>>w>>e>>s>>dd>>dp>>ds;
            int ss = s;
            for (int j = d, times = 1; times <= n; j += dd, times++)
            {
                x = min(x, w);
                y = max(y, e);
                wars[j].push_back(ATTACK(s, w, e));
                s += ds;
                w += dp;
                e += dp;
            }
        }
        //int *wall = new int[2*y + 1];
        memset(wall, 0, sizeof(wall));
        int res = 0;
        map<int, vector<ATTACK>>::iterator it = wars.begin();
        for (; it != wars.end(); it++)
        {
            vector<ATTACK> att = it->second;
            for (int i = 0; i < att.size(); ++i)
            {
                for (int j = (att[i].x - x) * 2; j <= (att[i].y - x) * 2; ++j)
                {
                    if (wall[j] < att[i].s)
                    {
                        res++;
                        break;
                    }
                }
            }

            for (int i = 0; i < att.size(); ++i)
            {
                for (int j = (att[i].x - x) * 2; j <= (att[i].y - x) * 2; ++j)
                {
                    wall[j] = max(wall[j], att[i].s);
                }
            }
        }

        printf("Case #%d: ", t+1);
        printf("%d\n", res);
        //delete [] wall;
    }
    return 0;
}