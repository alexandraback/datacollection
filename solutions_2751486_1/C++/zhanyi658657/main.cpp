#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;


char a[1000005];
long long ans[1000005];
long long back[1000005];
bool is(char c)
{
  return c=='a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

long long solve(long long n)
{
  memset(ans, 0, sizeof(ans));
  int L = strlen(a);

  if(!is(a[0]) ){
   back[0] = 1;
  } else {
   back[0] = 0; 
  }
  for (int i = 1;i < L;++i) {
    if(!is(a[i])) {
      back[i] = back[i - 1] + 1;
    } else {
      back[i] = 0;
    }
  }
  //for (int i = 0;i < L;++i) {
  //  cout<<back[i]<<' ';
  //}
  //cout<<endl;
  for (int i = 0;i < n - 1;++i) {
    ans[i] = 0;
  }


  for (int i = n - 1;i < L;++i) {
    if(is(a[i])) {
     ans[i] = ans[i - 1]; 
    }
    else {
      if(back[i] >= n) {
	ans[i] = i + 2- n;
      } else {
	ans[i] = ans[i - 1];
      }
    }
  }
  long long sum = 0;
  for (int i = 0;i < L;++i) {
    sum += ans[i];
  }
  return sum;
}
void solve()
{
  long long n;
  cin>>a>>n;
  long long v1 = solve(n);
  cout<<v1<<endl;
  //int v2 = solve(n + 1);
  //cout<<v1<<' '<<v2<<endl;
  //cout<<v1 - v2<<endl;
}
int main()
{
  //freopen("data.txt", "r", stdin);
  //freopen("test.txt", "r", stdin);
  //freopen("test.out", "w", stdout);
  freopen("A-large.in", "r", stdin);
  freopen("A-large.out", "w", stdout);
  //freopen("A-small-attempt0.in", "r", stdin);
  //freopen("A-small-attempt0.out", "w", stdout);
  int t;
  cin>>t;
  for (int i = 1;i <= t;++i) {
    cout<<"Case #"<<i<<": ";
    solve();
  }
  return 0;
}
