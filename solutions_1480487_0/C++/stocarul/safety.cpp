#include<cstdio>
#include<vector>
#include<algorithm>
#define infile "safety.in"
#define outfile "safety.out"
#define eps 0.00000001

using namespace std;

vector <int> j;
vector <double> r;
int x;

void read() {

  j.clear();
  r.clear();

  x = 0;
  int n, y;

  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", &y);
    x += y;
    j.push_back(y);
  }
}

bool valid(int id, double pr) {

  double cnt = pr;
  double sc = j[id] + x * pr;

  for(unsigned i = 0; i < j.size(); ++i) {
    if((int)i == id) continue;
    double a = (sc - j[i]) / x;
    if(a > 0) cnt += a;
  }

  return cnt > 1;
}

double solve(int id) {
  double le = 0, ri = 1, res = 1, mi;

  while(ri - le >= eps) {
    mi = (le + ri) / 2;
    if(valid(id, mi)) res = mi, ri = mi - eps;
    else le = mi + eps;
  }

  return res;
}

void solve() {
  for(unsigned i = 0; i < j.size(); ++i) {
    r.push_back(solve(i));
  }
}

void write(int t) {
  printf("Case #%d: ", t);
  for(unsigned i = 0; i < r.size(); ++i) {
    printf("%lf ", r[i] * 100);
  }
  printf("\n");
}

int main() {
  freopen(infile, "r", stdin);
  freopen(outfile, "w", stdout);

  int t;
  scanf("%d", &t);

  for(int test = 1; test <= t; ++test) {
    read();
    solve();
    write(test);
  }

  fclose(stdin);
  fclose(stdout);
  return 0;
}
