#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
  mr = VI(w.size(), -1);
  mc = VI(w[0].size(), -1);
  
  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

int a[10000];
int b[10000];
int ct;
map<string,int> mapl,mapr;
int main(){
  int t;
  scanf("%d",&t);
  for(int e = 0 ; e < t ; e++ ){
    mapl.clear();
    mapr.clear();
    ct = 0;
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++ ){
      string x,y;
      cin >> x >> y;
      if( mapl.find(x) == mapl.end() ){
        int ind = mapl.size();
        mapl[x] = ind;
      }
      if( mapr.find(y) == mapr.end() ){
        int ind = mapr.size();
        mapr[y] = ind;
      }
      a[ct] = mapl[x];
      b[ct] = mapr[y];
      ct++;
    }
    VVI w;
    VI v = VI(mapr.size(),0);
    for(int i = 0 ; i < mapl.size() ; i++ ){
      w.push_back(v);
    }
    for(int i = 0 ; i < ct ; i++ ){
      w[a[i]][b[i]] = 1;
    }
    VI x,y;
    int res = BipartiteMatching(w,x,y);
    printf("Case #%d: %d\n",e+1,(int)(n-(mapl.size()+mapr.size()-res)));
  }
}

