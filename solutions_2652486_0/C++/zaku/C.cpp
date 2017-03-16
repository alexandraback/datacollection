#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define SZ(v) ((int)(v).size())

typedef long long LL;

#ifdef __linux__
#define FMT "%lld"
#else
#define FMT "%I64d"
#endif

const int kMaxN = 10010;
const int kMaxM = 20;

int n, m, k, R;
int V[kMaxN][kMaxM];

int check(int num[], int r)
{
  static int vis[kMaxN] = {0}, ti = 0;
  ++ti;
  
  vis[1] = ti;
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      for (int l = 0; l < 2; ++l) {
	vis[(i ? 1 : num[0]) * (j ? 1 : num[1]) * (l ? 1 :num[2])] = ti;
      }

  int cnt = 0;
  for (int j = 0; j < k; ++j) {
    cnt += vis[V[r][j]] == ti;
  }

  return cnt == k;
}

void solve()
{
  int tmp[3], flag;

  for (int r = 0; r < R; ) {

    flag = 0;
    for (int i = 2; i <= 5; ++i)
      for (int j = 2; j <= 5; ++j)
	for (int l = 2; l <= 5; ++l) {
	  tmp[0] = i; tmp[1] = j; tmp[2] = l;
	  if (check(tmp, r)) {
	    flag = 1;
	    for (int i = 0; i < 3; ++i) printf("%d", tmp[i]);
	    puts("");
	    goto HHH;
	  }
      }
  HHH:
    ++r;
    if (flag == 0) puts("222");
  }

}

int main()
{
  int t;
  scanf("%d", &t);
  for (int l = 1; l <= t; ++l) {
    scanf("%d%d%d%d", &R, &n, &m, &k);
    for (int i = 0; i < R; ++i)
      for (int j = 0; j < k; ++j) scanf("%d", V[i] + j);

    printf("Case #%d:\n", l);
    solve();
  }
  return 0;
}

