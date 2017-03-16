#include <cstdio>
#include <iostream>
typedef long long ll;
using namespace std;

int main(){
    int t,T;
    ll r,lll,rr,mid,ans;
    double tem,tt;
    freopen("A-large.in","r",stdin);
    freopen("a.txt","w",stdout);
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        cin >> r >> tt;
        lll=0,rr=2e10;
        while(lll<=rr){
            mid=(lll+rr)>>1;
            tem=(double)2*mid*mid+((double)2*r-1)*mid;
            if(tem <= tt){
                ans=mid;
                lll=mid+1;
            }
            else rr=mid-1;
        }
        printf("Case #%d: ",t);
        cout << ans <<endl;
    }
    return 0;
}
