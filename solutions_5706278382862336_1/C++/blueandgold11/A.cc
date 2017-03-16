#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define x first
#define y second
#define fi(n) fo(i,n)
#define fj(n) fo(j,n)
#define fk(n) fo(k,n)
#define fd(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define fo(i,n) fr(i,0,n)
#define fr(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(x) (x).begin(),(x).end()
#define sqr(x) ((x)*(x))
#define srt(x) sort(all(x))

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int INF = 1000*1000*1000+7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
template<class T> int chmin(T &t, T f) { return (t>f) ? (t=f,1) : 0; }
template<class T> int chmax(T &t, T f) { return (t<f) ? (t=f,1) : 0; }

inline int getint() {
  int a;
  return scanf("%d",&a) ? a : (fprintf(stderr,"trying to read\n"),-1);
}

inline double getdouble() {
  double a;
  return scanf("%lf",&a) ? a : (fprintf(stderr,"trying to read\n"),-1);
}

ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b,a%b);
}

int bit_count(ll x) {
  int ret = 0;
  while (x) {
    if (x & 1)
      ret++;
    x >>= 1;
  }
  return ret;
}

int ctz(ll x) {
  int ret = 0;
  while (x && !(x&1)) {
    ret++;
    x >>= 1;
  }
  return ret;
}

int hb(ll x) {
  int ret = 0;
  while (x) {
    ret++;
    x >>= 1;
  }
  return ret;
}

void myCode() {
  int ttt = getint();
  fo(tt,ttt) {
    printf("Case #%d: ",tt+1);
    ll p, q;
    scanf("%lld/%lld",&p,&q);
    ll g = gcd(p,q);
    //cerr << g << endl;
    p /= g;
    q /= g;
    //cerr << p << " " << q << endl;

    if (bit_count(q) != 1) {
      printf("impossible\n");
      continue;
    }

    printf("%d\n",ctz(q) - hb(p) + 1);
  }
}

int main () {
  srand(time(NULL));
  myCode();
  return 0;
}
