//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;
double X[150000],F[150000];
int main()
{
    int i,j,k,l,t,r;
    double n,m,x,M,a,b;
    freopen("B-large.in","r",stdin);
    freopen("Output.txt","w",stdout);
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%lf%lf%lf",&n,&m,&x);
        l=(int)x;
        a=2.0000000;
        F[0]=0.000000;
        M=2000000000000000000.0000000;
        for(i=1;i<=l;i++)
        {
            F[i]=F[i-1]+(n/a);
            X[i]=F[i-1]+(x/a);
            a=a+m;
            if(M>X[i])
                M=X[i];
            else
                break;
        }
       printf("Case #%d: %.7lf\n",r,M);

    }
    fclose(stdout);
    fclose(stdin);
        return 0;
}

