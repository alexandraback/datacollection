#include <iostream>
#include <cstdio>
#define fo(i,a,b) for(long long i=a;i<=b;i++)
using namespace std;
int a[100],len,t;
long long st[20000],en[20000];
int ans[20000];
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
        cin>>st[ii]>>en[ii];
    }
    fo(i,1,10000000){
         if (ch(i) && ch(i*i)) {
            fo(j,1,t) if ((st[j]<=i*i)&&(i*i<=en[j])){
                ans[j]++;
            }
         }
    }
    for(int i=1;i<=t;i++) 
        printf("Case #%d: %d\n",i,ans[i]);
  //  fo(i,11,10000000){
    //    if (ch(i) && ch(i*i)) printf("%lld %lld\n",i,i*i);
   // }
}
