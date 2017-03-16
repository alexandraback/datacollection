#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<set>
typedef long long int uli;
using namespace std;

int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int t;
    double c,f,x;
    cin>>t;    
    for(int tc=1;tc<=t;tc++){
        scanf("%lf %lf %lf",&c,&f,&x);
        double ans = x/2.0;
        double chain = 0;
        for(double i=1;;i++){
            chain = chain + c/(2.0+(i-1)*f);
            double time = x/(2+i*f) + chain;
            if(time<=ans) ans = time;
            else break;

        }
        printf("Case #%d: %.7lf\n",tc,ans);
    }
    return 0;
}
