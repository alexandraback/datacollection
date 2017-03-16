#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

const int N = 110000;

double p[N];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int a,b,nc;
    cin>>nc;
    for(int cc=1;cc<=nc;++cc) {
        cin>>a>>b;
        for(int i=1;i<=a;++i) cin>>p[i];
        double ans = b+2, pcorrect = 1.0;
        for(int i=0;i<=a;++i)
        {
            double t = a-i + pcorrect*(b-i+1) + (1.0-pcorrect)*(b-i+1+b+1);
            if(t<ans) ans = t;
            pcorrect *= p[i+1];
        }
        printf("Case #%d: %.8lf\n",cc,ans);
    }
    return 0;
}
