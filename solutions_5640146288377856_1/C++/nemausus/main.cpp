//author Naresh
#include <algorithm>
#include <bitset>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ctype.h>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define SI(x) ((int)x.size())
#define PB(x) push_back(x)
#define MP(a,b) make_pair(a, b)
#define ALL(a) a.begin(),a.end()

#define SS ({int x;scanf("%d", &x);x;})
#define SSL ({long long int x;scanf("%lld", &x);x;})
#define REP(i, a, b) for(int i=(a); i<(b); ++i)
#define IREP(i, a, b) for(int i=(a); i>=(b); --i)
#define ITER(i,v) for(auto i : (v))
#define SORT(a) sort(a.begin(),a.end())
#define V vector
#define S string
typedef V<int> VI;
typedef V<S> VS;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<S, int> PSI;
typedef pair<int, S> PIS;
typedef pair<S, S> PSS;
typedef map<S, int> MSI;
typedef map<S, S> MSS;
typedef map<int, int> MII;
typedef map<int, S> MIS;

#define INF 1000000000

template<class T>
T gcd(T a, T b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

struct Point {
  int x;
  int y;
};

template<class T>
void printMap(T m) {
  for(const auto& i : m) {
    cout << i.first << " " << i.second << " ";
  }
  cout << endl;
}

template<typename T>
void printList(T l) {
  for(const auto& i : l) {
    cout << i.first << " " << i.second << "\n";
  }
  cout << endl;
}

bool valid(int i, int j, int n) {
  return i>=0 && i<n && j>=0 && j<n;
}

template<typename T>
T reverse(T n) {
  T reverse = 0;
  while (n != 0) {
    reverse = reverse * 10;
    reverse = reverse + n%10;
    n = n/10;
  }
  return reverse;
}

template<typename T>
int firstdigit(T n) {
  int ans = 0;
  while (n != 0) {
    ans = n%10;
    n = n/10;
  }
  return ans;
}

template<typename T>
int digits(T n) {
  int ans = 0;
  while (n != 0) {
    ans++;
    n = n/10;
  }
  return ans;
}

int main() {
  freopen("/Users/knaresh/codejam/codejam/in.txt", "r", stdin);
  freopen("/Users/knaresh/codejam/codejam/out.txt", "w", stdout);
  int testCase = SS;
  int testNo = 1;
  while(testCase--) {
      int ans = 0;
      int r = SS;
      int c = SS;
      int w = SS;
      int oneRow = c/w;
      ans = oneRow * (r-1);
      ans += w - 1 + c/w;
      ans += c%w == 0 ? 0 : 1;
    printf("Case #%d: %d\n", testNo++, ans);
  }
  return 0;
}
