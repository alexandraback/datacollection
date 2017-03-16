#include<cstdio>
int a[50];
typedef long long ll;
bool f(ll x){
    int i,n;
    for(i=0;x!=0;i++){
        a[i]=x%10;
        x/=10;
    }
    n=i-1;
    for(i=0;i<=n;i++)
        if(a[i]!=a[n-i])
            break;
    if(i<=n)
        return 0;
    return 1;
}
int main(){
    ll i,j,k,n;
    for(i=1;i<=ll(1e7);i++)
        if(f(i)&&f(i*i))
            printf("%lld,\n",i*i);
    return 0;
}
