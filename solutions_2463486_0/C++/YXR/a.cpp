#include <iostream>
#include <cstdio>
#define fo(i,a,b) for(long long i=a;i<=b;i++)
using namespace std;
int a[100],len,t,st,en,ans;
bool ch(long long x)
{
    len=0;
    for(len=1;x>0;len++){
        a[len]=x % 10;
        x=x / 10;
    }
    len--;
    fo(i,1,len){
        if (a[i]!=a[len-i+1]) return 0;
    }
    return 1;
}
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d\n",&t);
    fo(ii,1,t){
        printf("Case #%d: ",ii);
        cin>>st>>en;
        ans=0;
        fo(i,1,en){
            if (ch(i) && ch(i*i) && (st<=i*i) && (en>=i*i)) ans++;
        }
        printf("%d\n",ans);
    }
  //  fo(i,11,10000000){
    //    if (ch(i) && ch(i*i)) printf("%lld %lld\n",i,i*i);
   // }
}
