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

const int N = 110;
const int K = 30;
// pos in s, letter -> exp val
double p[N][K];

int k, l, s;

string kbd, tgt;
string str;

int cnt(int pos) {
  int ret = 0;
  if (pos == s) {
    fi(s-l+1) {
      bool ok = true;
      fj(l)
        if (str[i+j] != tgt[j])
          ok = false;
      if (ok)
        ret++;
    }
    // printf("%s -> %d\n",str.c_str(),ret);
  } else {
    fi(sz(kbd)) {
      str[pos] = kbd[i];
      ret += cnt(pos+1);
      str[pos] = '\0';
    }
  }
  return ret;
}

void myCode() {
  int tt; cin >> tt;
  fo(ttt,tt) {
    cin >> k >> l >> s;
    cin >> kbd;
    cin >> tgt;
    int lps = 0;
    fr(i,1,l) {
      bool ok = true;
      fj(i)
        if (tgt[j] != tgt[l-i+j])
          ok = false;
      if (ok)
        chmax(lps,i);
    }
    int most = (s-lps)/(l-lps);
    // cout << most << endl;

    str.resize(s);
    int tot = cnt(0);
    // printf("%d\n",tot);
    double prob = tot/pow(k,s);

    printf("Case #%d: %.9lf\n",ttt+1,tot?(most-prob):0.0);
  }
}

int main () {
  srand(time(NULL));
  myCode();
  return 0;
}
