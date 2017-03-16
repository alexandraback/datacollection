#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn=20+9;
const int inf=1e9+9;

int G[maxn][maxn];

int dfs(int b,int m);

int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int cass=1;
    while(t--)
    {
        int b;
        long long m;
        cin>>b>>m;
        printf("Case #%d: ",cass++);
        int tmp=(b-1)*(b-2)/2+1;
        if(m>(ll)tmp)
        {
            printf("IMPOSSIBLE\n");continue;
        }
        printf("POSSIBLE\n");
        memset(G,0,sizeof(G));

        ll cnt=1;
        for(int i=1;i<b;i++)
            G[i][i+1]=1;
        int s=1,e=3;
        while(cnt<m)
        {
            G[s][e]=1;
            e++;
            if(e>b)
            {
                s++;e=s+2;
            }
            cnt++;
        }

        for(int i=1;i<=b;i++)
        {
            for(int j=1;j<=b;j++)
            {
                printf("%d",G[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

