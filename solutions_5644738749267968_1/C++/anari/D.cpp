#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <set>
#include <algorithm>
#include <list>
using namespace std;
struct wood{
  double x;
  int person;
};
bool operator<(const wood& a,const wood& b){
  return a.x<b.x;
}
vector<wood> p;
int ans(int q){
  int bal=0;
  int score=0;
  for (int i=p.size()-1;i>=0;--i){
    if (p[i].person==q)
      bal += 1;
    else{
      if (bal>0){
        --bal;
        ++score;
      }
    }
  }
  return score;
}
int main(){
  int tnum;cin>>tnum;int tcou=0;
  while (tnum--){
    cout<<"Case #"<<++tcou<<": ";
    p.clear();
    int n;
    cin>>n;
    {
      for (int i=0;i<2;++i)
        for (int j=0;j<n;++j){
          wood w;cin>>w.x;
          w.person = i;
          p.push_back(w);
        }
    }
    sort(p.begin(), p.end());
    cout<<ans(0)<<' '<<n-ans(1)<<endl;
  }
  return 0;
}
