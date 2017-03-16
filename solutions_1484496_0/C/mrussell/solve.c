#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "linked_list.h"
#include <stdbool.h>

#define SET_LENGTH 20
#define NUM_SETS 1048576

struct subset {
  int number;
  int sum;
};

struct subset *subset_of_int(int number, struct LL_el *full_set) {
  int x;
  int element;
  int sum;
  sum=0;
  for(x = SET_LENGTH-1; x>=0; x--) {
    if((number & (1 << x)) != 0) {
      element = * ((int *) LL_nth(full_set, x));
      sum += element;
    }
  }
  
  struct subset *s;
  s = malloc(sizeof(struct subset));
  assert(s != NULL);
  s->number = number;
  s->sum = sum;
  return s;
}

void print_subset(struct subset *s, struct LL_el *full_set) {
  int x;
  int element;
  for(x = SET_LENGTH-1; x>=0; x--) {
    if((s->number & (1 << x)) != 0) {
      element = * ((int *) LL_nth(full_set, x));
      printf("%d ", element);
    }
  }
}

bool search_for_sum(struct subset *s, struct LL_el *subset_list, struct LL_el *full_set) {
  struct LL_el *el;
  struct subset *s1;
  for (el = subset_list; el != NULL; el = el->next) {
    s1 = el->data;
    if (s->sum == s1->sum) {
      print_subset(s1, full_set);
      printf("\n");
      print_subset(s, full_set);
      printf("\n");
      return true;
    }
  }
  return false;
}

void print_int(void *i) {
  printf("%d ", *(int *) i);
}
void print_set(struct LL_el *l) {
  LL_iter(l, print_int);
  printf("\n");
}
void one_test_case(FILE *f) {
  int n, *x, i;
  struct LL_el *full_set;
  full_set = LL_create();
  fscanf(f, "%d", &n);
  assert(n==SET_LENGTH);
  
  for (i=0; i<n; i++) {
    x = malloc(sizeof(int));
    fscanf(f, "%d", x);
    LL_push(x, &full_set, back);
  }

  struct subset *s;
  struct LL_el *subset_list;
  subset_list = LL_create();
  for (i=1; i<NUM_SETS; i++) {
    s = subset_of_int(i, full_set);
    if (search_for_sum(s, subset_list, full_set)) {
      return;
    }
    else {
      LL_push(s, &subset_list, front);
    }
  }
  printf("impossible\n");
}

int main(int argc, char *argv[]) {
  int i;
  FILE *f;
  int n;
  f = fopen(argv[1], "r");
  assert(f != NULL);
  
  fscanf(f, "%d", &n);
  for (i=0; i < n; i++) {
    printf("Case #%d:\n", i+1);
    one_test_case(f);
  }
  return 0;
}
