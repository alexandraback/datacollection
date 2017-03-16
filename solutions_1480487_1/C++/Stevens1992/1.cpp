#include <iostream>
#include <cstdio>
using namespace std;

int p[205];
double q[205],m[205];
bool s[205];

int main ()
{
    freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
    int t,n,sum,tmp,num,cas=1;
    double key;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum=0;
        for(int i=1; i<=n; i++)
        {
            s[i]=1;
            scanf("%d",&p[i]);
            sum+=p[i];
        }
        tmp=sum;
        num=n;
        printf("Case #%d:",cas++);
        for(int i=1; i<=n; i++)
            m[i]=double(p[i])/sum;
        key=2/double(n);
        for(int i=1; i<=n; i++)
		{
            if(key<=m[i])
            {
                q[i]=0;
                s[i]=0;
                --num;
                tmp-=p[i];
            }
		}
        key=double(sum+tmp)/num;
        for(int i=1;i<=n;i++)
		{
            if(s[i])
                q[i]=(key-p[i])/sum;
		}
        for(int i=1; i<=n; i++)
            printf(" %.06lf",q[i]*100);
        printf("\n");
    }
    return 0;
}
