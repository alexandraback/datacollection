#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "../../../courses/clib/data_types/linked_list.h"
#include <stdbool.h>

int num_digits(int n) {
  int c;
  c=0;
  if (n==0) {return 1;}
  while (n != 0) { n /= 10; c++;}
  return c;
}

int wrap_num(int n, int i) {
  int units;
  int divisor;
  int digits;
  digits = num_digits(n);
  divisor = pow(10, i);
  units = n % divisor;
  return pow(10, digits-i) * units + n / divisor;
}

bool exists_already(struct LL_el *recycled_nums, int x) {
  struct LL_el *el;

  for (el = recycled_nums; el != NULL; el = el->next) {
    if (x == *((int *) el->data)) {return true; }
  }
  return false;
}

int num_recycled_pairs(int n, int b) {
  int digits, i;
  int wrapped;
  int count;
  int *stable_int;
  struct LL_el *recycled_nums;

  recycled_nums = LL_create();

  count = 0;
  digits = num_digits(n);
  for(i = 1; i < digits; i++) {
    wrapped = wrap_num(n, i);
    if ((wrapped > n) && (wrapped <= b)) { 
      if (!exists_already(recycled_nums, wrapped)) {
	stable_int = malloc(sizeof(int));
	*stable_int = wrapped;
	LL_push(stable_int, &recycled_nums, front);
      }
    }
  }
  
  return LL_len(recycled_nums);
}

int one_test_case(FILE *f) {
  int a, b, i, count, n;
  fscanf(f, "%d", &a);
  fscanf(f, "%d", &b);
  count = 0;
  for (i=a; i < b; i++) {
    n = num_recycled_pairs(i, b);
    count += n;
  }
  return count;
}

void print_rotated_numbers(int n) {
  int digits, i;
  digits = num_digits(n);
  printf("%d -> ", n);
  for(i=1; i < digits; i++) {
    printf("%d, ", wrap_num(n, i));
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  int i;
  FILE *f;
  int n;
  f = fopen(argv[1], "r");
  assert(f != NULL);
  
  fscanf(f, "%d", &n);
  for (i=0; i < n; i++) {
    printf("Case #%d: %d\n", i+1, one_test_case(f));
  }
  return 0;
}
