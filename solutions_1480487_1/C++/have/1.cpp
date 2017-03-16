#include<cstdio>
using namespace std;
int a[205];
double b[205],t[205];
bool use[205];
int main ()
{
    freopen("A-large.in","r",stdin);
    freopen("1.out","w",stdout);
    int nn,n,sum,sum1,num;
    double aver;
    scanf("%d",&nn);
    for(int i=1; i<=nn; ++i){
        scanf("%d",&n);
        sum=0;
        for(int j=1; j<=n; ++j){
            use[j]=1;
            scanf("%d",&a[j]);
            sum+=a[j];
        }
        sum1=sum;
        num=n;
        printf("Case #%d:",i);
        for(int j=1; j<=n; ++j)
            t[j]=double(a[j])/sum;
        aver=2/double(n);
        for(int j=1; j<=n; ++j)
            if(aver<=t[j]){
                b[j]=0;
                use[j]=0;
                --num;
                sum1-=a[j];
            }
        aver=double(sum+sum1)/num;
        for(int j=1;j<=n;++j)
            if(use[j]){
                b[j]=(aver-a[j])/sum;
            }
        for(int j=1; j<=n; ++j)
            printf(" %.6lf",b[j]*100);
        printf("\n");
    }
    return 0;
}

