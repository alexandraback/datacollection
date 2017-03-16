#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define eps 1e-8
#define db double
#define rt return
#define cn const
#define op operator
#define N 30
#include<queue>
using namespace std;

char a[N],b[N],c[N];
int K,L,S;
int mx;

queue<int> q;

void dfs(int k)
{
    if(k== S)
    {
        int ans=0;
        for(int i=0;i+L<=S;i++)
        {
            bool f=true;
            for(int j=0;j<L && f;j++)
            {
                if(b[j]!=c[i+j]) f=false;
            }

            if(f) ans++;

        }

        mx=max(mx,ans);

        q.push(ans);

     return;

    }

    for(int i=0;i<K;i++)
    {
        c[k]=a[i];
        dfs(k+1);
    }
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("b.out","w",stdout);
    int T;
    scanf("%d",&T);

    for(int ca=1;ca<=T;ca++)
    {

        scanf("%d%d%d",&K,&L,&S);
        gets(a);
        gets(a);
        gets(b);

//        puts(a);
//        puts(b);
        mx=0;
        dfs(0);

        int ans=0;

        while(!q.empty())
        {
            int v=q.front();q.pop();
            ans += mx- v;
            //printf("%d  %d --\n",mx,v);
        }



        double w= ans*1.0/ pow(K*1.0,S);

       // printf("%d  %d\n",ans,mx);

        printf("Case #%d: %.8lf\n",ca,w);


    }
    return 0;
}

