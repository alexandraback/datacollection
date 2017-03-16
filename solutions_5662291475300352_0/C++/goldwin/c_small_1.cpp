#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define FOR(a,b,c) for(int (a) = (b), _n = (c); (a) <= _n ; (a)++)
#define FORD(a,b,c) for(int (a) = (b), _n = (c) ; (a) >= _n ; (a)--)
#define FOR_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) <= _n ; (a)+= _m )
#define FORD_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) >= _n ; (a)-= _m)
#define EACH(v,it) for(__typeof(v.begin()) it = v.begin(); it != v.end() ; it++)
#define INF 200000000
#define MAX 1

using namespace std;

struct Hiker
{
    int d,m;    
};

vector<Hiker> v;

int main()
{
    int t;
    scanf("%d",&t);
    for(int ca = 1; ca <= t ; ca++)
    {
        int n;
        v.clear();
        scanf("%d",&n);
        int mins = INF;
        for(int i = 0; i < n ; i++)
        {
            int d,h,m;
            scanf("%d %d %d",&d,&h,&m);            
            mins = min(mins,m);
            for(int j = 0; j < h ; j++)
            {
                Hiker h;
                h.d = d;
                h.m = m + j;
                v.push_back(h);
            }
        }
        int ans = 0;
        EACH(v,it)
        {
            if(mins == it->m) continue;
            double v1 = 360.0 / (double)mins;
            double v2 = 360.0 / (double) it->m;
            double s2 = (double)it->d;
            double t = s2/(v1 - v2);
            if(v1 * t < 360) ans = 1;
        }
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
