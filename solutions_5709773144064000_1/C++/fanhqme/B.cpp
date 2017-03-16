#include <cstdio>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    for (int Case=1;Case<=T;Case++){
        printf("Case #%d: ",Case);
        double C,F,X;
        scanf("%lf%lf%lf",&C,&F,&X);
        double s=0;
        int n=0;
        while (X/(2+n*F) - X/(2+(n+1)*F) > C/(2+n*F)){
			s+=C/(2+n*F);
			n+=1;
        }
        s+=X/(2+n*F);
        printf("%.9f\n",s);
    }
    return 0;
}
