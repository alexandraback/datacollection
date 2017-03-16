#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define MAXN 10005
using namespace std;

typedef long long int LL;
int testcase;
LL N, K, t1, t2, t3, t4;
bool ok;
int G[8][8], tmp; //1, i, j, k, -1, -i, -j, -k
int A[MAXN], F[MAXN], B[MAXN];
map <char,int> get_id;

int cal(int x, LL p) {
  if (p == 0) return 0;
  if (p % 2ll == 1ll) return G[x][cal(x,p-1)];
  int t = cal(x,p/2ll);
  return G[t][t];
}

int main () {
  freopen("C-small-attempt0.in","r",stdin);
  freopen("C.out","w",stdout);
  for (int i=0;i<7;++i) G[0][i] = G[i][0] = i;
  G[1][1] = 4; G[1][2] = 3; G[1][3] = 6;
  G[2][1] = 7; G[2][2] = 4; G[2][3] = 1;
  G[3][1] = 2; G[3][2] = 5; G[3][3] = 4;
  for (int i=0;i<4;++i)
    for (int j=0;j<4;++j) {
      if (G[i][j] < 4) G[i+4][j] = G[i][j+4] = G[i][j] + 4;
      else G[i+4][j] = G[i][j+4] = G[i][j] - 4;
      G[i+4][j+4] = G[i][j];
    }
  get_id['i'] = 1;
  get_id['j'] = 2;
  get_id['k'] = 3;
  //for (int i=0;i<8;++i,printf("\n"))
    //for (int j=0;j<8;++j) printf("%d ",G[i][j]);
  //cout << G[7][2] << endl;
  scanf("%d",&testcase);
  for (int TC=1;TC<=testcase;++TC) {
    cin >> N >> K;
    for (int i=1;i<=N;++i) {
      char c;
      scanf(" %c",&c);
      A[i] = get_id[c];
    }
    F[0] = B[N+1] = 0;
    for (int i=1;i<=N;++i) F[i] = G[F[i-1]][A[i]];
    for (int i=N;i>=1;--i) B[i] = G[A[i]][B[i+1]];
  //  for (int i=1;i<=N;++i) printf("%d ",F[i]); printf("\n");
  //  for (int i=1;i<=N;++i) printf("%d ",B[i]); printf("\n"); 
    if (cal(F[N],K) != 4) {
    //  cout << cal(F[N],0) << " " << cal(F[N],1) << endl;
    //  printf("FAIL %d\n",cal(F[N],K));
      goto end;
    }
    t1 = t2 = t3 = t4 = -1;
    tmp = 0;
    ok = 0;
    for (int i=0;!ok && i<=5;++i)
      for (int j=1;j<=N;++j) {
        tmp = G[tmp][A[j]];
        if (tmp == 1) {
          t1 = i, t2 = j;
          ok = 1;
          break;
        }
      }
    tmp = 0;
    ok = 0;
    for (int i=0;!ok && i<=5;++i)
      for (int j=N;j>=1;--j) {
        tmp = G[A[j]][tmp];
        if (tmp == 3) {
          t3 = i, t4 = N-j+1;
          ok = 1;
          break;
        }
      }
  //  printf("(%lld,%lld,%lld,%lld)\n",t1,t2,t3,t4);
    if (t1 >= 0 && t2 >= 0 && t3 >= 0 && t4 >= 0 && (t1+t3) * N + t2 + t4 < N * K) {
      printf("Case #%d: YES\n",TC);
      continue;
    }
    end:;
    printf("Case #%d: NO\n",TC);
  }
}
