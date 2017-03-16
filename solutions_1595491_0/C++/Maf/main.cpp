#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>


using namespace std;

int main(int argc, char *argv[])
{
  int T, N, S, p;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) {
    scanf("%d%d%d", &N, &S, &p);

    int normal_bound = max(p, 3*p-2);
    int supris_bound = max(p, 3*p-4);

    //printf("p = %d, normal_bound = %d, supris_bound = %d\n", p, normal_bound, supris_bound);

    int result = 0;

    for (int j = 0; j < N; ++j) {
      int t;
      scanf("%d", &t);
      if(t >= normal_bound) {
	++result;
      } else if(t >= supris_bound && S) {
	++result;
	--S;
      }
    }

    printf("Case #%d: %d\n", i+1, result);

  }
  return 0;
}
