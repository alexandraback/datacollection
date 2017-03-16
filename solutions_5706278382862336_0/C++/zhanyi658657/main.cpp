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
bool ok(unsigned long long a)
{
  while (a % 2 == 0) {
    a /= 2;
  }
  if (a == 1) return true;
  return false;
}
template<class T> inline T gcd(T a,T b)//NOTES:gcd(                              
  {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
void solve()
{
  string a;
  cin>>a;
  for (int i = 0;i < a.size();++i) {
    if (a[i] == '/') a[i] = ' ';
  }
  long long up;
  long long down;
  istringstream sin(a);
  sin>>up>>down;
  long long com = gcd(up, down);
  //cout<<com;
  up /= com;
  down /= com;
  if (!ok(down)) {
    cout<<"impossible"<<endl;
    return;
  }
  int cnt = 0;
  for (int i = 1;i <= 40;++i) {
    //if (up > 1) up -= 1;
    down /= 2;
    cnt += 1;
    if (down <= up) {
      cout<<cnt<<endl;
      return;
    }
  }
  cout<<"impossible"<<endl;
}

int main()
{

   freopen("/home/zhanyi/Downloads/A-small-attempt0.in", "r", stdin);
 //freopen("data.txt", "r", stdin);
  int T;
  cin>>T;
  for (int i = 1;i <= T;++i) {
    cout<<"Case #"<<i<<": ";
    solve();
  }
    return 0;
}

