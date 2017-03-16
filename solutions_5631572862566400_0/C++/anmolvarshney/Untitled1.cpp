/* Created by Anmol Varshney */

#include <stdio.h>
#include <string.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])
#define INT_MIN -2147483647
#define INT_MAX 2147483647
#define INF 2000000000
#define INF_LL 9223372036854775807LL
#define PI acos(-1.0)
#define llu long long unsigned
#define ll long long int
#define ld long int
#define iter(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define REP(p,a,b) for(int p=a;p<b;p++)
#define mod 1000000007
#define getchar_unlocked getchar
#define pb(f) push_back(f)
#define pob(f) pop_back(f)
#define pf(f) push_front(f)
#define pof(f) pop_front(f)
#define mkp(a,b) make_pair(a,b)
#define fst first
#define snd second
#define pii pair<int,int>
#define ins(a) insert(a)

int gcd(int a,int b)
{
    if(b>a) return gcd(b,a);
    else if(b!=0) return (b,a%b);
    else return a;
}

vector<int> adj[1001];
bool vis[1001];
int ans;

void dfs(int v,int len,int n)
{
    bool flag=false;
    vis[v]=true;
    ans=max(ans,len);
    REP(i,0,adj[v].size())
    {
        if(!vis[adj[v][i]])
        {
            flag=true;
            dfs(adj[v][i],len+1,n);
        }
    }
    if(!flag)
    {
        REP(i,1,n+1)
        {
            if(!vis[i])
            {
                REP(j,0,adj[i].size())
                {
                    if(adj[i][j]==v)
                    {
                        flag=true;
                        vis[i]=true;
                        ans++;
                        break;
                    }
                }
            }
            if(flag) break;
        }
    }
}

int main() {
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x;
    cin>>t;
    for(int l=1;l<=t;l++)
    {
        ans=0;
        memset(vis,false,sizeof(vis));
        REP(i,0,1002)
            adj[i].clear();
        cin>>n;
        REP(i,0,n)
        {
            cin>>x;
            adj[i+1].pb(x);
        }
        REP(i,1,n+1)
        {
            if(!vis[i])
            {
                dfs(i,0,n);
            }
        }
        cout<<"Case #"<<l<<": "<<ans+1<<endl;
    }
    return 0;
}
