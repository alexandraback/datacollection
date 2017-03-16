#include <stdio.h>
#include <algorithm>

using namespace std;

int N,s[200+200];

bool check(int i,double j,int sum)
{
    double tmp=0;
    for (int k=0;k<N;k++)
    if (k!=i) {
        if (s[i]+j-s[k]>=-1e-9)
            tmp+=s[i]+j-s[k];
    }
    //printf("%lf\n",tmp);
    if (tmp<sum-j-1e-7) return false;
    return true;
}
int main()
{
    freopen("d:\input.txt","r",stdin);
    freopen("d:\output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int times=1;times<=T;times++)
    {
        scanf("%d",&N);
        int sum=0;
        for (int i=0;i<N;i++)
        {
            scanf("%d",&s[i]);
            sum+=s[i];
        }
        //printf("%d\n",check(1,10,10));
        //return 0;
        //return 0;
        printf("Case #%d:",times);
        //printf("%d\n",check(1,sum,sum));
        //printf("%d\n",sum);
        for (int i=0;i<N;i++)
        {
            double l=0,r=sum,res;
            while (l<r-(1e-9))
            {
                double j=(l+r)/2;
                //printf("%d\n",j);
                if (check(i,j,sum)) {
                    res=r=j;
                    //printf("hello world");
                } else l=j;
               // printf("%f %f\n",l,r);
            }
            printf(" %.6f",res*100.0/sum);
        }
        printf("\n");
    }
}



