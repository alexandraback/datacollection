#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
typedef long long ll;
bool A[1<<20];
string vowels="aeiou";


int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
      freopen("output","w",stdout);
   #endif
   int T,N;
   cin>>T;
   REP(t,T){
       string cad; 
       cin>>cad>>N;
       int cnt=0;
       memset(A,0,sizeof A);
       for(int i=cad.size()-1;i>=0;i--){
          if(vowels.find(cad[i])==-1){
             cnt++;
             if(cnt>=N)A[i]=1;
          }
          else{
              cnt=0;         
          }  
       }
       vector<int> ubis;
       REP(i,cad.size())if(A[i]==1)ubis.push_back(i);
       ll ans=0;
       REP(i,cad.size()){
           int idx=lower_bound(ubis.begin(),ubis.end(),i)-ubis.begin();           
           if(idx<ubis.size()){
               int ii=ubis[idx];
               ans+=(cad.size()-ii-N+1);                
           } 
       }
       printf("Case #%d: %lld\n",t+1,ans);
   }
   return 0;      
}

