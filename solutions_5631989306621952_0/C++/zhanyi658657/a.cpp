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
string solve(string s)
{
  if (s.size() == 0) return "";
  if (s.size() == 1) return s;

  char maxc = 'A';
  REP (j, s.size()) {
    if (s[j] > maxc) maxc = s[j];
  }
  vector<int> pos;
  pos.PB(-1);
  REP (j, s.size()) {
    if(s[j] == maxc) pos.PB(j);
  }
  string pre = "";
  for (int i = 0;i < pos.size() - 1;++i) {
    pre += string(1, maxc);
  }
  pos.PB(s.size());
  //cout<<s<<endl;
  for (int k = 0;k < pos.size() - 1;++k) {
    if (pos[k] == pos[k + 1] -1) continue;
    string t(s.begin() + pos[k] + 1, s.begin() + pos[k + 1]);
    if (k == 0) t  = solve(t);
    //cout<<"T:"<<t<<endl;
    pre = pre + (t);
  }
  return pre;
}
int main()
{
  freopen("data", "r", stdin);
  int T;
  cin>>T;
  for (int i = 1;i <= T;++i) {
    string s;
    cin>>s;
    string ans = solve(s);
    cout<<"Case #"<<i<<": "<<ans<<endl;
  }
  return 0;
}

