#include <iostream>
#include <cstdio>
#include <algorithm>
#define fo(i,a,b) for(long long i=a;i<=b;i++)
using namespace std;
int t,x,n,ans,now,tn;
int a[1000];
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d\n",&t);
    fo(tt,1,t) {
       printf("Case #%d: ",tt);
       scanf("%d %d",&x,&n);
       fo(i,1,n) scanf("%d",&a[i]);
       sort(a+1,a+n+1);
      // fo(i,1,n) printf("%d ",a[i]);
       //printf("\n%d\n",x);
       ans=n;
       now=1;
       tn=0;
       while (now<=n){
            if (x>a[now]) {
               x=a[now]+x;
               now++;
             }
            else {
                if (tn+n-now+1<ans) ans=tn+n-now+1;
                if (x==1) break;
                x=x+x-1;
                tn++;
            }
       }
       if ((now>n)&&(tn<ans)) ans=tn;
       printf("%d\n",ans);
    }
}
