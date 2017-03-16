// File Name: main.cpp
// Author: ***
// Created Time: 2014年04月12日 星期六 20时51分14秒

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
using namespace std;
vector<string> pin;
vector<int> ind;
long long cnt = 0;

bool ok()
{
  map<char, int> mp;
  char pre = '#';
  for (int i = 0;i < ind.size();++i) {
    for (int k = 0;k < pin[ind[i]].size();++k) {
      char tc = pin[ind[i]][k];
      if (mp.count(tc) == 0) {//new
        mp[tc] = 1;
        pre = tc;
      } else {
        if (pre != tc) return false;
      }
    }
  }
  return true;
}
int tc = 0;
void search(int i, int n)
{
  if (i == n) {
//    cout<<tc++<<endl;
    if (ok()) cnt = (cnt + 1) % 1000000007;
    return;
  } else {
    for (int j = i;j < n;++j) {
      swap(ind[i], ind[j]);
      search(i + 1, n);
      swap(ind[i], ind[j]);
    }
  }
}
void solve()
{
  tc = 0;
  ind.clear();

  pin.clear();
  cnt = 0;
  int n;
  cin>>n;
  string tmp;
  for (int i = 0;i < n;++i) {
    cin>>tmp;
    pin.push_back(tmp);
  }
  for (int i = 0;i < n;++i) {
    ind.push_back(i);
  }
  search(0, n);
  cout<<cnt<<endl;
}

int main()
{

   freopen("/home/zhanyi/Downloads/B-small-attempt0.in", "r", stdin);
 //freopen("data.txt", "r", stdin);
  int T;
  cin>>T;
  for (int i = 1;i <= T;++i) {
    cout<<"Case #"<<i<<": ";
    solve();
  }
    return 0;
}

