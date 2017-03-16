#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define N 21
#define eps 1e-10
using namespace std;
double c,f,x;
int t;


int dcmp(double x)
{
    return x<-eps ? -1 : x>eps;
}
int ca=1;
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        double nowt=0,nowf=2;
        cin>>c>>f>>x;
        printf("Case #%d: ",ca++);
        while(1)
        {
            double t1,t2;
            t1=x/nowf;
            t2=c/nowf+x/(nowf+f);
            if(dcmp(t1-t2)<=0)
            {
                nowt+=t1;
                break;
            }
            else
            {
                nowt+=c/nowf;
                nowf+=f;
            }
        }
        printf("%.7lf\n",nowt);
    }
    return 0;
}

