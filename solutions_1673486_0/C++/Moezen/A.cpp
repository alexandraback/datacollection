#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 100000 + 10;
const int INF = 1<<30;
const double eps = 1e-9;

double p[200000];
double ex[200000];
double mist[200000];
double crt[200000];

int main()
{
 //   freopen("A-small-attempt0.in","r",stdin);
  //  freopen("Aout.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int A,B;
        scanf("%d%d",&A,&B);
        for(int i=1;i<=A;i++)
            scanf("%lf",&p[i]);
        crt[0]=1;
        for(int i=1;i<=A;i++)
            crt[i]=crt[i-1]*p[i];
        ex[0]=crt[A]*(B-A+1)+(1.0-crt[A])*(2*B-A+2);
        ex[1+A]=2+B;
        double maxs=ex[0];
        if((ex[1+A]-maxs)<-eps) maxs=ex[1+A];
        for(int i=1;i<=A;i++)
        {
            ex[i]=crt[A-i]*(2*i+B-A+1)+(1-crt[A-i])*(2*i+2*B-A+2);
            if((ex[i]-maxs)<-eps) maxs=ex[i];
        }

 /*       for(int i=A;i>0;i--)
            printf("%f\n",crt[i]);
        printf("\n");*/
 //       for(int i=0;i<=A+1;i++)
  //          printf("%f\n",ex[i]);
        printf("Case #%d: %f\n",cas,maxs);
    }
	return 0;
}
