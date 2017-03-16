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
  int R,C,M;
  cin>>R>>C>>M;
  if(R==1) {
    REP(i,C) {
      if(i<M)cout<<'*';else if(i==C-1) cout<<'c';else cout<<'.';
    }
    cout<<endl;
    return;

  }
  if(C==1) {
    REP(i,R) {
      if(i<M)cout<<'*';else if(i==R-1) cout<<'c';else cout<<'.';
      cout<<endl;
    }
    return;
  }
  vector<string> v(R,string(C,'*'));
  int to_place=R*C-M;
  if(to_place>1)REP(i,R) {
    int k=1;
    if(i==0) k=2;
    int use_columns= min(C,to_place/k);
    int rest=to_place-use_columns*k;
    if(rest==1) {use_columns--;rest+=k;}
    if(use_columns<2) break;

    for(int a=0;a<use_columns;++a) for(int b=0;b<k;++b) v[i+b][a]='.';

    to_place=rest;
    if(rest>use_columns && use_columns!=C) break;
    if(to_place==0) break;
    if(i==0) ++i;
  } else to_place=0;
  v[0][0]='c';


  if(to_place==0) REP(i,R) {
    cout<<v[i]<<endl;
  } else cout<<"Impossible"<<endl;
}
int main() {
int T;cin>>T;
REP(i,T) {
  cout<<"Case #"<<(i+1)<<": ";
  cout<<endl;
  solve();
}
}
