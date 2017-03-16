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

int memo[20][10];

int e,n,r;
int arr[1000];

int f(int ind,int energy)
{
    //cerr << ind << " " << energy << endl;
    if(ind == n) return 0;
    if(e < 0) return 0;
    int & ret = memo[ind][energy];
    if(ret != -1) return ret;
    int en = arr[ind];
    ret = 0;
    FOR(i,0,energy)
    {
        ret = max(ret, f(ind+1,min(e,energy - i + r)) + en * i);
    }
    return ret;
}

int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small.out","w",stdout);
    int t;
    scanf("%d",&t);
    FOR(ca,1,t)
    {
        memset(memo,-1,sizeof(memo));
        scanf("%d %d %d",&e,&r,&n);
        FOR(i,0,n-1)scanf("%d",&arr[i]);
        printf("Case #%d: %d\n",ca,f(0,e));
    }
    return 0;
}
