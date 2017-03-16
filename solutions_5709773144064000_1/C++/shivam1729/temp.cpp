#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define sll(x) scanf("%I64d",&x)
#define pll(x) printf("%I64d\n",x)
#define sc(x) scanf("%c",&x)
#define pc(x) printf("%c",x)
#define sf(x) scanf("%f",&x)
#define pf(x) printf("%f",x)
#define sd(x) scanf("%lf",&x)
#define pd(x) printf("%lf",x)
#define sld(x) scanf("%Lf",&x)
#define pld(x) printf("%Lf",x)
#define clr(a) memset(a,0,sizeof(a))
#define MOD 1000000009
using namespace std;
int main(void){
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int xx=0;
    while(t--){
        xx++;
        double c,f,x;
        cin>>c>>f>>x;
        double ans=x/2.0;
        double cur=2.0;
        double total=0;
        double prev=ans+1;
        while(1){
            double hm=c/cur;
            cur+=f;
            total+=hm;
            ans=min(ans,total+x/cur);
            if(ans>=prev)
                break;
            else{
                prev=ans;
            }
        }
        printf("Case #%d: %.7lf\n",xx,ans);
        //cout<<ans<<endl;
    }
    return 0;
}
