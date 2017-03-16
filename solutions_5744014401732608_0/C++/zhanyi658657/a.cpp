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

int count(vector<vector<int> > &v)
{
  int B = v.size();
  vector<int> w(B, 0);
  for (int k = B - 2;k >= 0;k--) {
    if (v[k][B - 1]) {
      w[k] += 1;
    }
    for (int j = k + 1;j < B;++j) {
      if (v[k][j]) {
        w[k] += w[j];
      }
    }
  }
  return w[0];
}
void solve(int B, int M)
{

  vector<pair<int, int> > vpr;
  for (int i = 0;i < B;++i) {
    for (int j = i + 1;j < B;++j) {
      vpr.PB(MP(i, j));
    }
  }
  int N = vpr.size();
  for (int i = 1;i < (1<<N);++i) {
    vector<vector<int> > v(B, vector<int>(B, 0));
    REP (k, N) {
      if ((1<<k) & i) {
        v[vpr[k].first][vpr[k].second] = 1;
      }
    }
    int num = count(v);
    if (num == M) {
      cout<<"POSSIBLE"<<endl;
      REP (s, v.size()) {
        REP (t, v.size()) {
          cout<<v[s][t];
        }
        cout<<endl;
      }
      return;
    }
  }
  cout<<"IMPOSSIBLE"<<endl;
  
  
}
int main()
{
  freopen("data", "r", stdin);
  int T;
  cin>>T;
  for (int i = 1;i <= T;++i) {
    int B, M;
    cin>>B>>M;
    cout<<"Case #"<<i<<": ";
    solve(B, M);
    //cout<<endl;
    
  }
  return 0;
}

