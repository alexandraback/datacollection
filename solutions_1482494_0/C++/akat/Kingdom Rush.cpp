#include<cstdio>
#include<algorithm>
using namespace std;
struct ha
{
  int a;
  int b;
};
bool cmp(ha c,ha d)
{
    return c.b<d.b;
}
void solve()
{
    int n,i,p=0,s=0,br[2000],o;
    ha a[2000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].a,&a[i].b);
        br[i]=0;
    }
    sort(a,a+n,cmp);
    o=0;
    while(p<n)
    {
        o++;
        if(s>=a[p].b)
        {
            s+=2-br[p];
            br[p]=2;
            p++;
            //printf("%d %d %d\n",p,s,br[p-1]);
        }
        else
        {
            bool l=0;
            for(i=n-1;i>=p;i--)
            {
                if(a[i].a<=s && br[i]==0)
                {
                    br[i]=1;
                    s++;
                    l=1;
                    //printf("%d %d %d %d\n",p,i,s,br[i]);
                    break;
                }
            }
            if(l==0)
            {
                printf("Too Bad\n");
                return;
            }
        }
    }
    printf("%d\n",o);
}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        printf("Case #%d: ",i+1);
        solve();
    }
}
