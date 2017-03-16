#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <set>
#include <map>

#define fr(i,n) for(i=0;i<(int)(n);i++)
#define fit(a,b) for(typeof(b.begin()) a = b.begin(); a != b.end(); a++)
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define SZ(u) ((int)u.size())
#define WT(x) cout << #x << ": " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int,int> p2;
typedef vector<int> vi;

int N, A[1000], B[1000], Star[1000];
int main() {
  int tc, cn = 0, i;
  scanf("%d", &tc);
  while (cn++ < tc) {
    scanf("%d", &N);
    fr (i, N) {
      scanf("%d%d", &A[i], &B[i]);
      Star[i] = 0;
    }

    int res = 0, star = 0;
    while (star < 2 * N) {
      int next_idx = -1, plus = 0;
      fr (i, N) if (Star[i] != 2) {
        if (B[i] <= star) next_idx = i, plus = 2;
        else if (Star[i] == 0 && A[i] <= star) {
          if (next_idx == -1 || (plus == 1 && B[next_idx] < B[i])) {
            next_idx = i, plus = 1;
          }
        }
      }

      if (next_idx == -1) break;
      res++;
      star += plus - Star[next_idx];
      Star[next_idx] = plus;
    }

    if (star < 2 * N) {
      printf("Case #%d: Too Bad\n", cn);
    } else {
      printf("Case #%d: %d\n", cn, res);
    }
  }

  return 0;
}
