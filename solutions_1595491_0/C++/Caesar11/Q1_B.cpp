#include<cstdio>
#include<cstring>
#define N 1000
using namespace std;

int main()
{
    int t,n,s,i,p,a,b,c,sum,ans,ys;

    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);

    scanf("%d",&t);
    ys=0;
    while (t--)
    {
        scanf("%d%d%d",&n,&s,&p);

        ans=0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&sum);

            if (sum%3==0)
            {
                a=b=c=sum/3;

                if (c>=p)
                    ans++;
                else if (p-c==1&&a-1>=0&&s>0)
                {
                    s--;
                    ans++;
                }
            }
            else if (sum%3==1)
            {
                a=b=c=sum/3;
                c++;

                if (c>=p)
                    ans++;
            }
            else
            {
                a=b=c=sum/3;
                b++;c++;

                if (c>=p)
                    ans++;
                else if (p-c==1&&s>0)
                {
                    s--;
                    ans++;
                }
            }
        }

        printf("Case #%d: %d\n",++ys,ans);
    }

    return 0;
}

