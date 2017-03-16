#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {

  int T;
  int A, B, K;

  scanf("%d", &T);

  for(int t=1; t<=T; t++) {

    //Read info
    scanf("%d %d %d", &A, &B, &K);

    int solution = 0;

    for(int i=0; i<A; i++)
      for(int j=0; j<B; j++)
	if( (i & j) < K )
	  solution++;

    printf("Case #%d: %d\n", t, solution);
  }

  return 0;
}
