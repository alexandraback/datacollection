#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int K, N;
int keys[201], need[201];
int table[1 << 20];
int inside[201][201];
int ptable[1 << 20];

int main() {
  int T;
  scanf("%d", &T);

  for (int cn = 1; cn <= T; ++cn) {
    scanf("%d%d", &K, &N);
    memset(keys, 0, sizeof(keys));
    memset(table, 0, sizeof(table));
    memset(inside, 0, sizeof(inside));
    memset(ptable, 0, sizeof(ptable));

    for (int i = 0; i < K; ++i) {
      int k;
      scanf("%d", &k); k--;
      keys[k]++;
    }
    for (int i = 0; i < N; ++i) {
      scanf("%d", &need[i]); need[i]--;
      int k;
      scanf("%d", &k);
      for (int j = 0; j < k; ++j) {
	int c;
	scanf("%d", &c); c--;
	inside[i][c]++;
      }
    }
    table[0] = 1;
    for (int bit = 0; bit < (1 << N) - 1; ++bit) {
      if (!table[bit]) continue;

      for (int i = 0; i < N; ++i) {
	if (bit & (1 << i)) continue;
	// 현재 bit 에서 i번째 상자를 열고 싶다!
	int nk = keys[need[i]];
	for (int j = 0; j < N; ++j) {
	  if (bit & (1 << j)) {
	    nk += inside[j][need[i]];
	    if (need[j] == need[i]) nk--;
	  }
	}
	if (nk >= 1) {
	  table[bit | (1 << i)] = 1;
	}
      }
    }

    if (table[(1 << N) - 1]) {
      ptable[(1 << N) - 1] = 1;
      for (int bit = (1 << N) - 1; bit >= 0; --bit) {
	if (!ptable[bit]) continue;

	for (int i = 0; i < N; ++i) {
	  if (bit & (1 << i)) {
	    // 현재 bit에서 i번째 상자가 없어도 현재 bit로 올 수 있는가?
	    int cbit = bit - (1 << i);
	    if (!table[cbit]) continue;


	    int nk = keys[need[i]];
	    for (int j = 0; j < N; ++j) {
	      if (cbit & (1 << j)) {
		nk += inside[j][need[i]];
		if (need[j] == need[i]) nk--;
	      }
	    }
	    if (nk >= 1) {
	      ptable[cbit] |= (1 << i);
	      //printf("%d -> %d\n", cbit, bit);
	    }
	  }
	}
      }

      int sbit = 0;
      printf("Case #%d:", cn);
      for (int i = 0; i < N; ++i) {
	for (int j = 0; j < N; ++j) {
	  if (sbit & (1 << j)) continue;
	  if (ptable[sbit] & (1 << j)) { //sbit + (1 << j)]) {
	    printf(" %d", j + 1);
	    sbit |= (1 << j);
	    break;
	  }
	}
      }
      printf("\n");
    } else {
      printf("Case #%d: IMPOSSIBLE\n", cn);
    }
  }
}
