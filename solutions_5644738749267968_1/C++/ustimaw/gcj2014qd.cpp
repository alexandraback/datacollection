#include<iostream>
#include<set>
#include<deque>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int dwar(vector<double> n,vector<double> k){
  sort(begin(n),end(n));
  sort(begin(k),end(k));
  int m=0;
  for(int i=0;i<n.size();i++){
    int c=0;
    for(int j=0;j+i<n.size();j++){
      c+=n[i+j]>k[j];
    }
    m=max(m,c);
  }
  return m;
}

int war(set<double> n,set<double> k){
  int c=0;
  while(!n.empty()){
    auto ni=n.begin();
    auto ki=k.upper_bound(*ni);
    if(ki==k.end()){
      c++;
      ki=k.begin();
    }
    n.erase(ni);
    k.erase(ki);
  }
  return c;
}

int main(){
  int T;
  cin>>T;
  for(int i=1;i<=T;i++){
    int N;
    cin>>N;
    vector<double> naomi(N),ken(N);
    for(int j=0;j<N;j++){
      cin>>naomi[j];
    }
    for(int j=0;j<N;j++){
      cin>>ken[j];
    }
    cout<<"Case #"<<i<<": "<<dwar(naomi,ken)<<" "<<war(set<double>(begin(naomi),end(naomi)),set<double>(begin(ken),end(ken)))<<endl;
  }
  return 0;
}
