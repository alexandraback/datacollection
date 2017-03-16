#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <list>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <ctime>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
#define FORR(i,a,b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a; i>=b; i--)
#define mset(a,b) memset(a,b,sizeof(a))
#define sz(a) int( a.size() )
#define all(A) A.begin(),A.end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define X first
#define Y second

typedef long long i64;
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef pair<int,int> PII;
typedef vector<string> VS;
typedef pair<string, string> PSS;

PSS a[20];
char s1[25], s2[25];
int n;
int mask[20];
int ans = 0;

void solve(int code) {
  // printf("Code: %d \n", code);
  REP(i, n) {
    mask[i] = code % 2;
    code /= 2;
  }

  //  printf("N: %d\n", n);
  //REP(i, n) printf("%d ", mask[i]); printf("\n");
  int r = 0;
  REP(i, n) {
    if (mask[i] == 1) {
      continue;
    }

    bool f1 = false;
    bool f2 = false;

    REP(j, n) {
      if (mask[j] == 0) {
        continue;
      }

      //  printf("Compare: %s %s  <= %s %s\n", a[j].X.c_str(), a[j].Y.c_str(), a[i].X.c_str(), a[i].Y.c_str());

      f1 |= (a[i].X == a[j].X);
      f2 |= (a[i].Y == a[j].Y);
    }

    // printf("%d %d\n", f1,f2);
    if (f1 && f2) r++;
  }

  if (r > ans) ans = r;
}

int main(){

 #ifdef LocalHost
  freopen("input.txt","r", stdin);
  freopen("c.txt", "w", stdout);
 #endif

  int testNum;
  scanf("%d",&testNum);
  REP(testCase, testNum) {
    scanf("%d", &n);
    REP(i, n) {
      scanf("%s %s", s1, s2);
      a[i] = mp(string(s1), string(s2));

    }
    ans = 0;
    solve(6);
    REP(m, 1 << (n+1)) {
        solve(m);
    }
    printf("Case #%d: %d\n", testCase+1, ans);
  }
  return 0;
}
