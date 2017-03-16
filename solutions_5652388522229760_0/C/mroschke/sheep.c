#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

void solve_instance(int start) {
  // special case
  if(start == 0) {
    printf("INSOMNIA\n");
  } else {
    int seen_bits = 0;

    int current = start;
    for(;;current += start) {
      int tmp = current;
      while(tmp) {
        seen_bits |= (1 << (tmp%10));
        tmp = tmp / 10;
      }

      if(seen_bits == 0x03ff) {
        break;
      }
    }

    printf("%d\n", current);
  }
}

int main(int argc, char* argv[]) {
  // get argument count
  int t = atoi(argv[1]);

  // iterate over entries
  for(int i = 2; i < t + 2; i++) {
    // get the value
    int start = atoi(argv[i]);

    // print prefix
    printf("Case #%d: ", i - 1);

    // solve problem
    solve_instance(start);
  }
}

