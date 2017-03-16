#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <stack>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define maxn 110000
#define E exp(double(1))
#define eps 1e-9
using namespace std;

#ifdef __int64
    typedef __int64 LL;
#else
    typedef long long LL;
#endif

double c,f,x;

int main() {
    int i,j,k,m;
    int _,n,cas=1;
    double now;
    freopen("out.txt","w",stdout);
    freopen("B-small-attempt2.in","r",stdin);
    cin>>_;
    while(_--) {
        scanf("%lf%lf%lf",&c,&f,&x);

        double n = 2.0,ans=x/2.0,tmp,ll=0;
        while(1){
            ll+=c/n;
            n+=f;
            tmp = ll+x/n;
            if(tmp<ans){
                ans=tmp;
            }else{
                break;
            }
        }

        printf("Case #%d: %.7f\n",cas++,ans);
    }
    return 0;
}
