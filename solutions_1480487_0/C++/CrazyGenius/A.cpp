#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int main()
{
    int _cc;
    scanf("%d",&_cc);
    for(int _c = 1 ; _c <= _cc ; _c++)
    {
        int n,x=0,share,sum=0;
        scanf("%d",&n);
        int judge[n];
        double ans[n],gone = 0,avg;

        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d",&judge[i]);
            sum += judge[i];
        }

        //printf("###%d\n",x);

        x = sum;
        avg = 2.0*x/(double)n;
        share = n;
        x *= 2;

        //printf("***%llf %d\n",avg,x);

        for(int i = 0 ; i < n ; i++)
        {
            if(judge[i] > avg)
            {
                x -= judge[i];
                share--;
            }
        }

        //printf("@@@%d %d\n",x,share);


        for(int i = 0 ; i < n ; i++)
        {
            if(judge[i] > avg) ans[i] = 0.0;
            else
            {
                ans[i] = ((double)x/share - judge[i])/(double)sum;
                //printf("*%llf %llf %d\n",ans[i],(double)x/share,judge[i]);
                ans[i] *= 100;
            }
        }

        printf("Case #%d: ",_c);
        for(int i = 0 ; i < n ; i++) printf("%llf ",ans[i]);
        printf("\n");
    }
    return 0;
}
