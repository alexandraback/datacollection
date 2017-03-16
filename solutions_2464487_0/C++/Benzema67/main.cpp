#include <cstdio>
#include <iostream>
typedef long long ll;
using namespace std;

int main(){
    int t,T;
    ll r,tt,ll,rr,mid,ans,tem;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a.txt","w",stdout);
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        cin >> r >> tt;
        ll=0,rr=2e9;
        //cout << "***" << rr <<endl;
        while(ll<=rr){
            mid=(ll+rr)>>1;
            tem=2*mid*mid+(2*r-1)*mid;
            if(tem <= tt){
                ans=mid;
                ll=mid+1;
            }
            else rr=mid-1;
        }
        printf("Case #%d: ",t);
        cout << ans << endl;
    }
    return 0;
}
