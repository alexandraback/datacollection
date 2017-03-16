#include <bits/stdc++.h>
#define ll long long
using namespace std;

int E[50][2];
int cnt;

void gen_edge(int n)
{
    cnt=0;
    for(int a=1;a<=n;a++)
    {
        for(int b=a+1;b<=n;b++)
        {
            E[cnt][0]=a;
            E[cnt][1]=b;
            cnt++;
        }
    }
}

vector<int>G[10];
bool bi[20][20];
int hcnt;
int N;

void recur(int i)
{
    if(i==N)
    {
        hcnt++;
        return;
    }
    for(int a=0;a<G[i].size();a++)
    {
        recur(G[i][a]);
    }
    return;
}

int main()
{
    freopen("0.in","r",stdin);
    freopen("0.out","w",stdout);

    int a,b,c,d,e,x,y,z,t,n;

    scanf("%d",&t);

    for(int te=1;te<=t;te++)
    {
        printf("Case #%d: ",te);

        scanf("%d %d",&n,&z);

        N=n;

        gen_edge(n);
        //cout<<cnt<<endl;

        for(a=1;a<(1<<cnt);a++)
        {
            for(b=1;b<=n;b++) G[b].clear();
            for(b=1;b<=n;b++)
            {
                for(c=1;c<=n;c++) bi[b][c]=false;
            }

            for(b=0;b<cnt;b++)
            {
                if((a&(1<<b)))
                {
                    x=E[b][0];
                    y=E[b][1];

                    G[x].push_back(y);

                    bi[x][y]=true;
                }
            }
            hcnt=0;
            recur(1);
            if(hcnt!=z) continue;
            break;
        }

        if(a!=(1<<cnt))
        {
            printf("POSSIBLE\n");

            for(b=1;b<=n;b++)
            {
                for(c=1;c<=n;c++) if(bi[b][c]) printf("1"); else printf("0");
                printf("\n");
            }
        }
        else
        {
            printf("IMPOSSIBLE\n");
        }

    }


    return 0;
}
