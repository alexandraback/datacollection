#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 2100100
typedef long long lint;

int a[MAX], x, l;
int mult[][5] = {{0, 0,  0,  0,  0},
		 {0, 1,  2,  3,  4},
		 {0, 2, -1,  4, -3},
		 {0, 3, -4, -1,  2},
		 {0, 4,  3, -2, -1}};

int f (int p, int q) {
  if (p < 0)
    return - f (-p, q);
  if (q < 0)
    return - f (p, -q);
  return mult[p][q];
}

int main () {
  int teste;
  scanf ("%d", &teste);
  for (int t = 0; t < teste; t++) {
    lint aux;
    scanf ("%d %lld", &l, &aux);
    for (int i = 0; i < l; i++) {
      char c;
      scanf (" %c", &c);
      a[i] = 2*(c == 'i') + 3*(c == 'j') + 4*(c == 'k');
    }
    x = aux;
    if (aux > 20) {
      aux = 20 + (aux - 20)%4;
    }
    x = aux;
    for (int j = 1; j < x; j++) {
      for (int i = 0; i < l; i++) {
	a[j*l + i] = a[i];
      }
    }
    int fail = 0;
    int total = 1;
    for (int i = 0; i < x*l; i++) 
      total = f (total, a[i]);
    if (total != -1) 
      fail = 1;

    int now = 1;
    int begin = 0;
    for (;begin < l*x && now != 2; begin++)
      now = f (now, a[begin]);
    if (now != 2)
      fail = 1;

    int end = l*x - 1;
    now = 1;
    for (;end >= begin && now != 4; end--)
      now = f (a[end], now);
    if (now != 4)
      fail = 1;
    if (fail) 
      printf ("Case #%d: NO\n", t + 1 );
    else
      printf ("Case #%d: YES\n", t + 1);
  }
  return 0;
}
