#include <cstdio>
#include <map>
#include <vector>
using namespace std;

const int MAXN = 550;

int n;
int A[MAXN];
map< int, vector< int > > M;

int check(const vector< int > &V, int x) {
  for (auto v : V) {
    if ((v & x) == 0) {
      return v;
    }
  }
  return 0;
}

void pisi(int x) {
  for (int i = 0; i < n; ++i) {
    if (x & (1<<i)) {
      printf("%d ", A[i]);
    }
  }
  printf("\n");
}

int main() {
  int numCases = 1;
  scanf("%d", &numCases);
  for (int caseIt = 0; caseIt < numCases; ++caseIt) {
    printf("Case #%d:\n", caseIt+1);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &A[i]);
    }

    M.clear();
    for (int i = 1; i < (1<<n); ++i) {
      int sum = 0;
      for (int j = 0; j < n; ++j) {
        if (i & (1<<j)) {
          sum += A[j];
        }
      }
      int c = check(M[sum], i);
      if (c) {
        pisi(c);
        pisi(i);
        break;
      }
      M[sum].push_back(i);
    }

  }

  return 0;
}

