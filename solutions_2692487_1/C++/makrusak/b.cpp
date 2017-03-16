#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <ctime>

#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define ALL(x) x.begin(), x.end()
#define F first
#define S second
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,-1,sizeof(x))
#define pw(x) (1ull<<(x))

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 214748364;
const ll LLINF = 9223372036854775807LL;

int maxn = 110;

int dp[110][1000100];
int a,n;
int b[110];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t; cin >> t;
  for (int i1=0;i1<t;i1++) {
    cin >> a >> n;
    for (int i=0;i<n;i++) scanf("%d", &b[i]);
    sort(b, b+n);
    maxn = max(b[n-1], a)+10;
    for (int i=0;i<=n;i++) for (int j=0;j<maxn;j++) dp[i][j] = INF;
    dp[0][a] = 0;
    //if (i1==3) { cout << "beg"; }
    for (int i=0;i<n;i++) {
      //cout << i << "\n";
      for (int w=0;w<maxn;w++) {
        if (dp[i][w]>n) continue;
        int sz = w, it = 0;
        if (w<=1) it = INF; else 
          while (sz<=b[i]) { sz = sz+sz-1; it++; }
        dp[i+1][min(sz+b[i], maxn-1)] = min(dp[i+1][min(sz+b[i], maxn-1)], dp[i][w]+it);
        dp[i+1][w] = min(dp[i+1][w], dp[i][w]+1);
      }
    }
    int mi = INF;
    for (int i=0;i<maxn;i++) {
      mi = min(mi, dp[n][i]);
    }
    cout << "Case #" << i1+1 << ": " << mi << "\n";
  }
  return 0;
}
