#include <stdio.h>
#include <assert.h>

typedef int bool;
#define false 0
#define true 1

typedef enum TableField
{
  FIELD_EMPTY,
  FIELD_MINE,
  FIELD_START,
  FIELD_VISITED
} TableField;

void printTable(const int nr, const int nc, TableField table[][5])
{
  for (int r = 0; r < nr; ++r) {
    for (int c = 0; c < nc; ++c) {
      switch(table[r][c]) {
        case FIELD_EMPTY  : putchar(' '); break;
        case FIELD_MINE   : putchar('*'); break;
        case FIELD_START  : putchar('c'); break;
        case FIELD_VISITED: putchar('.'); break;
        default: putchar('?'); break;
      }
    }
    putchar('\n');
  }
}

int dirr[] = {-1, -1, -1,  0,  0,  1,  1,  1};
int dirc[] = {-1,  0,  1, -1,  1, -1,  0,  1};

/**
 * @return false if a field has a mine next to it
 */
inline bool isFlooding(const int r, const int c, const int nr, const int nc, TableField table[][5])
{
  for (int i = 0; i < 8; ++i) {
    int checkr = r + dirr[i];
    if (checkr <   0) { continue; }
    if (checkr >= nr) { continue; }
    int checkc = c + dirc[i];
    if (checkc <   0) { continue; }
    if (checkc >= nc) { continue; }
    if (FIELD_MINE == table[checkr][checkc]) {
      return false;
    }
  }

  return true;
}

void flood(const int r, const int c, const int nr, const int nc, TableField table[][5])
{
  if (FIELD_START != table[r][c]) {
    assert(FIELD_EMPTY == table[r][c]);
    table[r][c] = FIELD_VISITED;
  }

  if (isFlooding(r, c, nr, nc, table)) {
    for (int i = 0; i < 8; ++i) {
      int checkr = r + dirr[i];
      if (checkr <   0) { continue; }
      if (checkr >= nr) { continue; }
      int checkc = c + dirc[i];
      if (checkc <   0) { continue; }
      if (checkc >= nc) { continue; }
      if (FIELD_EMPTY == table[checkr][checkc]) {
        flood(checkr, checkc, nr, nc, table);
      }
    }
  }

}

void solve(int nr, int nc, int m)
{
  for (int i = 0; i < (1 << nr*nc); ++i)
  {
    if (m == __builtin_popcount(i)) {
      for (int cr = 0; cr < nr; ++cr) {
        for (int cc = 0; cc < nc; ++cc) {

          //do not start on bomb
          if (i & (1 << (cr*nc+cc))) continue;

          TableField table[5][5];
          for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
              table[r][c] = i & (1 << (r*nc+c)) ? FIELD_MINE : FIELD_EMPTY;
            }
          }

          table[cr][cc] = FIELD_START;
          flood(cr, cc, nr, nc, table);

          bool success = 1;
          for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
              if (FIELD_EMPTY == table[r][c]) success = false;
            }
          }

          if (success) {
            printTable(nr, nc, table);
            return;
          }
        }
      }
    }
  }
  printf("Impossible\n");
}

int main()
{
  int tn = -1;
  scanf("%d", &tn);
  if (-1 == tn) {
    printf("Error reading number of test cases\n");
    return 1;
  }

  for (int ti = 0; ti < tn; ++ti)
  {
    int r, c, m;
    scanf("%d %d %d", &r, &c, &m);
    fprintf(stderr, "Solving %d %d %d\n", r, c, m);

    printf("Case #%d:\n", ti+1);

    solve(r, c, m);
  }

  return 0;
}

