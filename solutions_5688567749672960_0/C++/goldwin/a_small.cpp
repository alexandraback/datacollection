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

char temp[120];

int reverse(int x)
{
    int ret = 0;
    while(x > 0)
    {
        ret = ret * 10 + (x % 10);
        x/=10;
    }
    return ret;
}

int memo[2000000];

int dp(int n)
{
    for(int i = 1; i <= n; i ++)
    {
        memo[i] = INF;
    }
    for(int i = 1; i <= n; i++)
    {
        if(memo[i] == INF) memo[i] = 1;
        //cerr << i << " " << memo[i] << endl;
        memo[i+1] = min(memo[i] + 1,memo[i+1]);
        int x = reverse(i);
        if(x > i && x <= n) memo[x] = min(memo[x],memo[i] + 1);
    }
    return memo[n];
}

int main()
{
    int t;
    scanf("%d",&t);    
    for(int ca = 1; ca <= t; ca++)
    {
        cerr << "solving case-" << ca << endl;
        int x;
        scanf("%d",&x);        
        printf("Case #%d: %d\n",ca,dp(x));
    }
    return 0;
}
