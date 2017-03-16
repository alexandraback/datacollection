#include <cstdio>
#include <cstdlib>

int main () {

  int T;
  scanf ("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int x, y;
    scanf ("%d%d", &x, &y);
    
    printf ("Case #%d: ", t);

    int k = 1; // Length of the jump
    while (true) {
      //printf ("x = %d y = %d k = %d\n", x, y, k);
      if (x == 0 && y == 0) {
	printf ("\n");
	break;
      }
      else if (x > 0 && x < k) {
	for (int i = 0; i < x; ++i) {
	  printf ("WE");
	  k += 2;
	}
	x = 0;
      }
      else if (x < 0 && -x < k) {
	for (int i = 0; i > x; --i) {
	  printf ("EW");
	  k += 2;
	}
	x = 0;
      }
      else if (y > 0 && y < k) {
	for (int i = 0; i < y; ++i) {
	  printf ("SN");
	  k += 2;
	}
	y = 0;
      }
      else if (y < 0 && -y < k) {
	for (int i = 0; i > y; --i) {
	  printf ("NS");
	  k += 2;
	}
	y = 0;
      }
      else {
	if (abs(x) > abs(y)) {
	  if (x < 0) {
	    x += k;
	    printf ("W");
	  }
	  else if (x > 0){
	    x -= k;
	    printf ("E");
	  }
	} else {
	  if (y < 0) {
	    y += k;
	    printf ("S");
	  }
	  else {
	    y -= k;
	    printf ("N");
	  } 
	}
	++k;
      }
    }
  }
  return 0;
}
