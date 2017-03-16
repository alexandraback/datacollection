#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
int pow[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
set<int>s;

main()
{
    int t,a,b,ys,ans,x,y,l,i,j;

    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    scanf("%d",&t);
    ys=0;
    while (t--)
    {
        scanf("%d%d",&a,&b);

        ans=0;
        for (i=a;i<=b;i++)
        {
            x=i;
            s.clear();
            l=0;
            while (x/pow[l])
                l++;

            for (j=1;j<l;j++)
            {
                y=x/pow[j]+(x%pow[j])*pow[l-j];

                if (y>x&&y<=b&&s.count(y)==0)
                {
                    s.insert(y);
                    ans++;
                }
            }
        }

        printf("Case #%d: %d\n",++ys,ans);
    }

    return 0;
}


