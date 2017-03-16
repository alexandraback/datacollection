#include <iostream>
#include <algorithm>
using namespace std;

int solve(){
  int Smax=0;
  string line;
  cin>>Smax;
  cin>>line;
  vector<int> seq;
  for(char c:line){
    seq.push_back(c-'0');
  }
  int tot=seq[0];
  int added=0;
  for(int i=1;i<seq.size();i++){
    if(tot<i){
      int newguys = i - tot;
      tot = i;
      added+=newguys;
    }
    tot+=seq[i];
  }
  return added;
}

int main(){
  int cases;
  cin>>cases;
  for(int i=0;i<cases;i++){
    cout<<"Case #"<<i+1<<": "<<solve()<<endl;
  }
  return 0;
}
