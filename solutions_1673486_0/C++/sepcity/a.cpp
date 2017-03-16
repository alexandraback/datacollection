#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>

using namespace std;
double p[101010];
double j[101010];
int main()
{
    int cases;
    scanf("%d",&cases);
    for(int ca=1;ca<=cases;ca++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        j[0]=1;
        for(int i=1;i<=a;i++)
        {
            scanf("%lf",&p[i]);
            j[i]=j[i-1]*p[i];
        }
        double res=b+2;
        for(int i=0;i<=a;i++)
        {
            double x=j[a-i]*(2*i+b-a+1)+(b+1+2*i+b-a+1)*(1-j[a-i]);
            res=min(res,x);
        }
        printf("Case #%d: %.6lf\n",ca,res);
    }

}
