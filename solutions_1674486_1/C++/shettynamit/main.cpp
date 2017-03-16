#include <iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define N 1000
#define INF 100000000

using namespace std;

vector<int> E[N];
int D[N];

int main()
{
    int t,n,i,j,k,u,v,l,p,s;
    queue<int> Q;
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&t);
    bool yes;
    p=1;
    while(t>0)
    {
        scanf("%d",&n);
        yes=false;
        for(i=0;i<n;i++)
        {
            scanf("%d",&l);
            E[i].clear();
            for(j=0;j<l;j++)
            {
                scanf("%d",&k);
                E[i].push_back(k-1);
            }
        }

        for(s=0;s<n;s++)
        {
            fill(D,D+n,INF);
            D[s]=0;
            while(!Q.empty())
                Q.pop();

            Q.push(s);
            while(!Q.empty())
            {
                u=Q.front();
                k=E[u].size();
                for(i=0;i<k;i++)
                {
                    v=E[u][i];
                    if(D[v]!=INF)
                    {
                        yes=true;
                        break;
                    }
                    else
                    {
                        D[v]=D[u]+1;
                        Q.push(v);
                    }
                }
                if(yes)
                    break;
                Q.pop();
            }
            if(yes)
                break;
        }
        printf("Case #%d: ",p);
        if(yes)
            printf("Yes\n");
        else
            printf("No\n");
        yes=false;
        t--;
        p++;
    }
    return 0;
}
