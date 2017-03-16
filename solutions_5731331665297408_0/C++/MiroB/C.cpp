#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<map>
#include<string>

using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
vector<vector<int > >h;
void solve() {
  int n,m;
  cin>>n>>m;
  h=vector<vector<int> >(n);
  vector<string> s(n);
  REP(i,n) cin>>s[i];
  REP(i,m) {
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    h[a].push_back(b);
    h[b].push_back(a);
  }
  vector<int> p;REP(i,n) p.push_back(i);
  string rval="x";
  do{
    vector<int> seen(n);
    string val=s[p[0]];
    int ok=1;
    vector<int> path(1,p[0]);
    for(int next=1;next<n;++next) {
      int has=0;
      while(1) {
        int current=path[path.size()-1];
        REP(i,h[current].size()) if(h[current][i]==p[next]) has=1;
        if(has) {
          val.append(s[p[next]]);
          path.push_back(p[next]);
          break;
        } else {
          if(path.size()==1) break;
          path.resize(path.size()-1);
        }
      }
      if(!has) ok=0;
    }
    if(ok) {
      if(rval=="x") rval=val;
      if(val.size()<rval.size()) rval=val;
      else if(val.size()==rval.size() && val<rval) rval=val;
    }

  } while(next_permutation(p.begin(), p.end()));
  cout<<rval;
}
int main() {
  int T;cin>>T;
  REP(i,T) {
    cout<<"Case #"<<(i+1)<<": ";
    solve();
    cout<<endl;
  }
}
