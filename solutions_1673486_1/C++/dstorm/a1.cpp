// Problem A. LArge
#include <stdio.h>
#include <iostream>
using namespace std;
int main (){
    int t,A,B,i,j;
    double p[100001],pro,exp,min;
    scanf("%d",&t);
i=1;
    while(i<=t){
        scanf("%d %d",&A,&B);
        for (j=0;j<A;j++)
	{
            scanf("%lf",&p[j]);
        }
        min=(B+2)*1.0;
        pro=1;
        for (j=0;j<A;j++)
        {
            pro*=p[j];
            exp=pro*(A+B-2*j-1)+(1-pro)*(A+2*B-2*j);
            if (exp<min){
                              min=exp;
            }
        }
        printf("Case #%d: %.6lf\n",i,min);
	i++;
    }
    return 0;
}