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
int solve(int N)
{
  map<int, int> cnt;
  for (int i = 0;i < N * 2 - 1;++i) {
    for (int j = 0;j < N;++j) {
      int p;
      cin>>p;
      if (cnt.count(p) == 0) {
        cnt[p] = 1;
      } else {
        cnt[p] += 1;
      }
    }
  }
  vector<int> v;
  for (auto &it:cnt) {
    if (it.second %2 == 1) {
      v.PB(it.first);
    }
  }
  sort(v.begin(), v.end());
  for (auto &it:v) {
    cout<<it<<' ';
  }
  cout<<endl;
}
int main()
{
  freopen("data", "r", stdin);
  int T;
  cin>>T;
  for (int i = 1;i <= T;++i) {
    int N;
    cin>>N;
    
    cout<<"Case #"<<i<<": ";
    solve(N);
    
  }
  return 0;
}

