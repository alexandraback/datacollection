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

bool ableToPlace(int r1,int c1, int r, int c)
{
    if(r1 <= r && c1 <= c) return true;
    if(c1 <= r && r1 <= c) return true;
    return false;
}

bool solve(int x, int r, int c)
{
    if((r * c) %x  != 0) return true;
    if(x == 4 && r * c == 8) return true;
    for(int i = 1; i <= x; i++)
    {
        int h = i;
        int w = x / i + x % i;        
        bool res=ableToPlace(h,w,r,c);
        //cerr << h << " " << w << " " << res << endl; 
        if(!res) return true;
    }
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int ca = 1; ca <= t; ca++)
    {
        int x,r,c;
        scanf("%d %d %d",&x,&r,&c);
        printf("Case #%d: ",ca);
        if(solve(x,r,c)) puts("RICHARD");
        else puts("GABRIEL");
    }
    return 0;
}
