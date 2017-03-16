#include <algorithm>
#include <cstdio>
using namespace std;

#define VAL 100000000
#define NMAX 205

int value[NMAX];
int N, X;

bool check (int poz,double pro) {
  
	double v, rez, cP;

	rez = 1.0 - pro;
	v = (double)value[poz] + pro * X;

	for (int i = 1; i <= N; i++)
		if (i != poz) {
			if ((double)value[i] > v) continue ;

			cP = (v - value[i]) / X;
			if (cP >= rez) return 1;

			rez-=cP;
		}

  return 0;
}

void solve (int i) {
  
	int st, dr, mij;
	double rez = VAL;
    for (st = 0, dr = VAL; st <= dr; ) {
      mij = (st + dr) >> 1;

      if (check (i,(double) mij / VAL)) {

        rez = (double) 100 * (double) mij / VAL;
        dr = mij - 1;
      }
      else
        st = mij+1;
    }

	printf ("%.6lf ", rez);
}

int main () {
  
	freopen ("A.in", "r", stdin);
	freopen ("A.out", "w", stdout);
  
	int T;
	scanf ("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf ("%d", &N);
		X = 0;
		for (int i = 1; i <= N; i++) {
			scanf ("%d", &value[i]);
			X+= value[i];
		}

		printf ("Case #%d: ", t);
		for (int i = 1; i <= N; i++)
			solve (i); 
		printf ("\n");
	}

	return 0;
}
