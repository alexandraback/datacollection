#include <iostream>
#include <algorithm>
using namespace std;

void one_step(int *a, int *start, int *end, int motes[]) {
  if (*a > motes[*start]) {
    // printf("eating %d\n", motes[*start]);
    *a += motes[*start];
    *start += 1;
  }
}

int run(int a, int motes[], int start, int end) {
  int i;
  int num_ops = 0;
  while(true) {
    int cstart = start;
    int cend = end;
    one_step(&a, &start, &end, motes);
    if (start == end) {
      // printf("finished\n");
      break;
    } else if (cstart == start && cend == end) {
      // printf("dunno what to do -> branching\n"); 
      /* Two options: 
	 1.  Remove largest
	 2.  Add mote of size (a-1) if (a-1) > 0
      */
      num_ops += 1;
      int num_ops_removing = run(a, motes, start, end-1);
      if (a > 1) {
	int num_ops_adding = run(2*a-1, motes, start, end);
	if (num_ops_adding > num_ops_removing)
	  num_ops += num_ops_removing;
	else 
	  num_ops += num_ops_adding;
      }
      else 
	num_ops += num_ops_removing;

      break;
    } 
  }
  return num_ops;
}

void handle_input(int t) {
  int i, a, n;
  scanf("%d %d", &a, &n);
  int motes[n];
  for (i=0; i < n; i++) 
    scanf("%d", &motes[i]);
  sort(motes,motes+n);

  // print
  /*
  printf("a: %d, n: %d, motes: ", a, n);
  for (int i = 0; i < n; i++)
    printf("%d ", motes[i]);
  printf("\n");
  */

  int start=0;
  int end = n;
  int num_ops = run(a, motes, start, end);
  printf("Case #%d: %d\n", t, num_ops);
}

int main() {
  int t, T; scanf("%d", &T);
  // printf("T:%d\n", T);
  for (t=1; t <= T; t++) {
    handle_input(t);
  }
  return 0;
}
