#include <stdio.h>
#include <string.h>


int main() {
  int t, a, b;
  int i, j, k, q, p;
  int len;
  long long tmp;
  int result;
  int shift[8] = { 0, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
  int store[8];
  scanf("%d", &t);
  for (i = 0 ; i < t ; ++i) {
	scanf("%d %d", &a, &b);
	result = 0;
	for (len = 0 , tmp = a ; tmp > 9 ; len++) {
	  tmp = tmp / 10;
	}

	for (j = a ; j <= b ; ++j) {
	  for (q = 0 ; q < len ; q++) {
		store[q] = 0;
	  }
	  tmp = j;
	  for (k = 0 ; k < len ; k++) {
		tmp = tmp  / 10 + tmp  % 10 * shift[len];
		if (tmp > j && tmp > a -1 && tmp < b + 1 ) {
		  p = 0;
		  for (q = 0 ; q < len ; q++) {
			if (tmp == store[q]) {
			  p = 1;
			  break;
			}
		  }
		  if (p == 0) {
			store[k] = tmp;
			result++;
		  }
		}
	  }
	}
	printf("Case #%d: %d\n", i + 1 , result);
  }
  return 0;
}
