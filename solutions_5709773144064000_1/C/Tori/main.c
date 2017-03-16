#include <stdio.h>

int main()
{
    int testCases,t;
    double farmCost,farmBoost,target,cps;
    double currentTime,time2Target,time2Farm,time2TargetAfterBuy;

    scanf("%d",&testCases);

    for(t=1;t<=testCases;t++)
    {
        scanf("%lf %lf %lf",&farmCost,&farmBoost,&target);

        currentTime = 0.0;
        cps = 2.0;
        while(1)
        {
            time2Target = target/cps;
            time2Farm = farmCost/cps;
            if(time2Target<time2Farm)
            {
                currentTime+=time2Target;
                break;
            }
            else
            {
                time2TargetAfterBuy = (target/(cps+farmBoost))+time2Farm;

                if(time2TargetAfterBuy<time2Target)
                {
                    cps+=farmBoost;
                    currentTime+=time2Farm;
                    continue;
                }
                else
                {
                    currentTime+=time2Target;
                    break;
                }
            }
        }

        printf("Case #%d: %.7f",t,currentTime);
        if(t!=testCases)printf("\n");
    }

    return 0;
}
