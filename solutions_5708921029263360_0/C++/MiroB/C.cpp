#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
typedef long long int ll;
int  cnt1[10000];
int  cnt2[10000];
int  cnt3[10000];
void solve() {
  int J,P,S,K;
  cin>>J>>P>>S>>K;
  vector<string> D;
  vector<int> p1,p2,p3;
  REP(i,J) REP(j,P) REP(k,S) {    
    p1.push_back(i+J*j);
    p2.push_back(i+J*k);
    p3.push_back(j+P*k);
  }
  int n=p1.size();
  REP(i,10000) cnt1[i]=cnt2[i]=cnt3[i]=0;
  int  best=0;
  int best_v=0;
  REP(i,1<<n) {
    int ok=1;
    int sum=0;
    REP(j,n) if(i&(1<<j)){
      ++sum;
      cnt1[p1[j]]++;
      cnt2[p2[j]]++;
      cnt3[p3[j]]++;
      if(cnt1[p1[j]]>K || cnt2[p2[j]]>K|| cnt3[p3[j]]>K) {
        ok=0;
      }

    }
    REP(j,n) if(i&(1<<j)){
      cnt1[p1[j]]=0;
      cnt2[p2[j]]=0;
      cnt3[p3[j]]=0;
    }

    if(ok && sum>best_v) {
      best=i;
      best_v=sum;

    }

  }
  cout<<best_v<<endl;
  REP(i,n) {
    if(best&(1<<i)) {
      int f1=p1[i]%J+1;
      int f2=p1[i]/J+1;
      int f3=p2[i]/J+1;
      cout<<f1 << " "<<f2<< " "<<f3 <<" "<<endl;
    }
  }

}
int main() {
  int t;cin>>t;REP(i,t) {
    cout<<"Case #"<<(i+1)<<": ";
    solve();
  }

}
