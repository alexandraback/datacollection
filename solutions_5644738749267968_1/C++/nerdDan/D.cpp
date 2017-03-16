#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<vector>

using namespace std;

int n;
//double a[1000], b[1000];
vector<double> a, b;

int f0() {
  auto l = b.begin(), r = b.end()-1;
  int res = 0;
  for(auto i = a.begin(); i < a.end(); i++)
    if(*i < *l)
      r--;
    else {
      l++;
      res++;
    }
  return res;
}

int f1() {
  int res = 0;
  for(auto i = a.begin(); i < a.end(); i++) {
    auto j = lower_bound(b.begin(), b.end(), *i);
    if(j!=b.end()) {
      b.erase(j);
    } else {
      b.erase(b.begin());
      res++;
    }
  }
  return res;
}

int main() {
  int nCase;
  scanf("%d", &nCase);
  for(int iCase = 1; iCase <= nCase; iCase++) {
    printf("Case #%d: ", iCase);
    scanf("%d", &n);
    a.assign(n, 0);
    b.assign(n, 0);
    for(int i = 0; i < n; i++)
      scanf("%lf", &a[i]);
    for(int i = 0; i < n; i++)
      scanf("%lf", &b[i]);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // for(int i = 0; i < n; i++)
    //   printf("%lf ", a[i]);
    // puts("");
    // for(int i = 0; i < n; i++)
    //   printf("%lf ", b[i]);
    // puts("");
    printf("%d %d\n", f0(), f1());

  }
  return 0;
}
