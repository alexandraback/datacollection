#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
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
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;

int t;

double dp[4000][4000];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> t;
  for (int i1=0;i1<t;i1++) {
    int n,x,y;
    cin >> n >> x >> y;
    int level = (abs(x)+y)/2;
    cout << "Case #" << i1+1 << ": "; 
    if (level==0) { cout << "1.0\n"; continue; }
    int cur = 0;
    while ((n-cur*4-1)>=0) {
      int th = cur*4+1;
      n-=th;
      cur++;
    }
    if (cur<level) { cout << "0.0\n"; continue; }
    if (cur>level) { cout << "1.0\n"; continue; }
    if (n==0 && level<cur) { cout << "1.0\n"; continue; }
    if (n==0 && level>=cur) { cout << "0.0\n"; continue; }
    int st = 2*cur;
    if (n-st>=y+1) { cout << "1.0\n"; continue; }
    if (y%2==0 && y/2==cur) { cout << "0.0\n"; continue; }
    //m0(dp);
    
    for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) dp[i][j] = 0;

    dp[0][0] = 1;
    for (int i=0;i<=n;i++) {
      for (int j=0;j<=n;j++) {
        //cout << i << " " << j << " " << dp[i][j] << "\n";
        dp[i+1][j]+=dp[i][j]*0.5;
        dp[i][j+1]+=dp[i][j]*0.5;
      }
    }
    double all = 0, my = 0;
    y++;
    //cout << n << " " << y << "\n";
    for (int i=0;i<=n;i++) {
      all+=dp[i][n-i];
      if (i>=y) my+=dp[i][n-i];
    }
    cout << fixed << setprecision(10) <<  my/all << "\n";
    //exit(0);
  }
  return 0;
}
