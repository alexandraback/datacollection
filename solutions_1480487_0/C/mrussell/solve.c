#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "linked_list.h"
#include <stdbool.h>


void print_int(void *i) {
  printf("%d ", *(int *) i);
}
void print_set(struct LL_el *l) {
  LL_iter(l, print_int);
  printf("\n");
}

void one_test_case(FILE *f) {
  int i;
  struct LL_el *l;
  int n;
  int x, *j;
  float p;

  fscanf(f, "%d", &n);
  
  l = LL_create();
  for(i=0; i<n;i++) {
    j = malloc(sizeof(int));
    assert(j != NULL);
    fscanf(f, "%d", j);
    LL_push(j, &l, back);
  }

  struct LL_el *el;
  x=0;
  for(el = l; el != NULL; el = el->next) {
    x+= *(int *)el->data;
  }
  
  // goal point value
  p = ((float) 2 * x) / ((float) n);
  // print out the answers  
  for(el = l; el != NULL; el = el->next) {
    j = el->data;
    printf("%.6f ", 100 * (p - ((float) *j)) / ((float) x));
  }
}

int main(int argc, char *argv[]) {
  int i;
  FILE *f;
  int n;
  f = fopen(argv[1], "r");
  assert(f != NULL);
  
  fscanf(f, "%d", &n);
  for (i=0; i < n; i++) {
    printf("Case #%d: ", i+1);
    one_test_case(f);
    printf("\n");
  }
  return 0;
}
