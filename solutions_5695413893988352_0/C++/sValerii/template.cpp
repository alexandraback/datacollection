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

pair<string, string> solve(string a, string b) {
  string r1 = "", r2 = "";

  int n = sz(a);
  int v = 0;
  char ch;
  REP(i, n) {
    if (v == 0) {
      if (a[i] == b[i] && a[i] == '?') {
        r1 += "0";
        r2 += "0";
      } else if (a[i] != '?' && b[i] != '?') {
        r1 += a[i];
        r2 += b[i];

        if (a[i] > b[i]) v = 1;
        else if (a[i] < b[i]) v = -1;
      } else {
        if (a[i] != '?') ch = a[i];
        else ch = b[i];

        r1 += ch;
        r2 += ch;
      }
    }
    else if (v  == 1) {
        if (a[i] != '?') r1 += a[i];
        else r1 += '0';

        if (b[i] != '?') r2 += b[i];
        else r2 += '9';

    } else if (v == -1) {
      if (a[i] != '?') r1 += a[i];
      else r1 += '9';

      if (b[i] !='?') r2 += b[i];
      else r2 +='0';
    }
  }

  return mp(r1,r2);
}

bool match(int num, string s) {
  FORD(i, sz(s)-1, 0) {
    int ch = num % 10;
    if (s[i] != '?' && ch != s[i]-'0') return false;
    num /= 10;
  }
  if (num > 0) return false;
  return true;
}

void printNum(int num, int sz) {
  int c = num;
  int k = 0;
  if (num == 0) k = 1;
  while(num) k++, num/=10;
  while (k++<sz) printf("0");
  printf("%d", c);
}

int main(){

 #ifdef LocalHost
  freopen("input.txt","r", stdin);
  freopen("b.txt", "w", stdout);
 #endif

  int testNum;
  scanf("%d\n",&testNum);
  char s1[20], s2[20];
  REP(testCase, testNum) {
    scanf("%s %s", s1, s2);
    //pair<string, string> r = solve(string(s1), string(s2));
    //printf("Case #%d: %s %s\n", testCase+1, r.X.c_str(), r.Y.c_str());
    int ans = 10000;
    int u,v;
    REP(i,1000)
      REP(j,1000)
      if (match(i, string(s1)) && match(j, string(s2)) && abs(i-j) < ans) {
        ans = abs(i-j);
        u = i;
        v = j;
      }
    printf("Case #%d: ", testCase+1);
    printNum(u, sz(string(s1)));
    printf(" ");
    printNum(v, sz(string(s1)));
    printf("\n");
  }

  return 0;
}
