#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int m;
int n;
int touch[1001];
int road[1001][1001]={0};
bool search(int head)
{
    for(int i=0;i<n;i++)
    {
        if(road[head][i]==1&&head!=i)
        {
            if(touch[i]==1)
                {return 1;}

            else
            {
                touch[i]=1;
                if(search(i))
                    return 1;
            }
        }
    }
    return 0;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("1.out","w",stdout);
    int t;
    cin>>t;
    int ori=t;
    while(t--)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                road[i][j]=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&m);
            for(int j=0;j<m;j++)
            {
                int tem;
                scanf("%d",&tem);
                road[i][tem-1]=1;
            }
        }
        bool flag=0;

        for(int i=0;i<n;i++)
        {
            for(int i=0;i<n;i++)
                touch[i]=0;
            if(search(i))
            {
                flag=1;
                break;
            }

        }
        printf("Case #%d: ",ori-t);
        if(flag==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
