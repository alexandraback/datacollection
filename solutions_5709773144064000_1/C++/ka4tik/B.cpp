/*
 *Kartik Singal @ ka4tik
 */
#include<bits/stdc++.h>
using namespace std;
#define s(n) scanf("%d",&n)
int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int test;s(test);
    int kase=0;
    while(test--)
    {
        kase++;
        double c,f,x;
        cin>>c>>f>>x;
        double ans=(x/2.0);
        double production=2;
        double t=c/production;
        while(t<ans)
        {
            production+=f;
            double req=t+x/production;
            ans=min(ans,req);
            t+=c/production;
        }
        printf("Case #%d: %0.7lf\n",kase,ans);
    }
    return 0;
}

