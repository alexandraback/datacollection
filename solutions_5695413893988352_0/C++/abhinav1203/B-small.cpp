#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////
char str1[1005], str2[1005];
int main()
{
  int T, test, pow[4], len, i, j, tmp, modValue, k, ansA, ansB, minDiff;
  bool found1, found2;
  vector<int> v1, v2;
  scanf("%d", &T);
  pow[1] = 10;
  pow[2] = 100;
  pow[3] = 1000;
  for (test=1; test<=T; test++) {
    minDiff = 1e9;
    scanf("%s %s", str1, str2);
    len = strlen(str1);
    v1.clear(); v2.clear();
    for (j=0; j<pow[len]; j++) {
      tmp = j;
      found1 = found2 = true;
      for (k=0; k<len; k++) {
	modValue = tmp%10;
	if (str1[len-1-k]!=(char)(modValue+(int)'0') && str1[len-1-k]!='?') {
	  found1=false;
	}
	if (str2[len-1-k]!=(char)(modValue+(int)'0') && str2[len-1-k]!='?') {
	  found2=false;
	}
	tmp/=10;
      }
      if (found1) {
	v1.push_back(j);
      }
      if (found2) {
	v2.push_back(j);
      }
    }
    for (i=0; i<v1.size(); i++) {
      for (j=0; j<v2.size(); j++) {
	if (abs(v2[j]-v1[i]) < minDiff) {
	  minDiff = abs(v2[j]-v1[i]);
	  ansA = v1[i];
	  ansB = v2[j];
	}
      }
    }
    printf("Case #%d: ", test);
    if (len==1) {
      printf("%01d %01d\n", ansA, ansB);
    } else if(len==2) {
      printf("%02d %02d\n", ansA, ansB);
    } else if (len==3) {
      printf("%03d %03d\n", ansA, ansB);
    }
    //printf("%d %d\n", ansA, ansB);
  }
    return 0;
}
