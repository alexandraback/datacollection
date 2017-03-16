#include <cstdio>
#include <cmath>
#include <set>

using namespace std;

int last_added[2000001];
unsigned long long recycle_bin[2000001];

int main(int argc, char *argv[])
{
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {

    int A, B;
    scanf("%d%d", &A, &B);

    int mul = 1, B2 = B, digits = 1;
    while(B2 /= 10) {
      mul *= 10;
      ++digits;
    }
    //printf("mul: %d, digits: %d\n", mul, digits);

    unsigned long long count = 0;
    for (int n = A; n <= B; ++n) {
      count += recycle_bin[n];

      //printf("Shifts for %d:\n", n);
      int n2 = n;
      for (int i = 0; i < digits; ++i) {

	n2 = (n2 / 10) + (n2 % 10) * mul;

	if(n2 <=n) continue;
	if(n2 > B) continue;
	if(last_added[n2] == n) continue;

	//printf("  %d\n", n2);
	++recycle_bin[n2];
	last_added[n2] = n;
      }

    }

    printf("Case #%d: %llu\n", t+1, count);

    for (int n = A; n <= B; ++n) {
      recycle_bin[n] = 0ull;
      last_added[n] = -1;
    }

  }

  return 0;
}
