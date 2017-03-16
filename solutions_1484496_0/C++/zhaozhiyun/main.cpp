#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int maxn=500;
const int maxm=(1<<23);

int data[maxn+10];
int table[maxm+10];
int n;
int ans1[maxn+10],ans2[maxn+10];

void output(int a,int b)
{
    bool flag=false;
    int c=2,k=1;
    while(a>=c)
    {
        if(a&c)
        {
            ans1[k]=1;
        }
        c<<=1;
        k++;
    }
    c=2; k=1;
    a=b;
    while(a>=c)
    {
        if(a&c)
        {
            ans2[k]=1;
        }
        c<<=1;
        k++;
    }
}

bool dfs(int k,int s,int p)
{
    if(k==n+1)
    {
        if(table[s])
        {
            output(table[s],p);
            return true;
        }
        else
        {
            table[s]=p;
            return false;
        }
    }
    for(int i=k;i<=n;i++)
    {
        if(dfs(i+1,s+data[i],p+(1<<i))) return true;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&n);
        printf("Case #%d:\n",t);
        memset(ans1,0,sizeof(ans1));
        memset(ans2,0,sizeof(ans2));
        memset(table,0,sizeof(table));
        for(int i=1;i<=n;i++) scanf("%d",&data[i]);
        if(dfs(1,0,0))
        {
            bool temp=true;
            for(int i=1;i<=n;i++)
            {
                if(ans1[i]==1&&ans2[i]!=1)
                {
                    if(temp)
                    {
                        printf("%d",data[i]);
                        temp=false;
                    }
                    else printf(" %d",data[i]);
                }
            }
            printf("\n");
            temp=true;
            for(int i=1;i<=n;i++)
            {
                if(ans2[i]==1&&ans1[i]!=1)
                {
                    if(temp)
                    {
                        printf("%d",data[i]);
                        temp=false;
                    }
                    else printf(" %d",data[i]);
                }
            }
            printf("\n");
        }
        else printf("Impossible\n");
    }
    return 0;
}
