#include <cstdio>
#include <string>
#include <iostream>
#include <set>
#include <cmath>
#include <cstdlib>
#include <map>
#include <algorithm>
using namespace std;

#define FILEIO
 string _input="A-small-attempt1.in";
// string _input="A-large.in";


int main()
{
#ifdef FILEIO
    freopen(_input.c_str(),"r",stdin);
    freopen((_input+".out.txt").c_str(), "w", stdout);
#endif

    int T; scanf("%d",&T);
    for(int IT=0;IT<T;IT++)
    {
        int n; scanf("%d", &n);
        int J[300];
        for(int i=0;i<n;i++)scanf("%d",&J[i]);
        double tJ=0;for(int i=0;i<n;i++)tJ+=J[i];

        double P[300];
        for(int i=0;i<n;i++)
        {
            double a=0,b=1.0;
            while(fabs(a-b)>1e-10)
            {
                double c=(a+b)*0.5;
                double tP=J[i]+tJ*c;
                double need=0;
                for(int j=0;j<n;j++)
                {
                    if(J[j]*1.0>=tP) continue;
                    need+=(tP-J[j])/tJ;
                }
                if(need<1.0)a=c;
                else b=c;
            }
            P[i]=(a+b)/2;
        }

        printf("Case #%d:", IT+1);
        for(int i=0;i<n;i++)printf(" %lf",P[i]*100);
        printf("\n");

    }
    return 0;
}
