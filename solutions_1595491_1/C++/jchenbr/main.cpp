#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int n,m,p,ans,total,cc=0;
    cin>>total;
    while (total--)
    {
        scanf("%d%d%d",&n,&m,&p);
        ans=0;
        int tmp,now;
        while (n--)
        {
            scanf("%d",&tmp);
            now=tmp/3;
            if (tmp%3==0)
            {
                if (now>=p)ans++;
                else if (m>0&&now>0&&now+1>=p)ans++,m--;
            }else if (tmp%3==1)
            {
                if (now+1>=p)ans++;
            }else if (tmp%3==2)
            {
                //printf("{%d ,%d ,%d,%d}\n",tmp,now,m,ans);
                if (now+1>=p)ans++;
                else if (m>0&&now+2>=p)ans++,m--;
            }
        }
            printf("Case #%d: ",++cc);
            printf("%d\n",ans);
    }
}
