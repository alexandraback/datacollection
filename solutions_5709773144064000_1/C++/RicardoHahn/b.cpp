#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int ccnt=1; ccnt<=t; ++ccnt)
    {
        double c,f,x;
        scanf("%lf %lf %lf",&c,&f,&x);

        double base_time=0;
        double coef=2;
        double prev_ans;
        double ans=x/coef;
        do
        {
            prev_ans = ans;
            base_time += c/coef;
            coef += f;
            ans = base_time+x/coef;
        } while(prev_ans>ans);

        printf("Case #%d: %.7f\n",ccnt,prev_ans);
    }
    return 0;
}
