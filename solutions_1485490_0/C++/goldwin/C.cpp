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
#define MAX 120

using namespace std;

typedef long long ll;
typedef pair<int,ll> toy;

int n,m;
vector<toy> boxes;
vector<toy> toys;

ll memo[MAX][MAX];

ll f(int a,int b)
{
    if(a >= n || b >= m) return 0;
    ll & ret = memo[a][b];
    //if(ret != -1) return ret;
    if(boxes[a].first == toys[b].first)
    {
        ll val = min(boxes[a].second, toys[b].second);
        boxes[a].second -= val; toys[b].second -= val;
        ret = val + max(f(a+1, b), f(a, b+1));
        boxes[a].second += val; toys[b].second += val; 
    }
    else ret = max(f(a+1,b),f(a,b+1));
    return ret; 
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small.out","w",stdout);
    int t;
    scanf("%d",&t);
    FOR(ca,1,t)
    {
        memset(memo,-1,sizeof(memo));
        scanf("%d %d",&n,&m);
        toys.clear(); boxes.clear();
        FOR(i,0,n-1)
        {
            int a;
            ll b;
            scanf("%I64d %d",&b,&a);
            boxes.push_back(toy(a,b));
        }
        FOR(i,0,m-1)
        {
            int a;
            ll b;
            scanf("%I64d %d",&b,&a);
            toys.push_back(toy(a,b));
        }
        printf("Case #%d: %I64d\n",ca,f(0,0));
    }
    FOR(i,0,1) getchar();
    return 0;
}
