#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
using namespace std;

pair<int,int> star[1000];

int main(){
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  ios::sync_with_stdio(false);

  int tests; cin>>tests; for (int test=1; test<=tests; test++){
    int n; cin>>n;

    int best=1024;
    map<int,multiset<int>> to;
    for (int i=n; i--;) cin>>star[i].first>>star[i].second;
    for (int i=1<<n; i--;){
      vector<pair<int,int>> want; for (int j=n,k=i; j--; k>>=1) if (k&1) want.push_back(make_pair(star[j].second,2)); else want.push_back(make_pair(star[j].first,1)), want.push_back(make_pair(star[j].second,1));
      sort(want.begin(),want.end());
      int have=0;
      int cost=0;
      bool ok=true;
      for (auto it: want) if (have<it.first) ok=false; else have+=it.second, ++cost;
      if (ok) best=min(best,cost);
    }
    cout<<"Case #"<<test<<": ";
    if (best==1024) cout<<"Too Bad"<<endl; else cout<<best<<endl;
  }
}
