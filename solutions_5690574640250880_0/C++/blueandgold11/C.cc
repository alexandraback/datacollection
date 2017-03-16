#include <algorithm>
#include <cassert>
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

int a[50][50];

void myCode() {
  int tt = getint();
  fo(ttt,tt) {
    printf("Case #%d:\n",ttt+1);
    int m = getint(), n = getint();
    int x = getint();
    int mm = m, nn = n;

    if (x == m*n-1) {
      fi(m) {
        fj(n)
          printf("%c",(i || j) ? '*' : 'c');
        printf("\n");
      }
      continue;
    }

    fi(m)
      fj(n)
        a[i][j] = 0;

    while (true) {
      if (mm >= nn) {
        if (mm >= 3 && x >= nn) {
          fj(nn)
            a[mm-1][j] = 1;
          mm--;
          x -= nn;
        } else
          break;
      } else {
        if (nn >= 3 && x >= mm) {
          fi(mm)
            a[i][nn-1] = 1;
          nn--;
          x -= mm;
        } else
          break;
      }
    }

    if (x > max(mm-2,0) * max(nn-2,0)) {
      printf("Impossible\n");
      continue;
    }

    while (mm >= 3 && x >= nn-2) {
      fr(j,2,nn)
        a[mm-1][j] = 1;
      mm--;
      x -= nn-2;
    }

    if (mm >= 3) {
      fr(j,nn-x,nn)
        a[mm-1][j] = 1;
      mm--;
      x -= x;
    }

    fi(m) {
      fj(n)
        printf("%c",(i == 0 && j == 0) ? 'c' :  (a[i][j] ? '*' : '.'));
      printf("\n");
    }
  }
}

int main () {
  srand(time(NULL));
  myCode();
  return 0;
}
