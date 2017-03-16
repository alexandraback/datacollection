#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<map>
#include<string>

using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
void solve() {
  int n;
  cin>>n;
  vector<double> naomi(n),peter(n);
  REP(i,n) cin>>naomi[i];
  REP(i,n) cin>>peter[i];
  sort(naomi.begin(), naomi.end());
  sort(peter.begin(), peter.end());
  int dec_s=0;
  int np=0,pp=0;
  REP(i,n) {
    if(naomi[np]<peter[pp]) {
      np++;
    } else {
      dec_s++;
      np++;
      pp++;
    }
  }
  int war_s=0;
  REP(i,n) {
    int fn=-1;
    REP(j,n) {
      if(peter[j]>naomi[n-1-i]) {
        fn=j;break;
      }
    }
    if(fn==-1) {
      REP(j,n) if(peter[j]!=-1) {peter[j]=-1;break;}
      war_s++;
    } else {
      peter[fn]=-1;
    }

  }


  cout<<dec_s<<" "<<war_s;
}
int main() {
  int T;
  cin>>T;REP(i,T) {
    cout<<"Case #"<<(i+1)<<": ";
    solve();
    cout<<endl;
  }
}
