#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <algorithm>
#include <string>
#include <cstring>

#define fori(i,b,e) for (int i = (b); i < (e); i++)
#define mp make_pair
#define pb push_back
#define add insert
#define all(a) (a).begin(), (a).end()
#define elsif else if
#define sz(a) ((int)(a).size())

#ifdef DEBUG
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif
#define next next_sadasddsa

using namespace std;

typedef long long int int64;
typedef long double ldb;
typedef pair<int,int> pii;

inline void printInt(int a) { printf("%d", a); }
inline void printDbl(double a) { printf("%.10lf", a); }
inline int getInt() { int res;  scanf("%d", &res);  return res; }
inline double getDbl() { double res;  scanf("%lf", &res);  return res; }

const int maxn = 100;
int pos[maxn], per[maxn];

struct Frac {
  int64 nom, den;
  inline void norm() {
    int64 d = __gcd(nom, den);
    nom /= d;
    den /= d;
  }
  Frac(int64 nom_, int64 den_) : nom(nom_), den(den_) {
    norm();
  }
  Frac(int64 nom_) : nom(nom_), den(1) {}

};

   Frac operator/ (Frac a, Frac b) {
    int64 nom = a.nom * b.den;
    int64 den = a.den * b.nom;
    return Frac(nom,den);
  }

   Frac operator* (Frac a, Frac b) {
    int64 nom = a.nom * b.nom;
    int64 den = a.den * b.den;
    return Frac(nom,den);
  }

   Frac operator- (Frac a, Frac b) {
    int64 nom = a.nom * b.den - a.den * b.nom;
    int64 den = a.den * b.den;
    return Frac(nom,den);
  }

   Frac operator+ (Frac a, Frac b) {
    int64 nom = a.nom * b.den + a.den * b.nom;
    int64 den = a.den * b.den;
    return Frac(nom,den);
  }

  bool operator<= (Frac a, Frac b) {
    return a.nom * b.den <= a.den * b.nom;
  }

  bool operator< (Frac a, Frac b) {
    return a.nom * b.den < a.den * b.nom;
  }

int64 solve() {
  int n = 0;
  int g = getInt();
  fori(i,0,g) {
    int d = getInt(), k = getInt(), m = getInt();
    fori(j,0,k) {
      pos[n] = d;
      per[n] = m + j;
      n++;
    }
  }
  int64 minRes = 1e18;
  fori(i,0,n) {
    int64 cur = 0;
    Frac v(360, per[i]);
    Frac t = Frac(360 - pos[i]) / v;
    fori(j,0,n) {
      if (i == j)
        continue;
      Frac v1(360, per[j]);
      //cerr << v1.nom << " " << v1.den << endl;
      Frac dist = (v1 * t + Frac(pos[j])) / Frac(360);
      //cerr << dist.nom << " " << dist.den << endl;
      int64 d1 = dist.nom / dist.den;
      if (d1 == 0) {
        cur++;
        continue;
      }
      if (dist.den == 1 && (v < v1)) {
        cur++;
      }
      cur += d1 - 1;
    }
    minRes = min(minRes, cur);
  }
  return minRes;
}

int main() {
#ifdef DEBUG
  freopen("in.txt", "rt", stdin);
  freopen("out.txt", "wt", stdout);
#endif
  srand(time(0));
  int T = getInt();
  fori(i,0,T) {
    printf("Case #%d: ", i+1);
    cout << solve() << endl;
  }
  return 0;
}