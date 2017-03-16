#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

#define PRINT(x) cout << "DEBUG " << #x << " = " << x <<  endl;

#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fr(i, n) for(i = 0; i < (n); i++)
#define frr(i, n) for(int i = 0; i < (n); i++)
#define _cl(x) memset(x, 0, sizeof(x))
#define _rs(x) memset(x, -1, sizeof(x))

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef istringstream ISS;
typedef ostringstream OSS;
typedef long long ll;

const double eps = 1e-12;
const double inf = 1e100;

struct Car {
 bool lane;
 int d, v;

 bool operator < (const Car &c) const {
  return v < c.v;
 }
};

struct Collision {
 double t;
 int f, s;

 bool operator < (const Collision &c) const {
  return t < c.t;
 }
};

int N, C;
Car a[100];
Collision col[1000000];

void read(ifstream &fin)
{
 string lane;

 fin >> N;
 frr(i, N) {
  fin >> lane >> a[i].v >> a[i].d;
  a[i].lane = lane == "L";
 }
}

double collision(int f, int s) {
 if(a[f].d < a[s].d)
  return double(a[s].d - a[f].d - 5) / double(a[f].v - a[s].v);
 else
  return -1;
}

inline bool othercars(bool lane, double t, int car) {
 double pos = a[car].d + a[car].v * t;

 frr(i, N) if(a[i].lane == lane) {
  double d = a[i].d + a[i].v * t;
  if(a[i].v - eps > a[car].v) {
   if(d + 1e-3 > pos - 5 && d + eps < pos + 5)
    return true;
  } else if(a[i].v + eps < a[car].v) {
   if(d - eps > pos - 5 && d - 1e-3 < pos + 5)
    return true;
  } else {
   if(d - eps > pos - 5 && d + eps < pos + 5)
    return true;
  }
 }

 return false;
}

double rec(int c) {
 if(c >= C)
  return inf;

 double res = col[c].t;

 if(a[col[c].f].lane != a[col[c].s].lane) {
  res = max(res, rec(c + 1));

  bool fl = a[col[c].f].lane;
  bool sl = a[col[c].s].lane;

  a[col[c].s].lane = !a[col[c].s].lane;
  if(!othercars(!a[col[c].f].lane, col[c].t, col[c].f)) {
   a[col[c].s].lane = !a[col[c].s].lane;
   a[col[c].f].lane = !a[col[c].f].lane;
   if(!othercars(!a[col[c].s].lane, col[c].t, col[c].s)) {
    a[col[c].f].lane = !a[col[c].f].lane;

    a[col[c].s].lane = !a[col[c].s].lane;
    a[col[c].f].lane = !a[col[c].f].lane;
    res = max(res, rec(c + 1));
   }
  }
  a[col[c].f].lane = fl;
  a[col[c].s].lane = sl;

  return res;
 }

 if(!othercars(!a[col[c].f].lane, col[c].t, col[c].f)) {
  a[col[c].f].lane = !a[col[c].f].lane;
  res = max(res, rec(c + 1));
  a[col[c].f].lane = !a[col[c].f].lane;
 } else if(!othercars(!a[col[c].f].lane, col[c].t, col[c].s)) {
  a[col[c].s].lane = !a[col[c].s].lane;
  res = max(res, rec(c + 1));
  a[col[c].s].lane = !a[col[c].s].lane;
 }

 return res;
}

void proc(ofstream &fout)
{
 C = 0;
 sort(a, a + N);
 frr(i, N) for(int j = 0; j < i; ++j) {
  double t = collision(i, j);
  if(t > -.5) {
   col[C].t = t;
   col[C].f = i;
   col[C].s = j;
   ++C;
  }
 }

 sort(col, col + C);

 double res = rec(0);
 if(res > 1e50)
  fout << "Possible" << endl;
 else
  fout << fixed << setprecision(7) << res << endl;
}

int main()
{
 int i;
 int NT;

 ifstream fin("in");
 ofstream fout("out");
 string ln;

 getline(fin, ln);
 istringstream is(ln);
 is >> NT;

 fr(i, NT)
 {
  read(fin);
  fout << "Case #" << i + 1 << ": ";
  cout << "Case #" << i + 1 << endl;
  proc(fout);
 }

 return 0;
}
