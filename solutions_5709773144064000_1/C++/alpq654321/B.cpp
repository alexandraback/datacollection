#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
double ans,NOW,C,F,X,now;
int T,i;
int main()
{
    scanf("%d",&T);
    while (T--)
    {
        cin>>C>>F>>X;
        ans=X/2.0;
        now=0; NOW=0;
        while (1)
        {
            now+=C/(2+NOW);
            NOW+=F;
            if (now+X/(NOW+2)>ans) break; else
              ans=now+X/(2+NOW);
        }
        i++;
        printf("Case #%d: %.7f\n",i,ans);
    }
    return 0;
}
