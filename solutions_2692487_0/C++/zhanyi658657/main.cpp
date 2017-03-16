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


void solve()
{
  long A, n;
  vector<long> t;
  long d[200];

  cin>>A>>n;
  for (int i = 1;i <= n;++i) {
    long t1;
    cin>>t1;
    t.push_back(t1);
  }
  //for (int i = 1;i <= n;++i) {
  //  cout<<t[i - 1]<<' ';
  //}
  sort(t.begin(), t.end());
  for (int i = 1;i <= n;++i) {
    d[i] = t[i - 1];
  }
  //sort(d + 1, d + n);
  //for (int i = 1;i <= n;++i) {
  //  cout<<d[i]<<' ';
  //}
  
  long ans[200];
  for (int i = 1;i <= n;++i) {
    ans[i] = 10000000;
  }
  ans[0] = n;
  
  for (int i = 1;i <= n;++i) {
      long tmp = A;
      int count = 0;
      if(tmp == 1) continue;;
      for (int j = 1;j <=i;++j) {
	if(tmp > d[j]) {
	  tmp += d[j];
	} else {
	  int b = tmp - 1;
	  while(tmp <= d[j]) {
	    tmp += b;
	    b = tmp - 1;
	    count++;
	  }
	  tmp += d[j];
	}
      }
      count += n - i;
      ans[i] = count;
  }
  //for (int i = 1;i <= n;++i) {
  //  cout<<ans[i]<<' ';
  //}
  int min = 1000;
  for (int i = 0;i <= n;++i) {
    if(ans[i] < min) {
      min = ans[i];
    }
  }
  cout<<min<<endl;
}
int main()
{
  //freopen("data.txt", "r", stdin);
  freopen("test.txt", "r", stdin);
  freopen("test.out", "w", stdout);
  //freopen("A-small-attempt0.in", "r", stdin);
  //freopen("A-small-attempt0.out", "r", stdin);
  //freopen("C-large-practice.in", "r", stdin);
  //freopen("C-large-practice.out", "w", stdout);
  int t;
  cin>>t;
  for (int i = 1;i <= t;++i) {
    cout<<"Case #"<<i<<": ";
    solve();
  }
  return 0;
}
