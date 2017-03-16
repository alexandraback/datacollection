
#include <numeric>
#include <cstdio>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  int Z;
  scanf("%d", &Z);
  for (int z=1;z<=Z;z++) {
    printf("Case #%d: ", z);
    int n;
    scanf("%d", &n);
    if (!n) printf("INSOMNIA\n");
    else {
      vector<int> dig(10, 0);
      int d = n;
      for(;accumulate(dig.begin(), dig.end(), 0) != 10;n+=d) {
        int k = n;
        while (k) {
          dig[k % 10] = 1;
          k /= 10;
        }
      }
      printf("%d\n", n - d);
    }
  }
  return 0;
}
