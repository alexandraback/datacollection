#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <cstring>

typedef long long i64d;

using namespace std;

typedef struct
{
    int w , e , s , day;
}Att;

int cmp(Att x , Att y)
{
    return x.day < y.day;
}
int main()
{
	freopen("C-small-attempt0.in" , "r" , stdin);
	freopen("C-small-attempt0.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int n;
        vector<Att> a;
        scanf("%d" , &n);
        for (int i = 0; i < n; i ++)
        {
            int d , nn, w , e , s;
            int dd , dp , ds;
            scanf("%d %d %d %d %d %d %d %d" , &d , &nn , &w , &e , &s , &dd , &dp , &ds);
            for (int j = 0; j < nn; j ++)
            {
                Att x;
                x.day = d;
                x.w = w;
                x.e = e;
                x.s = s;
                a.push_back(x);
                d += dd;
                w += dp;
                e += dp;
                s += ds;
            }
        }
        sort(a.begin() , a.end() , cmp);
        int wallL[500] = {0};
        int wallR[500] = {0};
        int res = 0;
        int i = 0;
        while (i < a.size())
        {
            int s = i;
            int t = s + 1;
            while (t < a.size() && a[t].day == a[s].day) t ++;
            for (int j = s; j < t; j ++)
            {
                int ok = 1;
                if (wallR[a[j].w + 200] < a[j].s) ok = 0;
                for (int k = a[j].w + 1; k < a[j].e; k ++)
                {
                    if (wallL[k+200] < a[j].s || wallR[k+200] < a[j].s) {ok = 0; break;}
                }
                if (wallL[a[j].e + 200] < a[j].s) ok = 0;
                if (ok == 0) res ++;
            }
            for (int j = s; j < t; j ++)
            {
                wallR[a[j].w + 200] = max(wallR[a[j].w + 200] , a[j].s);
                wallL[a[j].e + 200] = max(wallL[a[j].e + 200] , a[j].s);
                for (int k = a[j].w+1; k < a[j].e; k ++)
                {
                    wallL[k+200] = max(wallL[k+200] , a[j].s);
                    wallR[k+200] = max(wallR[k+200] , a[j].s);
                }
            }
            i = t;
        }
        printf("%d\n" , res);
    }
    return 0;
}