#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
ll getpow(ll x,ll y){
    ll res=1;
    while(y--)
        res*=x;
    return res;
}
int main()
{
    freopen("dd.in","r",stdin);
    freopen("out.txt","w+",stdout);
    int ncase,T=0;
    scanf("%d",&ncase);
    while(ncase--){
        printf("Case #%d: ",++T);
        ll k,c,s;
        cin>>k>>c>>s;
        ll now=1,step=getpow(k,c-1);
        for(int i=1;i<=s;i++){
            cout<<now<<" ";
            now+=step;
        }
        cout<<endl;
    }
    return 0;
}
