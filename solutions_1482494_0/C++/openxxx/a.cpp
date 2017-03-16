#include<map>
#include<set>
#include<cmath>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int T,N;
struct node
{
    int id,a,b;
};

node g[1100],f[1100];
int s[1100];

bool cmp(node x,node y)
{
    return x.b<y.b;
}

int main()
{
    //freopen("B-small-attempt0.in","r",stdin);
    //freopen("B-small-attempt0.out","w",stdout);
    cin>>T;
    for(int ca=1;ca<=T;ca++)
    {
        cin>>N;
        for(int i=1;i<=N;i++)
        {
            scanf("%d%d",&g[i].a,&g[i].b);
            g[i].id=i;
            f[i].a=g[i].a;
            f[i].b=g[i].b;
            f[i].id=g[i].id;
        }
        sort(f+1,f+N+1,cmp);
        memset(s,0,sizeof(s));
        int cwj=0;
        int ans=N;
        bool flag=true;
        int i=0;
        while(1)
        {
            if(i==N) break;
            while(i<N)
            {
                if(f[i+1].b<=cwj)
                {
                    cwj+=(2-s[f[i+1].id]);
                    s[f[i+1].id]=2;
                    i++;
                }
                else break;
            }
            if(i==N) break;
            int tag=-1,fuck=-1;
            for(int j=1;j<=N;j++)
            {
                if(s[j]==0)
                {
                    if(g[j].a<=cwj)
                    {
                        if(g[j].b>fuck)
                        {
                            fuck=g[j].b;
                            tag=j;
                        }
                    }
                }
            }
            if(tag==-1)
            {
                flag=false;
                break;
            }
            else
            {
                s[tag]=1;
                cwj++;
                ans++;
            }
        }
        if(flag)
        {
            printf("Case #%d: %d\n",ca,ans);
        }
        else
        {
            printf("Case #%d: Too Bad\n",ca);
        }
    }
    return 0;
}

















