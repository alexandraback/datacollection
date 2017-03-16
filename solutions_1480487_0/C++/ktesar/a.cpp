#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <ctime>

#define FOR(i, m, n) for (int i=m; i<n; i++)

using namespace std;

int N, X;
vector<int> body;
int nula;

double hledej(int i) {
  /*if (body[i]==0) {
    if (nula==1) return 1.0;
    else return 0.0;
  }*/
  double l = 0.0; double r = 1.0;
  while (l<r) {
    double h = (l+r)/2.0;
    double my = body[i] + X*h;
    double celkem = h;
    FOR (j, 0, N) {
      if (j!=i) {
        double q = (double)(my - body[j])/(double)X;
        if (q>=0.0) celkem += q;
      }
    }
    if (celkem > 1.0) {
      r = h;
    }
    else l = h;
    if (l+1.0E-10 >= r || celkem==1.0) return h;
  }
  return l;
}

void solve() {
  nula = 0;
  body.clear();
  X = 0;
  scanf("%d", &N);
  FOR (i, 0, N) {
    int x; scanf("%d", &x);
    body.push_back(x);
    X += x;
    if (x==0) nula++;
  }
  FOR (i, 0, N)
    printf("%lf ", hledej(i)*100.0);
}

int main()
{
  int t; scanf("%d", &t);
  FOR (i, 0, t) {
    printf("Case #%d: ", i+1);
    solve();
    printf("\n");
  }
  return 0;
}
