#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int a,b;
double p[10005];
double a1,a2,a3;
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int cas=1;
    int t;
    cin>>t;
    while(t--)
    {
        double total = 1;
        cin>>a>>b;
        for(int i=0;i<a;i++)
        {
            cin>>p[i];
            total*=p[i];
        }
        //cout<<total<<endl;
        a3=1+b+1;
        int ret = b-a+1;
        //cout<<ret<<endl;
        a1=ret*total+(ret+b+1)*(1-total);
        double right=1;
        double wrong =1;
        a2=0;
        double ans = min(a1,a3);
        for(int i=0;i<a;i++)
        {
            a2=right*((a-i)+(b-i)+1)+(1-right)*(b+1+(a-i)+(b-i)+1);
            //<<i<<" "<<a2<<endl;
            ans = min(ans,a2);
            right*=p[i];
        }
        printf("Case #%d: %.6lf\n",cas++,ans);
    }
    return 0;
}
