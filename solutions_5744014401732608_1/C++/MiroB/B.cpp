#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
typedef long long int ll;
void solve() {
   ll B,M;
   cin>>B>>M;
   
   vector<int> v;
   ll x=M;
   int sum=0;
   while(x) {
     v.push_back(x%2ll);
     sum+=x%2ll;
     x/=2;
   }
   int moc=v.size()-1;
   int n=v.size();
   
   if (moc+2>B || (sum>1 && moc+2==B)) {
     cout<<"IMPOSSIBLE"<<endl;
     return;
   }
   vector<vector<int> > A (B,vector<int>(B));
   if(sum!=1 || moc+2<B) {
     REP(i,n) if(v[i]){
       A[0][B-i-2]=1;
       //cout<<i<<endl;
     }
     for(int i=1;i<B;++i) {
       for(int j=i+1;j<B;++j) A[i][j]=1;
     }
   } else {
     for(int i=0;i<B;++i) {
       for(int j=i+1;j<B;++j) A[i][j]=1;
     }

   }
   cout<<"POSSIBLE"<<endl;
   REP(i,B) {
     REP(j,B) cout<<A[i][j];     
     cout<<endl;
   }
}
int main() {
  int t;cin>>t;REP(i,t) {
    cout<<"Case #"<<(i+1)<<": ";
    solve();
  }

}
