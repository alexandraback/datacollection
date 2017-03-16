#include <cstdio>
#include <algorithm>
using namespace std;
long long hw[102000];
int ct=0;
int ck(long long x)
{
    int bit[20],p=0;
    while(x){
        bit[p++]=x%10;
        x/=10;
    }
    for(int i=0;i<p;i++) {
        if(bit[i]!=bit[p-1-i]) return 0;
    }
    return 1;
}
long long cal(long long x)
{
    if(x==0) return 0;
    int l=0,h=ct-1;
    while(l<h){
        int mid=(l+h+1)/2;
        if(hw[mid]<=x) l=mid;
        else h=mid-1;
    }
    return l+1;
}
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    for(int i=1;i<10;i++) hw[ct++]=i;
    for(int i=1;i<10000;i++){
        int p=i;
        int bit[10],c=0;
        while(p){
            bit[c++]=p%10;
            p/=10;
        }
        for(int j=0;j<10;j++) {
            hw[ct]=i*10+j;
            for(int k=0;k<c;k++) hw[ct]=hw[ct]*10+bit[k];
            ct++;
        }
        hw[ct]=i;
        for(int j=0;j<c;j++) {
            hw[ct]=hw[ct]*10+bit[j];
        }
        ct++;
    }
    sort(hw,hw+ct);
    int s=ct;
    ct=0;
    for(int i=0;i<s;i++){
        hw[i]=hw[i]*hw[i];
        if(ck(hw[i])) hw[ct++]=hw[i];
    }
//    for(int i=0;i<10;i++) printf("%d\n",hw[i]);
    long long A,B;
    int T,ca=0;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&A,&B);
        printf("Case #%d: %lld\n",++ca,cal(B)-cal(A-1));
    }
}
