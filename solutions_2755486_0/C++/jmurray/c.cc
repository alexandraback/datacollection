#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

struct node {
  node *left, *right;
  int l,r,h;
  node(int lower, int upper, int height) {
    l=lower;r=upper;
    h=height;
    left=right=NULL;
  }
  ~node() {
    if (left) delete left;
    if (right) delete right;
  }
  node *getl() {
    if (left==NULL) left = new node(l, (l+r)/2, h);
    if (left->h < h) left->h=h;
    return left;
  }
  node *getr() {
    if (right==NULL) right = new node((l+r)/2, r, h);
    if (right->h < h) right->h=h;
    return right;
  }
  bool attack(int lower, int upper, int height, bool change) {
    // cout << "[" << l << ", " << r << "] (" << h << ") getting hit with [" << lower << ", " << upper << "] (" << height << ") " << (change?"(updating)":"") << "\n";
    if (lower < l) lower=l;
    if (upper > r) upper=r;
    if (lower >= upper) return false;
    if (h >= height) return false;
    if (lower == l && upper == r) {
      bool ret=(height>h);
      if (change) {
        h=height;
      }
      return ret;
    }
    bool ret = getl()->attack(lower, upper, height,change);
    if (getr()->attack(lower,upper,height,change)) {
      ret=true;
    }
    h = min(getl()->h, getr()->h);
    return ret;
  }
};

int main() {
  int numCases;
  cin >> numCases;
  for(int caseno=1;caseno<=numCases;caseno++) {
    int numTribes;
    cin >> numTribes;

#define mp make_pair
    vector<vector<pair<int,pair<int,int> > > > attacks(676061);
    // height, left, right
    for(int i=0;i<numTribes;i++) {
      int d,n,w,e,s,dd,dp,ds;
      cin >> d >> n >> w >> e >> s >> dd >> dp >> ds;
      for(int j=0;j<n;j++) {
        attacks[d].push_back(mp(s,mp(w,e)));
        d += dd;
        e += dp;
        w += dp;
        s += ds;
      }
    }
    int ans=0;
    node root(-(1000*1000*1000),1000*1000*1000,0);
    for(int i=0;i<attacks.size();i++) {
      sort(attacks[i].begin(),attacks[i].end());
      for(int j=0;j<attacks[i].size();j++) {
        if (root.attack(attacks[i][j].second.first,attacks[i][j].second.second,attacks[i][j].first,false)) {
          // cout << "day " << (i+1) << " attack from " << attacks[i][j].second.first << " to " << attacks[i][j].second.second << " at strength " << attacks[i][j].first << " succeeds\n";
          ans++;
        }
      }
      for(int j=0;j<attacks[i].size();j++) {
        root.attack(attacks[i][j].second.first,attacks[i][j].second.second,attacks[i][j].first,true)?1:0;
      }
    }
    cout << "Case #" << caseno << ": " << ans << '\n';
  }

  return 0;
}
