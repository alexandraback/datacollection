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

void solve()
{
  int N,M,K;
  cin>>N>>M>>K;
  if (N < M) { swap(N, M); }
  
  if (M <= 2) {
    cout<<K<<endl;;
    return;
  }
  if (K <= 4) {
    cout<<K<<endl;
    return;
  }
  int min = K;
  for (int w = 1;w + 2<= M;++w) {
    for (int d = w;d + 2<= N;++d) {
      int sz = (w + 2) * (d + 2);
      if (sz < K) continue;
      else if (K >= sz - 4) {
        int tmp = 2 * w + 2 * d + (K - (sz - 4));
        if (tmp < min) min = tmp;
      } else {
        continue;
      }
    }
  }
  cout<<min<<endl;
}

int main()
{

   freopen("/home/zhanyi/Downloads/C-small-attempt0.in", "r", stdin);
 //freopen("data.txt", "r", stdin);
  int T;
  cin>>T;
  for (int i = 1;i <= T;++i) {
    cout<<"Case #"<<i<<": ";
    solve();
  }
    return 0;
}

