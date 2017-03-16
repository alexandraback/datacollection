
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXN = 3, MAXM = 100;
int N, M;

ll a[MAXN], b[MAXM];
int A[MAXN], B[MAXM];

ll ans;

void solve(int ii, int jj, ll ii_used, ll jj_used, ll value)
{
  if (ii == N || jj == M)
  {
    ans = max(ans, value);
    return;
  }
  if (A[ii] == B[jj])
  {
    ll ai = a[ii]-ii_used, bj = b[jj]-jj_used;
    ll m = min(ai, bj);
    solve(ii+1, jj+1, 0, 0, value+m);
    solve(ii+1, jj, 0, jj_used+m, value+m);
    solve(ii, jj+1, ii_used+m, 0, value+m);

  }
  else
  {
    solve(ii+1, jj, 0, jj_used, value);
    solve(ii, jj+1, ii_used, 0, value);
    solve(ii+1, jj+1, 0, 0, value);
  }
}

int main()
{
  int T;
  scanf("%d", &T);

  for (int case_id = 1; case_id <= T; case_id++)
  {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    ans = 0;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
      scanf("%lld %d", &a[i], &A[i]);
    for (int i = 0; i < M; i++)
      scanf("%lld %d", &b[i], &B[i]);
    solve(0, 0, 0, 0, 0);
    printf("Case #%d: %lld\n", case_id, ans);
  }
}
