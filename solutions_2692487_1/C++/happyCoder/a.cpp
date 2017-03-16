#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned long long ullong;
typedef long long llong;
typedef unsigned long ulong;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

void solve() {
  int a, n;
  scanf("%i%i", &a, &n);
  int *motes = new int[n];
  for (int i = 0; i < n; ++i) {
    scanf("%i", &motes[i]);
  }
  if (a == 1) {
    printf("%d\n", n);
    return;
  }
  sort(motes, motes+n);
  int minOps = -1;
  for (int i = 0; i <= n; ++i) {
    int ca = a;
    int ops = i;
    for (int j = 0; j < n-i; ++j) {
      while (ca <= motes[j]) {
	ca += ca-1;
	++ops;
      }
      ca += motes[j];
    }
    if (minOps == -1 || ops < minOps) {
      minOps = ops;
    }
  }
  printf("%d\n", minOps);
}

int main() {
  int numC;
  scanf("%i", &numC);
  for (int i = 1; i <= numC; ++i) {
    printf("Case #%i: ", i);
    solve();
  }
}