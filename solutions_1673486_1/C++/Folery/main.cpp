#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
typedef long long LL;
using namespace std;
const double PI=acos(-1.0);
double p[100010];
double min(double a,double b)
{
    return a<b?a:b;
}
int main()
{
    FILE *fpr,*fpw;
    fpr=fopen("A-large.in","rb");
    fpw=fopen("out.txt","wb");
    int A,B;
    int T,Case;
    int i,j;

    fscanf(fpr,"%d",&T);
    for(Case=1;Case<=T;Case++)
    {
        fscanf(fpr,"%d%d",&A,&B);
        double ans=0;
        for(i=0;i<A;i++)    fscanf(fpr,"%lf",&p[i]);
        ans=B+2;
        double correct=1.0;
        for(i=0;i<A;i++)
            correct*=p[i];
        ans=min((B-A+1)*correct+(2*B-A+2)*(1-correct),B+2.0);
        for(i=1;i<=A;i++)
        {
            double tempans;
            double coooo=1.0;
            for(j=0;j<A-i;j++)
                coooo*=p[j];
            tempans=(B-A+1+2*i)*coooo+(2*B-A+2+2*i)*(1-coooo);
            ans=min(ans,tempans);
        }
        fprintf(fpw,"Case #%d: %.9lf\n",Case,ans);
        printf("Case #%d: %.9lf\n",Case,ans);
    }
    fclose(fpr);
    fclose(fpw);
    return 0;
}
