#include <stdio.h>

#define MAXN 10000
// #define DEBUG 0

const int matrix[4][4] = {
  {0, 1, 2, 3},
  {1, 0, 3, 2},
  {2, 3, 0, 1},
  {3, 2, 1, 0}
};

const int smatrix[4][4] = {
  {1, 1, 1, 1},
  {1, -1, 1, -1},
  {1, -1, -1, 1},
  {1, 1, -1, -1}
};

struct Val {
  int val;
  int sign;
  Val(): val(0), sign(1) {
  }
  Val(int _val, int _sign) {
    val = _val;
    sign = _sign;
  }
  void print() const {
      printf("%c%c ", sign == 1 ? ' ' : '-',
          val == 0 ? '1' : val + 'i' - 1);
  }
};

struct Val table[MAXN+1][MAXN+1];
Val seg[5];

Val compute(const struct Val a, const struct Val b) {
  return Val(matrix[a.val][b.val], a.sign * b.sign * smatrix[a.val][b.val]);
}

bool verified(const Val first, const Val second, const Val third) {
#ifdef DEBUG
  printf("verifying ");
  first.print();
  second.print();
  third.print();
  printf("\n");
#endif
  return ((first.val == 1 && first.sign == 1) &&
      (second.val == 2 && second.sign == 1) &&
      (third.val == 3 && third.sign == 1));
}

bool sameSegment(int L, long long int X) {
  Val first, second, third;
  for (int ii = 0; ii <= 4; ++ii) {
    long long int remain = X - 1 - ii;
    if (remain < 0) {
      continue;
    }
    int jj = remain % 4;
    for (int i = 0; i <= L; ++i) {
      for (int j = i + 1; j <= L; ++j) {
        if ((ii == 0 && i == 0) ||
            (remain / 4 == 0 && jj == 0 && j == L)) {
          continue;
        } 
#ifdef DEBUG
        printf("ii: %d jj: %d i: %d j: %d\n", ii, jj, i, j);
#endif
        first = compute(seg[ii], table[0][i]);
        second = table[i][j];
        third = compute(table[j][L], seg[jj]);
        if (verified(first, second, third)) {
          return true;
        }
      }
    }
  }
  return false;
}

bool diffSegment(int L, long long int X) {
  Val first, second, third;
  for (int ii = 0; ii <= 4; ++ii) {
    for (int jj = 0; jj <= 4; ++jj) {
      long long int remain = X - 2 - ii - jj;
      if (remain < 0) {
        continue;
      }
      int kk = remain % 4;
      for (int i = 0; i <= L; ++i) {
        for (int j = 0; j <= L; ++j) {
          if ((ii == 0 && i == 0) ||
              (jj == 0 && i == L && j == 0) ||
              (remain/4 == 0 && kk == 0 && j == L)) {
            continue;
          }
#ifdef DEBUG
          printf("ii %d, jj %d, kk %d, i %d, j %d\n", ii, jj, kk, i, j);
#endif
          first = compute(seg[ii], table[0][i]);
          second = compute(compute(table[i][L], seg[jj]), table[0][j]);
          third = compute(table[j][L], seg[kk]);
          if (verified(first, second, third)) {
            return true;
          }
        }
      }
    }
  }
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
for (int ic=1; ic<=T; ++ic) {
  int L;
  long long int X;
  int input[MAXN + 1];
  char cinput[MAXN + 1];
  scanf("%d%lld", &L, &X);
  scanf("%s", cinput);
  for (int i = 0; i < L; ++i) {
    input[i] = cinput[i] - 'i' + 1;
  }
  for (int i = 0; i <= L; ++i) {
    table[i][i] = Val(0, 1);
    for (int j = i + 1; j <= L; ++j) {
      table[i][j] = compute(table[i][j-1], Val(input[j-1], 1));
    }
  }
#ifdef DEBUG
  for (int i = 0; i <= L; ++i) {
    for (int j = i; j <= L; ++j) {
      table[i][j].print();
    }
    printf("\n");
  }
#endif

  seg[0] = Val(0, 1);
  for (int i = 1; i <= 4; ++i) {
    seg[i] = compute(seg[i-1], table[0][L]);
  }
#ifdef DEBUG
  for (int i = 0; i <= 4; ++i) {
    seg[i].print();
  }
  printf("\n");
#endif
  printf("Case #%d: %s\n", ic,
      sameSegment(L, X) || diffSegment(L, X) ? "YES" : "NO");
}
  return 0;
}
