#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct L2{
  int s;
  int l1;
};

bool comparator2(const L2& a, const L2& b){
  return a.s < b.s;
};

vector<int> v1;
vector<L2> v2;

int play(){
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end(), comparator2);
//  for (int i = 0; i < v1.size(); ++i)
//    cout<<v1[i]<<" ";
//  cout<<endl;
//  for (int i = 0; i < v2.size(); ++i)
//    cout<<v2[i].s<<" ";
//  cout<<endl;
  int cur = 0, steps = 0;
  int ind1 = 0, ind2 = 0;
  vector<bool> ignr(v1.size());
  for (int i = 0; i < ignr.size(); ++i)
    ignr[i] = false;
  while (ind1 < v1.size() || ind2 < v2.size()){
    if (ind2 < v2.size() && v2[ind2].s <= cur){
      for (int i = ind1; i < v1.size(); ++i)
        if (v1[i] == v2[ind2].l1 && !ignr[i]){
          ignr[i] = true;
          break;
        }
      cur += 2; ++ind2; ++steps;
    } else { 
      while (ignr[ind1]) ++ind1;
      if (ind1 < v1.size() && v1[ind1] <= cur){
        ++cur; ++ind1; ++ steps;
      } else {
        if (ind1 >= v1.size() && ind2 >= v2.size())
          return steps;
        else
          return -1;
      }
    }
  }
  return steps;
}

int main(){
  int t; cin>>t;
  for (int i = 1; i <= t; ++i){
    int n; cin>>n;
    for (int j = 0; j < n; ++j){
      int a, b; cin>>a>>b;
      v1.push_back(a);
      L2 level2; level2.s = b; level2.l1 = a;
      v2.push_back(level2);
    }

    int temp;
    cout<<"Case #"<<i<<": ";
    if ((temp = play()) < 0)
      cout<<"Too Bad"<<endl;
    else
      cout<<temp<<endl;

    v1.clear();
    v2.clear();
  }
}
