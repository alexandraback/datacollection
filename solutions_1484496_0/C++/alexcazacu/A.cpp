#include <cstdio>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

#define NMAX 23

int N;
int value[NMAX];

void solve () {
	
	int st2;

	map <int, int> hash;                                       
	for (int st = 1; st < (1 << N); st++) {
		
		int sum = 0;
		for (int i = 0; i < N; i++)
			if ( (st>>i)&1 ) sum+= value[i];

		// printf ("%d\n", sum);
		if (hash[sum]) {
			st2 = hash[sum];	
			for (int i = 0; i < N; i++)
				if ( (st2>>i)&1 ) printf ("%d ", value[i]);
			printf ("\n");

			for (int i = 0; i < N; i++)
				if ( (st >> i)&1 ) printf ("%d ", value[i]);
			printf ("\n");

			return ;
		}

		hash[sum] = st;
	}

	printf ("Impossible\n");
}

int main () {
	
	freopen ("A.in", "r", stdin);
	freopen ("A.out", "w", stdout);

	int T, t;
	for (t = 1, scanf ("%d", &T); T; T--, t++) {
		scanf ("%d", &N);
		for (int i = 0; i < N; i++)
			scanf ("%d", &value[i]);

		printf ("Case #%d:\n", t);
		solve ();           
	}

	return 0;
}
