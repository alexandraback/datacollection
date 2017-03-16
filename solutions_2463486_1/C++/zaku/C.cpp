#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define SZ(v) ((int)(v).size())

#ifdef __linux__
#define FMT "%lld"
#else
#define FMT "%I64d"
#endif

typedef long long LL;

const int kMaxN = 10000001;

bool isp[kMaxN];
bool isf[kMaxN];
vector<LL> far;

int ispar(LL num)
{
  static int a[1024];
  int len = 0;
  for (; num; num /= 10) a[len++] = num%10;
  for (int l = 0, r = len-1; l < r; ++l, --r)
    if (a[l] != a[r]) return 0;
  return 1;
}

void pre()
{
  for (int i = 1; i < kMaxN; ++i) isp[i] = ispar(i);

  far.clear();
  for (int i = 1; i < kMaxN; ++i) {
    if (!isp[i]) continue;
    isf[i] = ispar((LL)i*(LL)i);
    if (isf[i]) far.push_back(i);
  }

  // for (int i = 0; i < SZ(far); ++i) 
  //   printf("%d ", far[i]);
  // puts("");
}

void solve()
{
  LL A, B;
  scanf(FMT FMT, &A, &B);

  LL result = 0;
  for (int i = 0; i < SZ(far); ++i) {
    LL tmp = far[i] * far[i];
    if (A <= tmp && tmp <= B) ++result;
  }
  
  printf(FMT "\n", result);
}

int main()
{
  pre();
  int t;
  scanf("%d", &t);
  for (int l = 1; l <= t; ++l) {
    printf("Case #%d: ", l);
    solve();
  }
  return 0;
}
