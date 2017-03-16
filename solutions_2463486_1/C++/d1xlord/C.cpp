#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<string>
#include<sstream>
#include<ctype.h>
#include<vector>
#include<map>
#include<queue>
#include<math.h>
#include<algorithm>
#include<set>

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case #%d: ", cas++);
#define EPS 1e-9
#define MAX 10000000
#define ll long long
#define INF (1<<30)
#define pii pair<int, int>
#define MP make_pair
int xx[] = {1,1,0,-1,-1,-1,0,1}, yy[] = {0,1,1,1,0,-1,-1,-1}; //eight direction

using namespace std;

vector<ll>sol;

bool chk(ll now)
{
    stringstream ss;
    ss<<now;
    string inp;
    ss>>inp;
    for(int i=0, j=SZ(inp)-1;i<SZ(inp)/2;i++,j--)
    {
        if(inp[i]!=inp[j]) return false;
    }
    return true;
}

void gen()
{
    ll i, j, k;
    ll now, cur;
    for(now=1;now<=MAX;now++)
    {
        if(chk(now))
        {
            if(chk(now*now))
                sol.pb(now*now);
        }
    }
    return;
}

int main()
{
    freopen("large.in", "r", stdin);
    freopen("large.out", "w", stdout);
    int t, cas=1;
    gen();
//    for(int i=0;i<SZ(sol);i++)
//        cout<<sol[i]<<" ";
//    cout<<endl;
    scanf("%d", &t);
    while(t--)
    {
        ll i, a, b, cnt=0, cur;
        cin>>a>>b;
        for(i=0;i<SZ(sol);i++)
        {
            cur = sol[i];
            if(cur>=a && cur<=b) cnt++;
        }
        csprnt;
        cout<<cnt<<endl;
    }
    return 0;
}

