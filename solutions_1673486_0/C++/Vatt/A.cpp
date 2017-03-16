#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int t;
int a,b;
double c[100005],minn,now,com;
int main()
{
        freopen("Ain.txt","r",stdin);
        freopen("Aout.txt","w",stdout);
        scanf("%d",&t);
        int r;
        for(r=1;r<=t;r++) {
                scanf("%d",&a);
                scanf("%d",&b);
                minn=b+2;
                now=1.0;
                for(int i=0;i<a;i++)
                {
                        scanf("%lf",&c[i]);
                        now*=c[i];
                        com = now*(a-i-1+b-i)+(1-now)*((a-i-1+b-i)+b+1);
                        //printf("%lf\n",com);
                        if(com<minn)
                        {
                                minn=com;
                        }
                }
                printf("Case #%d: ",r);  
                printf("%lf\n",minn);
        }
        //system("pause");
}
