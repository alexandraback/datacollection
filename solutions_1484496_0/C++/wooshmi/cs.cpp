#include <cstdio>
#include <vector>

using namespace std;

const int kMaxN = 100;

int SA, SB, N, v[kMaxN];

vector <int> A, B, rA, rB;

bool ok;

void read() {
  scanf("%d", &N);

  for (int i = 1; i <= N; ++i)
    scanf("%d", &v[i]);
}

void back(int pos) {
  if (pos > N) {
    if (SA == SB) {
      ok = 1;
      rA = A;
      rB = B;
      ok = 1;
    }
    return;
  }

  if (!ok) {
    A.push_back(v[pos]);
    SA += v[pos];
    back(pos + 1);
    A.pop_back();
    SA -= v[pos];
  }

  if (!ok) {
    B.push_back(v[pos]);
    SB += v[pos];
    back(pos + 1);
    B.pop_back();
    SB -= v[pos];
  }

  if (!ok)
    back(pos + 1);
}

void afis() {
  if (ok == 0) {
    printf("Impossible\n");
    return;
  }
  
  for (int i = 0; i < rA.size(); ++i)
    printf("%d ", rA[i]);
  printf("\n");

  for (int i = 0; i < rB.size(); ++i)
    printf("%d ", rB[i]);
  printf("\n");
}

int main() {
  freopen("file.in", "r", stdin);
  freopen("file.out", "w", stdout);

  int T;

  scanf("%d", &T);

  for (int i = 1; i <= T; ++i) {
    read();

    SA = SB = 0;
    ok = 0;
    back(1);

    printf("Case #%d:\n", i);
    afis();
  }

  return 0;
}
