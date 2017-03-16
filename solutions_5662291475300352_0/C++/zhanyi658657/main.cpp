// File Name: main.cpp
// Author: ***
// Created Time: 2015年04月11日 星期六 08时26分21秒

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <cstring>
#include <cassert>
#include <fstream>
#include <sstream>
#include <cmath>
#define FOR(i,a,b)  for(int i=(int)(a);i<(int)(b);++i)
#define REP(i,a)  FOR(i,0,a)
#define PB push_back
#define MP make_pair
#define VC vector
#define VD vector<long long>
#define PII pair <int, int>
#define VI VC < int >
#define VF VC < float >
#define VS VC < string >
#define VVS VC < VS >
#define DB(a) cerr << #a << ": " << (a) << endl;
#define VALID(ret) (!isnan(ret) && !isinf(ret))
using namespace std;

//int solve(VI D, VI H, VI M)
int solve(VD D, VD H, VD M)
{
  int res = 0;
  vector<pair<long long, long long> > pr;
  REP (i, D.size()) {
    for (int j = 0;j < H[i];++j) {
      pr.PB(MP(D[i], M[i] + j));
    }
  }
  assert(pr.size() <= 2);
  if (pr.size() == 1) return 0;

  vector<long long> t(2, 0);
  REP (i, t.size()) {
    t[i] = (long long)(360 - (long long)pr[i].first)  * pr[i].second;
  }
  if (t[0] == t[1]) return 0;
  if (t[1] > t[0]) {
    swap(t[0], t[1]);
    swap(pr[0], pr[1]);
  }
  long long tt = 0;
  //long long dd = 0;
  //if (pr[0].first < pr[1].first) dd = 360 - (pr[1].first - pr[0].first);
  //else if (pr[0].first > pr[1].first) dd = 360 + (pr[0].first - pr[1].first);
  long long dd = 360 + (360 - pr[1].first);
  tt = dd * pr[1].second;
  if (tt <= t[0]) return 1;
  return 0;


}

int main()
{
  freopen("data.txt", "r", stdin);
  int T;
  cin>>T;
  REP (i, T) {
    int n;
    cin>>n;
    vector<long long> D(n, 0);
    vector<long long> H(n, 0);
    vector<long long> M(n, 0);
    REP (j, n) {
      cin>>D[j]>>H[j]>>M[j];
    }
    int num = solve(D, H, M);
    cout<<"Case #"<<i + 1<<": "<<' '<<num<<endl;
  }
    return 0;
}

