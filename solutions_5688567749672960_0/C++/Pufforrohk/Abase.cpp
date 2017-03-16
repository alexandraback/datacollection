#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int N;
map<int,int> m;

int rev(int el){
  string s= "" + to_string(el);
  reverse(s.begin(),s.end());
  return atoi(s.c_str());
}

int solve(){
  m.clear();
  cin>>N;
  if(N==1)
    return 1;
  queue<int> q;
  q.push(1);
  m[1]=1;
  while(true){
    int el = q.front();
    q.pop();
    int n1=el+1;
    int n2=rev(el);
    //  cout<<el<<" "<<n1<<" "<<n2<<endl;
    if(n1==N || n2==N)
      return m[el]+1;
    if(m.find(n1)==m.end()){
      m[n1]=m[el]+1;
      q.push(n1);
    }
    if(m.find(n2)==m.end()){
      m[n2]=m[el]+1;
      q.push(n2);
    }
  }
}

int main(){
  int cases;
  cin>>cases;
  for(int i=0;i<cases;i++){
    cout<<"Case #"<<i+1<<": "<<solve()<<endl;
  }
  return 0;
}
