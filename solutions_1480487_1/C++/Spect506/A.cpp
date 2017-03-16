#include<stdio.h>
#include<string.h>
#include<algorithm>
#define eps 1e-10
using namespace std;
int n;
double a[201],sum,nowa[201],tt;
bool hash[201];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int test,qq,i,j,k;
    scanf("%d",&test);
    for(qq=1;qq<=test;qq++)
    {
      scanf("%d",&n);
      sum=0;
      for(i=1;i<=n;i++)
      {
        scanf("%lf",&a[i]);
        sum+=a[i];
      }
      printf("Case #%d: ",qq);
      /*for(i=1;i<=n;i++)
      {
        double tmp=2.0/n-a[i]/sum;
        if(tmp<0)tmp=0;
        printf("%.6lf ",tmp*100);
      }*/
      for(i=1;i<=n;i++)
      {
        memcpy(nowa,a,sizeof(a));
        sort(&nowa[1],&nowa[n]+1);
        int nown=n;
        double nowsum=sum;
        for(j=n;j>=1;j--)
        {
          double tmp=nowsum/(sum*nown)+1.0/nown-a[i]/sum;
          if((nowsum-a[i]+(1-tmp)*sum)/(nown-1)+eps<nowa[j])
          {
            nowsum-=nowa[j];
            nown--;
          }
          else break;
        }
        double tmp=nowsum/(sum*nown)+1.0/nown-a[i]/sum;
        if(tmp<0)tmp=0;
        printf("%.6lf ",tmp*100);
        tt+=tmp;
      }
      //printf("\n%lf\n",tt);
      printf("\n");
      tt=0;
    }
}
