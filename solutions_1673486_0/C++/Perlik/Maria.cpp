#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N=100010;
double p[N];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("hello.txt","w",stdout);
    int t;
    cin>>t;
    for(int q=1;q<=t;q++)
    {
        int a,b;
        cin>>a>>b;
        double ans=1e18,v=1;
        for(int i=0;i<a;i++)
        {
            cin>>p[i];
            ans=min(ans,v*(a-i+b-i+1)+(1-v)*(a-i+b-i+1+b+1));
            v*=p[i];
        }
        printf("Case #%d: %.6lf\n",q,min(ans,min(b+2.0,v*(b-a+1)+(1-v)*(b-a+1+b+1))));
    }
    return 0;
}
