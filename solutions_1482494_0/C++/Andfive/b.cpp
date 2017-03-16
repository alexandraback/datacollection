#include<cstdio>
#include<cstdlib>
using namespace std;
struct pp
{
    int a,b;
} qq[1005];
int cmp(const void *a,const void *b)
{
    pp *aa=(pp *)a;
    pp *bb=(pp *)b;
    if(aa->b!=bb->b)
        return  aa->b-bb->b;
    return aa->a-bb->a;
}
bool t[1005];
int main ()
{
    freopen("B-small-attempt3.in","r",stdin);
    freopen("jian4.out","w",stdout);
    int nn,n,now,ans;
    bool flag;
    scanf("%d",&nn);
    for(int i=1; i<=nn; ++i)
    {
        scanf("%d",&n);
        for(int j=0; j<n; ++j)
            t[j]=0;
        for(int j=0; j<n; ++j)
            scanf("%d%d",&qq[j].a,&qq[j].b);
        qsort(qq,n,sizeof(qq[0]),cmp);
        printf("Case #%d: ",i);
        now=0;
        ans=0;
        flag=1;
        for(int j=0; j<n; ++j)
        {
            if(qq[j].b>now)
            {
                //for(int k=n-1; k>=j; --k)
                //{
                    if(!t[n-1] && qq[n-1].a<=now)
                    {
                        t[n-1]=1;
                        ++now;
                        ++ans;
                        //if(qq[j].b<=now)
                            //break;
                    }
                //}
            }
            if(qq[j].b<=now)
            {
                if(t[j])
                    ++now;
                else
                    now+=2;
                ++ans;
            }
            else
            {
                flag=0;
                break;
            }
        }
        if(flag)
            printf("%d\n",ans);
        else
            printf("Too Bad\n");
    }
    return 0;
}
