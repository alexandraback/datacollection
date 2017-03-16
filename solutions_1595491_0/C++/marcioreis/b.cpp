/*
  codejam 2012
  marcioreis
*/

#include <iostream>
#include <stdio.h>

using namespace std;

int main () {
  int t;
  int caso = 1;
  int res;
  int n, super, limite, nota, maximo;
  
  scanf (" %d", &t);
  while (t--) {
    res = 0;
    scanf (" %d %d %d", &n, &super, &limite);
    while (n--) {
      scanf (" %d", &nota);
      maximo = nota - (nota/3) - ((nota-nota/3)/2);
      if (maximo >= limite) {
        res++;
      }
      else if ((nota > 1) && (super > 0) && ((nota - 1) % 3) && (maximo + 1 >= limite)) {
        res++;
        super--;
      }
    }
    printf ("Case #%d: %d\n", caso++, res);
  }
  return 0;
}

