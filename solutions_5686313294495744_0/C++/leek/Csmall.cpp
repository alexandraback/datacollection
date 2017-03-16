#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int N;
map<string, int> idx;
set<string> sset;
vector<pair<int ,int> > li;
int cnt1[3000];
int cnt2[3000];
bool v1[3000];
bool v2[3000];

int cntFake(vector<pair<int, pair<int, int> > >& ps) {
  int ret= 0;
  for(int i =0; i<ps.size(); i++) {
    int x1 = ps[i].second.first;
    int x2 = ps[i].second.second;
    if(v1[x1] && v2[x2]) ret ++;
    v1[x1] = true;
    v2[x2] = true;
  }
  return ret;
}

int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    idx.clear();
    sset.clear();
    li.clear();
    for(int i=0; i<3000;i ++) {
      cnt1[i] = 0;
      cnt2[i] = 0;
      v1[i] = false;
      v2[i] = false;
    }

    cin >> N;
    int icnt = 0;
    for(int i=0; i<N;i ++) {
      string s1, s2;
      cin >> s1 >> s2;
      if(sset.find(s1) == sset.end()) {
        icnt ++;
        idx.insert(make_pair(s1, icnt));
        sset.insert(s1);
      }
      if(sset.find(s2) == sset.end()) {
        icnt ++;
        idx.insert(make_pair(s2, icnt));
        sset.insert(s2);
      }
      cnt1[(idx.find(s1))->second] ++;
      cnt2[(idx.find(s2))->second] ++;
      li.push_back(make_pair(idx.find(s1)->second, idx.find(s2)->second));
    }
    vector<pair<int, pair<int, int> > > ps;
    for(int i=0; i<li.size(); i++) {
      int x1 = li[i].first;
      int x2 = li[i].second;
      ps.push_back(make_pair(min(cnt1[x1],cnt2[x2]), make_pair(x1, x2)));
    }

    sort(ps.begin(), ps.end());
    int ret = cntFake(ps);

    printf("Case #%d: %d\n",tc,ret);


  }

  return 0;
}