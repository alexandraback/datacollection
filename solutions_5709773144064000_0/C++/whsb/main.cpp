#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

double Cost,AddI,Need;

double cal(int Build)
{
    double Inc = 2.0;
    double Tim=0;
    for(int i=0;i<Build;i++)
    {
        Tim+=Cost/Inc;
        Inc+=AddI;
    }
    return Tim+Need/Inc;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int casT;
    scanf("%d",&casT);
    for(int cas=1;cas<=casT;cas++)
    {
        int head=0,tail=100000;
        scanf("%lf%lf%lf",&Cost,&AddI,&Need);
        while(head+3<tail)
        {
            int ML = (head*2+tail)/3;
            int MR = (head+tail*2)/3;
            double VL = cal(ML);
            double VR = cal(MR);
            if(VL<VR) tail=MR;
            else head=ML;
        }
        double ans = cal(head);
        for(int i=head+1;i<=tail;i++) ans=min(ans,cal(i));
        printf("Case #%d: %.7f\n",cas,ans);

    }

    return 0;
}
