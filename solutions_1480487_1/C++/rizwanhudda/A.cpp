#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define EPS 1e-9
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out6.txt","w",stdout);
    int T,N,S[210];
    double lo,hi,mid,frac[210],sfrac,sums,prfrac[210],res[210];
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&N);
        sums=0;
        for(int i=0;i<N;i++){
            scanf("%d",&S[i]);
            sums+=S[i];
        }
        for (int i=0;i<N;i++)
        {
            lo=S[i];
            hi=sums+S[i];
            prfrac[i]=0;
            while (1)
            {
                mid = (lo+hi)/2;
                sfrac=0;
                for (int j=0;j<N;j++)
                    {
                        if (S[j]>mid)frac[j]=0;
                        else
                        frac[j]=(mid-S[j])/sums;
                        sfrac+=frac[j];
                    }
                //printf("%d %lf\n",i,frac[i]);
                if (fabs(prfrac[i]-frac[i])<EPS){
                        //printf("%lf\n",sfrac);
                        break;
                }
                prfrac[i]=frac[i];
                if (sfrac>1+EPS)
                    hi=mid;
                else
                    lo=mid;
            }
            res[i]=frac[i];
        }
        printf("Case #%d:",t);
        for(int i=0;i<N;i++)printf(" %.6lf",res[i]*100);
        printf("\n");
    }
    return 0;
}

