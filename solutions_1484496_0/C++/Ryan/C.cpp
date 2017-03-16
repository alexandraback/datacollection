#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve(const vector<int>& v);

int main(){
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    cout<<"Case #"<<i+1<<":\n";
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<v.size();i++)
      cin>>v[i];
    solve(v);
  }
}

void print(const vector<int>& v,int n);
int sum(const vector<int>& v,int n);

void solve(const vector<int>& v){
  map<int,int> m;
  for(int i=1;i<(1<<v.size());i++){
    int s=sum(v,i),other=m[s];
    if(other){
      print(v,other);
      print(v,i);
      return;
    }
    m[s]=i;
  }
  cout<<"Impossible\n";
}

void print(const vector<int>& v,int n){
  for(int i=0;i<v.size();i++)
    if(n&(1<<i))
      cout<<v[i]<<' ';
  cout<<'\n';
}

int sum(const vector<int>& v,int n){
  int ret=0;
  for(int i=0;i<v.size();i++)
    if(n&(1<<i))
      ret+=v[i];
  return ret;
}

