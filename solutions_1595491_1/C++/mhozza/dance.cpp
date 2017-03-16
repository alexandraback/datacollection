#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <list>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<pair<int,int> > VPII;
typedef vector<LL> VLL;
typedef vector<pair<LL,LL> > VPLL;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;

#define PI 3.14159265358979323
#define EE 2.71828182845
#define EPS 10e-11
#define INF 10000000

inline LL MAX(LL a, LL b){ return a < b ? b : a;}
inline LL MIN(LL a, LL b){ return a < b ? a : b;}

#define FOR(i,n)      for(int i=0;i<(n);i++)
#define FORD(i,n)     for(int i=(n)-1;i>=0;i--)
#define FORR(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define FORE(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define SIZE(x) ((int) ((x).size()))

#define PB push_back
#define MP make_pair

int main(){
  int t;
  cin >> t;
  FOR(i,t)
  {
    int n,s,p,sum = 0;
    cin >> n >> s >> p;
//     cerr << n << " " << s << " " << p << endl;
    VI scr(n);
    FOR(j,n)
    {
      cin >> scr[j];      
    }
//     sort(scr.begin(), scr.end(), greater<int>());
    FOR(j,n)
    {
      int ls = scr[j]/3, hs;
      hs = ls;
      if(scr[j] % 3 > 0)
      {
        hs = ls+1;
      }
//       cerr << "HS:" << hs << ", s: " << s << endl;
      if(hs>=p)
      {
        sum++;
      }
      else if(s>0 && hs+1>=p && scr[j] > 1 && scr[j]%3!=1)
      {
        s--;
        sum++;
      }
    }
    cout << "Case #" << i+1 << ": " << sum << endl;
  }
  return 0;
}

