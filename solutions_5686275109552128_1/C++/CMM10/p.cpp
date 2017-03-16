#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <cmath>
#include <stack>
#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
  freopen("in", "r", stdin);
  freopen("out", "w", stdout); 
  int tt;
  cin >> tt;
  for(int i=0; i<tt; ++i){
    int d; cin >> d;
    vector<int> p(d);
    int maxP=0;
    for(int j=0; j<p.size(); ++j){
      cin >> p[j];
      maxP=max(maxP,p[j]);
    }
    int res = maxP;
    while(maxP>1){
      int aux=maxP;
      for(int k=0; k<p.size();++k)
        aux+=floor((p[k]-1)/maxP);
      res=min(aux,res);
      --maxP;
    }
    cout << "Case #" << i+1 << ": " << res << endl; 
  }
}