#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

const int maxn = 100;
struct node {
  int d, h, m;
} a[maxn];
int n;

int calc(double s1, double v1, double s2, double v2) {
  if (v1 == v2) return 0;
  if (s1 < s2) {
    swap(s1, s2);
    swap(v1, v2);
  }
  if (v1 < v2) {
    if ((360.0 - s1) / v1 < (720.0 - s2) / v2) return 0;
  } else {
    double gap_t = (s2 - s1) / (v1 - v2);
    if (gap_t >= (360.0 - s1) / v1) return 0;
    s1 += gap_t * v1;
    s2 += gap_t * v2;
    if ((360.0 - s2) / v2 < (720.0 - s1) / v1) return 0;
  }
  return 1;
}

int go() {
  if (n < 1 || (n == 1 && a[1].h == 1)) return 0;
  double s1 = a[1].d, v1 = 360.0 / a[1].m, s2, v2;
  if (n == 1) {
    s2 = a[1].d, v2 = 360.0 / (a[1].m + 1);
  } else {
    s2 = a[2].d, v2 = 360.0 / a[2].m;
  }
  return calc(s1, v1, s2, v2);
}


int main()
{
  freopen("C-small-1-attempt0.in", "r", stdin);
  freopen("C_small.out", "w", stdout);
  int TextN;
  cin >> TextN;
  for (int TT = 1; TT <= TextN; TT++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].d >> a[i].h >> a[i].m; 
    }
    cout << "Case " << "#" << TT << ": " << go() << endl;
  }
  return 0;
}