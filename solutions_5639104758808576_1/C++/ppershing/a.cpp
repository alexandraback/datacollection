#include <stdio.h>
#define FOR(x, n) for (int x=0; x<n; x++)

#define MAX 1010

void solve(int testcase) {
  int shyness[MAX];
  int levels;
  scanf("%d", &levels);
  levels++;
  FOR(i, levels)
    scanf("%1d", &shyness[i]);

  int standing = 0;
  int add = 0;
  FOR(i, levels) {
    FOR(j, shyness[i]) {
      //printf("level %d (person %d), standing %d\n", i, j, standing);
      while (standing < i) {
        standing++;
        add++;
      }
      standing++;
    }
  }

  printf("Case #%d: %d\n", testcase + 1, add);
}


int main() {
  int T;
  scanf("%d", &T);
  FOR(i, T) solve(i);

}
