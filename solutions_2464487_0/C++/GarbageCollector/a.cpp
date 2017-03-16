#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "helper.h"

using namespace std;


static const char *sentence[] = {

};


unsigned long long process(unsigned long long r, unsigned long long t)
{
  unsigned long long res = 0;
  unsigned long long tot = 2 * r + 1;
  while (tot <= t) {
    r += 2;
    tot += (2 * r + 1);
    res++;

  }
  return res;
}

int main()
{
  unsigned nb_case;
  r1int(&nb_case);
  for (unsigned i = 0; i < nb_case; i++) {
    /* Parse ith case */
    unsigned long long r;
    unsigned long long t;
    r2ull(&r, &t);

    /* Data structures */

    /* Process and display */
    //printf("%lld, %lld\n", r, t);
    printf("Case #%d: %lld", i + 1, process(r, t));
    printf("\n");
  }

  return EXIT_SUCCESS;
}
