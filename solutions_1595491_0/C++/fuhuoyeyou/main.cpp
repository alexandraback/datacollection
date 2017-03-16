#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int shu[200];
int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("1.txt", "w", stdout);
    int casenum;
    scanf("%d",&casenum);
    int num=1;
    int n,t,p;
    int tp,ans=0;
    while(casenum--)
    {
       scanf("%d%d%d",&n,&t,&p);
       tp=ans=0;
       for(int i=0;i<n;++i)
          scanf("%d",&shu[i]);
       for(int i=0;i<n;++i)
       {
           if(shu[i]%3==0)
           {
               if(shu[i]/3>=p)
               {
                   ++ans;
               }
               else if( shu[i]!=0&&shu[i]/3+1>=p && tp<t)
               {
                   ++ans;
                   ++tp;
               }
           }
           else if(shu[i]%3==1)
           {
               if(shu[i]/3+1>=p)
                 ++ans;
           }
           else if(shu[i]%3==2)
           {
               if(shu[i]/3+1>=p)
                 ++ans;
                else if(shu[i]/3+2>=p && tp<t)
                {
                    ++ans;
                    ++tp;
                }
           }
       }
       printf("Case #%d: %d\n",num++,ans);
    }
    return 0;
}
