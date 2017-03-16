#include <cstdio>
#include <cstring>

//#define SMALL
#define LARGE

int T;
int nums[27], ans[10];
char inp[2001];

void del(const char* c) {
  for (int i = 0; c[i]; ++i)
    --nums[c[i] - 'A'];
}

int main()
{
#ifdef SMALL
  freopen("A-small.in", "r", stdin);
  freopen("A-small.out", "w", stdout);
#endif

#ifdef LARGE
  freopen("A-large.in", "r", stdin);
  freopen("A-large.out", "w", stdout);
#endif

  scanf("%d", &T);
  for (int Case = 1; Case <= T; ++Case) {
    scanf("%s", inp);
    memset(nums, 0, sizeof(nums));
    memset(ans, 0, sizeof(ans));
    for (int i = 0; inp[i]; ++i)
      ++nums[inp[i] - 'A'];
    printf("Case #%d: ", Case);
    while (nums['Z' - 'A'] != 0) {
      del("ZERO\0");
      ++ans[0];
    }
    while (nums['X' - 'A'] != 0) {
      del("SIX\0");
      ++ans[6];
    }
    while (nums['U' - 'A'] != 0) {
      del("FOUR\0");
      ++ans[4];
    }
    while (nums['F' - 'A'] != 0) {
      del("FIVE\0");
      ++ans[5];
    }
    while (nums['G' - 'A'] != 0) {
      del("EIGHT\0");
      ++ans[8];
    }
    while (nums['H' - 'A'] != 0) {
      del("THREE\0");
      ++ans[3];
    }
    while (nums['V' - 'A'] != 0) {
      del("SEVEN\0");
      ++ans[7];
    }
    while (nums['W' - 'A'] != 0) {
      del("TWO\0");
      ++ans[2];
    }
    while (nums['O' - 'A'] != 0) {
      del("ONE\0");
      ++ans[1];
    }
    while (nums['N' - 'A'] != 0) {
      del("NINE\0");
      ++ans[9];
    }
    for (int i = 0; i < 10; ++i)
      while (ans[i]--)
        printf("%d", i);
    printf("\n");
  }
  return 0;
}
