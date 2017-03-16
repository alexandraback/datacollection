#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "helper.h"

using namespace std;


// static const char *sentence[] = {

// };


unsigned gain;
unsigned max_gain;

void process(unsigned *tab, unsigned size, unsigned E, unsigned R,
            unsigned E_left, unsigned indice)
{
  if (indice == 0)
    gain = 0;

  if (indice == size) {
    if (gain > max_gain)
      max_gain = gain;
    return;
  }

  for (unsigned i = 0; i <= E_left; i++) {
    gain += i * tab[indice];
    unsigned e_tmp = E_left - i + R;
    process(tab, size, E, R, (e_tmp > E)? E: e_tmp, indice + 1);
    gain -= i * tab[indice];
  }
}

int main()
{
  unsigned nb_case;
  r1int(&nb_case);
  for (unsigned i = 0; i < nb_case; i++) {
    /* Parse ith case */

    unsigned E, R, N;
    unsigned *tab;
    r3int(&E, &R, &N);
    newtabint(&tab, 1, N);

    max_gain = 0;

    // for (int j = 0; j < N; j++)
    //   printf("%d ", tab[j]);


    /* Process and display */
    process(tab, N, E, R, E, 0);
    printf("Case #%d: %d", i + 1, max_gain);

    printf("\n");
  }

  return EXIT_SUCCESS;
}
