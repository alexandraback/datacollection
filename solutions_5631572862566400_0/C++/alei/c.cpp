#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
const int mx=15;
int f[mx];
int p[mx];
int main(){

   freopen("c.in","r",stdin);
   freopen("c.out","w",stdout);

   int t;
   scanf("%d",&t);
   for(int tt=1;tt<=t;tt++){
      cerr<<"tt="<<tt<<endl;
      int n;
      scanf("%d",&n);
      for(int i=0;i<n;i++){
         scanf("%d",f+i);
         f[i]--;
         p[i]=i;
      }
      int ans=1;
      do{
         int s=0;
         int bet=0;
         for(int i=1;i<n;i++){
            if(f[p[i-1]]==p[i])s++;
            if(f[p[i]]==p[i-1])s++;
            int ns=s;
            if(i!=1){
               if(f[p[i]]==p[0])ns++;
               if(f[p[0]]==p[i])ns++;
            }
            if(ns>=i+1){
               bet=i+1;
            }
         }
         ans=max(ans,bet);
      }while(next_permutation(p,p+n));
      printf("Case #%d: %d\n",tt,ans);
   }
   return 0;
}
