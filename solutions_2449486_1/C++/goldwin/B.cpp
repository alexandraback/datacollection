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

int m,n;
int arr[110][110];

bool hasCutPath(int row,int col)
{
    int h = arr[row][col];
    bool ans1 = true,ans2 = true;
    FOR(i,0,m-1)
    {
        if(h < arr[i][col])
        {
            ans1 = false;
            break;
        }
    }
    FOR(i,0,n-1)
    {
        if(h < arr[row][i]) 
        {
            ans2 = false;
            break;
        }
    }
    return ans1 || ans2;
}

void solve(int ca)
{
    scanf("%d %d",&m,&n);
    FOR(i,0,m-1)
    {
        FOR(j,0,n-1) scanf("%d",&arr[i][j]);
    }
    printf("Case #%d: ",ca);
    //cerr << "Case " << ca << ":" << endl;
    FOR(i,0,m-1)
    {
        FOR(j,0,n-1)
        {
            if(!hasCutPath(i,j))
            {
                //cerr << i << " " << j << endl;
                puts("NO");
                return;
            }
        }
    }
    puts("YES");
}

int main()
{
    int t;
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&t);
    FOR(ca,1,t)
    {
        solve(ca);
    }
    return 0;
}
