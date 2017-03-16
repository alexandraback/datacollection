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
#define MAX 100010
#define ll long long
#define INF (1<<30)
#define pvi pair<vector<int>, int>
#define MP make_pair
int xx[] = {1,1,0,-1,-1,-1,0,1}, yy[] = {0,1,1,1,0,-1,-1,-1}; //eight direction

using namespace std;

map<pvi, bool>mp;

vector<int>adj[30];
int req[30], n;
int ans[30];

bool rec(vector<int>cur, int mask)
{
    int popc = __builtin_popcount(mask);
    if(popc==n)
    {
        return true;
    }
    if(mp.find(MP(cur, mask))==mp.end())
        mp[MP(cur, mask)] = true;
    else return false;
    int i, j, k, ret=0;
    vector<int>tmp;
    for(i=0;i<n;i++)
    {
        if((mask&(1<<i))==0)
        {
            for(j=0;j<SZ(cur);j++)
            {
                if(cur[j]==req[i])
                {
                    tmp = cur;
                    tmp.erase(tmp.begin()+j);
                    for(k=0;k<SZ(adj[i]);k++)
                        tmp.pb(adj[i][k]);
                    sort(tmp.begin(), tmp.end());
                    ans[popc] = i+1;
                    ret = rec(tmp, mask|(1<<i));
                    if(ret) return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    freopen("small.in", "r", stdin);
    freopen("small.out", "w", stdout);
    int t, cas=1;
    scanf("%d", &t);
    while(t--)
    {
        vector<int>tmp;
        int k, i, j, now, key;
        scanf("%d%d", &k, &n);
        for(i=0;i<k;i++)
        {
            scanf("%d", &now);
            tmp.pb(now);
        }
        sort(tmp.begin(), tmp.end());
        for(i=0;i<=n;i++) adj[i].clear();

        for(i=0;i<n;i++)
        {
            scanf("%d%d", &req[i], &now);
            for(j=0;j<now;j++)
            {
                scanf("%d", &key);
                adj[i].pb(key);
            }
        }
        mp.clear();
        bool sol = rec(tmp, 0);
        csprnt;
        if(!sol) cout<<"IMPOSSIBLE"<<endl;
        else
        {
            for(i=0;i<n;i++)
            {
                if(i!=0) printf(" ");
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}

