#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
const int mx=1234;
string a[mx],b[mx];
int main(){
   freopen("x.in","r",stdin);
   freopen("x.out","w",stdout);

   int t,n;
   scanf("%d",&t);
   for(int tt=1;tt<=t;tt++){
      scanf("%d",&n);      
      for(int i=0;i<n;i++){
         cin>>a[i]>>b[i];
      }
      int ans=n;
      for(int c=0;c<(1<<n);c++){
         set<string>lft,rht;
         bool ok=true;
         for(int i=0;i<n;i++)if(c&(1<<i)){
            if(lft.count(a[i])==1)ok=false;
            if(rht.count(b[i])==1)ok=false;

            lft.insert(a[i]); 
            rht.insert(b[i]);
         }
         for(int i=0;i<n;i++){
            if(c&(1<<i))continue;
            if(lft.count(a[i])!=0 && rht.count(b[i])!=0){
            }
            else ok=false;
         }
         if(ok){
            int bet=__builtin_popcount(c);
            ans=min(ans,bet);
         }
      }
      printf("Case #%d: %d\n",tt,n-ans);
   }
   return 0;
}
