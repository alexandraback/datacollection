#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#define pi (2*acos(0))
#define ll long long int
#define pii pair<int,int>

using namespace std;

double ok[100005];

int main()
{
    int i,j,k,t,T,r,a,b;
    double ans,d;

    freopen("A-small-attempt0(1).in","r",stdin);
    freopen("a1.txt","w",stdout);

    ok[0]=1.0;

    scanf("%d",&T);

    for(t=1;t<=T;t++)
    {
        scanf("%d %d",&a,&b);

        for(i=1;i<=a;i++)
        {
            scanf("%lf",&d);

            ok[i]=ok[i-1]*d;
        }

        ans=2+b;

        for(i=1;i<=a;i++)
        {
            d=ok[i]*(a+b-2*i+1);
            d+=(1.0-ok[i])*(a+2*b-2*i+2);

            //cout<<"for "<<i<<" "<<d<<endl;

            ans=min(ans,d);
        }



        printf("Case #%d: %.8lf\n",t,ans);
    }

    return 0;
}

