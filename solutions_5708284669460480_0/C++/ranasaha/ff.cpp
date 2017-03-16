#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
#else
#include "header.h"
#include "debug.h"
#endif
#define sz(s) int((s).size())
#define clr(a) memset(a,0,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int(i)=0; (i)<(n);++(i))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef pair <int,int> pii;
typedef long long ll;
template <class T> inline T gcd(T a,T b){return (!b? a : gcd(b,a%b));}
template <class T> inline T ABS(T x){return ((x)>0?(x):(-(x)));}
const int N = 20;

int t, k, l, s, htcn,temp,getans,big;
string str1, str2, str3;

ll getpow (ll b, ll p) {
  if (p == 0) {
    return 1;
  }
  ll sq = getpow (b, p / 2);
  sq *= sq;
  if (p % 2 == 1) sq *= b;
  return sq;
}

void func() {
  if (sz (str3) == s) {
    temp = 0;
    for (int i = 0; i < s;++i) {
      if (str3.substr (i, l) == str2) {
        ++htcn;
        ++temp;
      }
    }
    big = max (big, temp);
    return;
  }
  for(int i = 0; i < k; ++i) {
    str3 += str1[i];
    func();
    str3.pop_back();
  }
}
int main () {
  #ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
  #endif
  int tt;
  cin >> tt;
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    cin >> k >> l >> s >> str1 >> str2;
    htcn = big  = 0; getans = getpow (k,s);
    func ();
    printf ("%.10lf\n", big - (htcn * 1.0) / getans);
  }
}
