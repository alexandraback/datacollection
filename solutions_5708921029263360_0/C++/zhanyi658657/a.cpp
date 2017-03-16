// File Name: a.cpp
// Author: ***
// Created Time: 2016年04月09日 星期六 08时44分10秒

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
#define PII pair <int, int>
#define VI VC < int >
#define VF VC < float >
#define VS VC < string >
#define VVS VC < VS >
#define DB(a) cerr << #a << ": " << (a) << endl;
#define VALID(ret) (!isnan(ret) && !isinf(ret))
using namespace std;

void solve(int J, int P, int S, int K)
{
  map<vector<int>, int> inset;

  map<vector<int>, int> hist; 

  REP (j, J) {
    vector<int> v = {j, -1, -1};
    hist[v] = 0;
  }
  REP (s, S) {
    vector<int> v = {-1, -1, s};
    hist[v] = 0;
  }
  REP (p, P) {
    vector<int> v = {-1, p, -1};
    hist[v] = 0;
  }


  REP (j, J) REP (p, P) {
    vector<int> v = {j, p, -1};
    hist[v] = 0;
  }
  REP (j, J) REP (s, S) {
    vector<int> v = {j, -1, s};
    hist[v] = 0;
  }
  REP (p, P) REP (s, S) {
    vector<int> v = {-1, p, s};
    hist[v] = 0;
  }
  
  vector<vector<int> > res;
  
  
  
  while (true) {
    int minn = 100000000;
    VI minv;
    int mj = 100;
    int mp = 100;
    int ms = 100;
    int minp= 100000000;
    REP (j, J) REP (p, P) REP (s, S) {
      vector<int> v = {j, p, s};
      if (inset.count(v) > 0) continue;
      vector<int> v0 = {j, p, -1};
      vector<int> v1 = {j, -1, s};
      vector<int> v2 = {-1, p, s};
      vector<int> w0 = {j, -1, -1};
      vector<int> w1 = {-1, p, -1};
      vector<int> w2 = {-1, -1, s};
      int cnt0 = hist[v0];
      int cnt1 = hist[v1];
      int cnt2 = hist[v2];
      int pnt0 = hist[w0];
      int pnt1 = hist[w1];
      int pnt2 = hist[w2];
      if (cnt0 >= K) continue;
      if (cnt1 >= K) continue;
      if (cnt2 >= K) continue;
      cnt0 = min(cnt0, cnt1);
      cnt0 = min(cnt0, cnt2);
      pnt0 = min(pnt0, pnt1);
      pnt0 = min(pnt0, pnt2);
      if (cnt0 < minn ||
          (cnt0 == minn && pnt0 < minp) ||
          (cnt0 == minn && pnt0 == minp && s < ms) ||
          (cnt0 == minn && pnt0 == minp && s == ms && p < mp) ||
          (cnt0 == minn && pnt0 == minp && s == ms && p == mp && j < mp)
          ) {
        minn = cnt0;
        minv = v;
        minp = pnt0;
        mj = j;
        mp = p;
        ms = s;
      }
    }
    if (minn == 100000000) {
      break;
    } else {
      inset[minv] = 1;
      
      int j = minv[0];
      int p = minv[1];
      int s = minv[2];
      vector<int> v0 = {j, p, -1};
      vector<int> v1 = {j, -1, s};
      vector<int> v2 = {-1, p, s};
      vector<int> w0 = {j, -1, -1};
      vector<int> w1 = {-1, p, -1};
      vector<int> w2 = {-1, -1, s};
      hist[v0] += 1;
      hist[v1] += 1;
      hist[v2] += 1;
      hist[w0] += 1;
      hist[w1] += 1;
      hist[w2] += 1;
      res.PB(minv);
    }
  }
  cout<<res.size()<<endl;
  REP (i, res.size()) {
    cout<<res[i][0] + 1<<' ';
    cout<<res[i][1] + 1<<' ';
    cout<<res[i][2] + 1<<endl;
  }
  
  
}
int main()
{
  freopen("data", "r", stdin);
  int T;
  cin>>T;
  for (int i = 1;i <= T;++i) {
    int J, P, S;
    int K;
    cin>>J>>P>>S>>K;
    cout<<"Case #"<<i<<": ";
    solve(J, P, S, K);
    
  }
  return 0;
}

