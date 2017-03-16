#include <stdio.h>


int main(int argc, char* argv[])
{
    int T;
    scanf("%d",&T);
    for (int t=1;t<=T;t++)
    {
        int A,B;
        scanf("%d %d",&A,&B);
        double p;
        double ptotal=1.0f;
        //hit enter and type the password
        double mejor=2.0+double(B);
        for (int i=1;i<=A;i++)
        {
            scanf("%lf",&p);
            ptotal*=p;
            //get back to have i characters
            double actual=double(A-i);
            //type the missing chars and enter
            actual+=double(1+B-i);
            //not entering it right
            actual+=(1.0-ptotal)*double(B+1);
            if (actual<mejor)
                mejor=actual;
        }
        printf("Case #%d: %lf\n",t,mejor);
    }
    return 0;
}
//---------------------------------------------------------------------------
 