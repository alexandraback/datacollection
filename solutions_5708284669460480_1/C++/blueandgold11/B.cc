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
// frequency of letter in kbd
int freq[N];
// frequency of matching letter of tgt
int ltr[N];
// probability  of matching prefix of tgt
double pre[N];
// probability of being at position i of s, letter j, matching prefix k of tgt
double dp[N][K][N];

int t, l, s;

string kbd, tgt;

void myCode() {
  int tt; cin >> tt;
  fo(ttt,tt) {
    cin >> t >> l >> s;
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

//    cerr << "got most = " << most << endl;

    fj(K)
      freq[j] = 0;
    fj(t)
      freq[kbd[j]-'A']++;
/*
    cerr << "got freqs:";
    fj(K)
      cerr << " " << freq[j];
    cerr << endl;
*/
    pre[0] = 1;
    bool doable = true;
    fi(l) {
      ltr[i] = 0;
      fj(t)
        if (tgt[i] == kbd[j])
          ltr[i]++;
      if (ltr[i] == 0)
        doable = false;
      pre[i+1] = pre[i]*ltr[i]/t;
    }
    if (!doable) {
      printf("Case #%d: 0.0\n",ttt+1);
      continue;
    }
/*
    cerr << "got ltr:";
    fj(l)
      cerr << " " << ltr[j];
    cerr << endl;
    cerr << "got pre:";
    fj(l+1)
      cerr << " " << pre[j];
    cerr << endl;
*/
    fi(N)
      fj(K)
        fk(N)
          dp[i][j][k] = 0;

    for (int i = 0; i < s; i++) {
      for (int j = 0; j < K; j++) {
        dp[i][j][0] = 1;
        if (tgt[0] == j+'A')
          dp[i][j][1] = 1.0*freq[j]/t;
        if (i > 0) {
          for (int k = 1; k < l; k++) {
            if (tgt[k] == j+'A')
              dp[i][j][k+1] = dp[i-1][tgt[k-1]-'A'][k]*freq[j]/t;
          }
        }
      }
    }
    
    double val = 0;
    for (int i = 0; i < s; i++)
      val += dp[i][tgt[l-1]-'A'][l];

    printf("Case #%d: %.9lf\n",ttt+1,most-val);
  }
}

int main () {
  srand(time(NULL));
  myCode();
  return 0;
}
