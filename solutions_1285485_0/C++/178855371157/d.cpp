
// Rewritten from Python, because Python was too slow.

// Frank, why is this problem such a pain in the ass?

#include <algorithm>
#include <boost/rational.hpp>
#include <cassert>
#include <stdio.h>

using namespace std;
using boost::rational;

int B[30][30];
int H, W, D;


int gcd(int x, int y) {
  int a = max(x, y);
  int b = min(x, y);
  while (b != 0) {
    int c = a % b;
    a = b;
    b = c;
  }
  return a;
}


int sign(int x) {
  if (x >= 0) {
    return 1;
  }
  return -1;
}


bool entering(int r, int c, int dr_sign, int dc_sign, int r0, int c0) {
  int er = r;
  int ec = c;
  if (dr_sign < 0) {
    er--;
  }
  if (dc_sign < 0) {
    ec--;
  }
  return (er == r0) && (ec == c0);
}

int get_canonical_corner(int r, int c, int dr_sign, int dc_sign) {
  if (dr_sign == 1) {
    if (dc_sign == 1) {
      return (B[r-1][c-1]*0x1000 + B[r-1][c]*0x100
	      + B[r][c-1]*0x10 + B[r][c]*0x1);
    } else {
      return (B[r-1][c]*0x1000 + B[r-1][c-1]*0x100
	      + B[r][c]*0x10 + B[r][c-1]*0x1);
    }
  } else {
    if (dc_sign == 1) {
      return (B[r][c-1]*0x1000 + B[r][c]*0x100
	      + B[r-1][c-1]*0x10 + B[r-1][c]*0x1);
    } else {
      return (B[r][c]*0x1000 + B[r][c-1]*0x100
	      + B[r-1][c]*0x10 + B[r-1][c-1]*0x1);
    }
  }
}

bool cast(int r0, int c0, int dr, int dc) {
  rational<int> dist_r = 0;
  rational<int> dist_c = 0;

  int dr_sign = sign(dr);
  int dc_sign = sign(dc);
  dr = abs(dr);
  dc = abs(dc);

  rational<int> dr_over_dc = 0;
  rational<int> dc_over_dr = 0;
  if ((dr != 0) && (dc != 0)) {
    dr_over_dc = rational<int>(dr, dc);
    dc_over_dr = rational<int>(dc, dr);
  }

  int r = r0;
  int c = c0;
  if (dr_sign < 0)
    r += 1;
  if (dc_sign < 0)
    c += 1;

  rational<int> r_rem(1,2);
  rational<int> c_rem(1,2);

  rational<int> r_start = r + dr_sign*(1 - r_rem);
  rational<int> c_start = c + dc_sign*(1 - c_rem);

#if 0
  printf("START: (%d/%d,%d/%d) (%d,%d))\n",
	 (r+dr_sign*(1-r_rem)).numerator(),
	 (r+dr_sign*(1-r_rem)).denominator(),
	 (c+dc_sign*(1-c_rem)).numerator(),
	 (c+dc_sign*(1-c_rem)).denominator(),
	 dr * dr_sign, dc * dc_sign);
#endif

  while (true) {
    if (r_rem*dc >= c_rem*dr) {
      dist_r += dr_over_dc * c_rem;
      dist_c += c_rem;
      r_rem -= dr_over_dc * c_rem;
      c_rem = 0;
    } else {
      dist_c += dc_over_dr * r_rem;
      dist_r += r_rem;
      c_rem -= dc_over_dr * r_rem;
      r_rem = 0;
    }

    if (r_rem == 0)
      r += dr_sign;
    if (c_rem == 0)
      c += dc_sign;

    if (dist_r*dist_r + dist_c*dist_c > D*D)
      return false;

    int corner = get_canonical_corner(r, c, dr_sign, dc_sign);
    if ((r_rem == 0) && (c_rem == 0)) {
      if (corner == 0x0001) {
	break;
      } else if (corner == 0x0111) {
	dr_sign = -dr_sign;
	dc_sign = -dc_sign;
    } else if (corner == 0x0011) {
	dr_sign = -dr_sign;
      } else if (corner == 0x0101) {
	dc_sign = -dc_sign;
      }

    } else if ((corner & 0x1) && (r_rem == 0)) {
      dr_sign = -dr_sign;

    } else if ((corner & 0x1) && (c_rem == 0)) {
      dc_sign = -dc_sign;
    }

    if (r_rem == 0)
      r_rem = 1;
    if (c_rem == 0)
      c_rem = 1;

#if 0
    printf("(%d/%d,%d/%d) (%d,%d))\n",
	   (r+dr_sign*(1-r_rem)).numerator(),
	   (r+dr_sign*(1-r_rem)).denominator(),
	   (c+dc_sign*(1-c_rem)).numerator(),
	   (c+dc_sign*(1-c_rem)).denominator(),
	   dr * dr_sign, dc * dc_sign);
#endif

    if (entering(r, c, dr_sign, dc_sign, r0, c0)) {
      rational<int> sep_r = r_start - (r + dr_sign * (1 - r_rem));
      rational<int> sep_c = c_start - (c + dc_sign * (1 - c_rem));
      if (sep_r * dc_sign * dc == sep_c * dr_sign * dr) {
#if 0	
	printf("Entered %d/%d %d/%d %d/%d %d/%d\n",
	       dist_r.numerator(), dist_r.denominator(),
	       dist_c.numerator(), dist_c.denominator(),
	       sep_r.numerator(), sep_r.denominator(),
	       sep_c.numerator(), sep_c.denominator());
#endif
	dist_r += abs(sep_r);
	dist_c += abs(sep_c);
	rational<int> dist = dist_r*dist_r + dist_c*dist_c;
#if 0
	printf("   and final dist is %d/%d\n",
	       dist.numerator(), dist.denominator());
#endif
	return (dist_r*dist_r + dist_c*dist_c <= D*D);
      }
    }
  }

  return false;
}


int main(void) {
  int T;
  scanf("%d\n", &T);
  for (int t = 1; t <= T; t++) {
    int r0 = 0, c0 = 0;

    scanf("%d %d %d\n", &H, &W, &D);
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
	int c = getchar();
	if (c == '#') {
	  B[i][j] = 1;
	} else {
	  if (c == 'X') {
	    r0 = i;
	    c0 = j;
	  }
	  B[i][j] = 0;
	}
      }
      getchar();
    }

    int answer = 0;
    for (int dr = -D; dr <= D; dr++)
      for (int dc = -D; dc <= D; dc++)
	if (gcd(abs(dr),abs(dc)) == 1)
	  if (cast(r0, c0, dr, dc))
	    answer += 1;

    printf("Case #%d: %d\n", t, answer);
  }

  return 0;
}
