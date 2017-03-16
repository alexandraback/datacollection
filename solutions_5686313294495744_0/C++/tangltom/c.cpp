#include <bits/stdc++.h>
using namespace std;

typedef pair<string,string> pss;

int bit_cnt(int x){
  return __builtin_popcount(x);
}

int check(vector<pss> &v, int fake){
  set<string> f, s;
  for(int i=0;i<v.size();i++){
    if(!(fake&(1<<i))){
      f.insert(v[i].first);
      s.insert(v[i].second);
    }
  }
  for(int i=0;i<v.size();i++){
    if(fake&(1<<i) ){
      if(f.count(v[i].first)==0 || s.count(v[i].second)==0)
	return 0;
    }
  }
  return 1;
}

int main(){
  int T;
  cin>>T;
  for(int t=1;t<=T;t++){
    int N;
    cin>>N;
    vector<pss> v(N);
    for(int i=0;i<N;i++)
      cin>>v[i].first>>v[i].second;
    int res = 0;
    for(int fake=0;fake<(1<<N);fake++){
      if(check(v, fake))
	res = max(res, bit_cnt(fake));
    }
    cout<<"Case #"<<t<<": "<<res<<endl;
  }
  return 0;
}
