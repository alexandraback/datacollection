#include <vector>
#include <string>
#include <iostream>
using namespace std;

int freq[2501];
int DEBUG=0;

vector<int> doit(vector<vector<int> > g, int n) {
  sort(g.begin(),g.end());
  if(DEBUG) {
  for(int i=0;i<g.size();i++) {
    for(int j=0;j<g[i].size();j++) {
      cout<<g[i][j]<<" ";
    }
    cout<<endl;
  }
  }
  memset(freq,0,sizeof(freq));
  vector<int> v;
  for(int i=0;i<g.size();i++) {
    for(int j=0;j<g[i].size();j++) {
      freq[g[i][j]]++;
    }
  }
  vector<int> ret;
  for(int i=1;i<=2500;i++) {
//    cout<<i<<" "<<freq[i]<<endl;
    if(freq[i]%2==1) ret.push_back(i);
  }
  return ret;
}

int main() {
  int tests;
  cin>>tests;
  for(int i=0;i<tests;i++) {
    int n;
    cin>>n;
    vector<vector<int> > g;
    for(int j=0;j<2*n-1;j++) {
      vector<int> l;
      for(int k=0;k<n;k++) {
        int val;
        cin>>val;
        l.push_back(val);
      }
      g.push_back(l);
    }
    DEBUG=0;
    vector<int> ret=doit(g,n);
    cout<<"Case #"<<(i+1)<<":";
    for(int j=0;j<n;j++) cout<<" "<<ret[j];
    cout<<endl;
  }
  return 0;
}
