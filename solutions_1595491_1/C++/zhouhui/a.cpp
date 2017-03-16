#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct p
{
    int a,b,c;
} pp[120];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int k=1; k<=t; k++)
    {
        int n,s,p,y[110],cnt=0,num=0;
        scanf("%d%d%d",&n,&s,&p);
        for(int i=0; i<n; i++)
            scanf("%d",&y[i]);
            sort(y,y+n);
        for(int i=0; i<n; i++)
        {
            if(y[i]%3==0)
            {
                if(y[i]/3>=p)
                cnt++;
                else if(y[i]/3+1>=p&&y[i]/3-1>=0&&num<s)
                {
                    cnt++;
                    num++;
                }
            }
            else if(y[i]%3==1)
            {
                if(y[i]/3>=p)
                cnt++;
                else if(y[i]/3+1>=p)
                cnt++;
            }
            else if(y[i]%3==2)
            {
                if(y[i]/3>=p)
                cnt++;
                else if(y[i]/3+1>=p)
                cnt++;
                else if(y[i]/3+2>=p&&num<s)
                {
                    cnt++;
                    num++;
                }
            }
        }
        printf("Case #%d: %d\n",k,cnt);
    }
    return 0;
}
