#include <cstdio>
#include <map>
#include <algorithm>
#include <string.h>
#include <ctime>
using namespace std;

#define NMAX 510

long long N, viz[NMAX];
long long value[NMAX], value2[NMAX];

bool solve (int N) {
	
	//printf ("DA!\n");

	int st2;

	map <int, int> hash;                                       
	for (int st = 1; st < (1 << N); st++) {
		
		int sum = 0;
		for (int i = 0; i < N; i++)
			if ( (st>>i)&1 ) sum+= value[i];
       
		//printf ("%d\n", sum);
		if (hash[sum]) {
			st2 = hash[sum];	
			for (int i = 0; i < N; i++)
				if ( (st2>>i)&1 ) printf ("%lld ", value[i]);
			printf ("\n");

			for (int i = 0; i < N; i++)
				if ( (st >> i)&1 ) printf ("%lld ", value[i]);
			printf ("\n");

			return 1;
		}

		hash[sum] = st;
	}

	return 0;
}

int main () {
	
	srand ( time (0) );
	freopen ("A.in", "r", stdin);
	freopen ("A.out", "w", stdout);

	int T, t;
	for (t = 1, scanf ("%d", &T); T; T--, t++) {
		scanf ("%lld", &N);
		for (int i = 0; i < N; i++)
			scanf ("%lld", &value2[i]);

		printf ("Case #%d:\n", t);
		
		memset (viz, 0, sizeof (viz));

		int nr = 0, poz;
        while (nr < 25) {
			poz = rand () % N; 
			if (!viz[poz])  {
				viz[poz] = 1;
				value[nr] = value2[poz];
				nr++;
			}
		}

		//for (int i = 1; i <= nr; i++)
		//  printf ("%d ", value[i]);
		//printf ("\n");

		//solve (nr);

	    while (solve (nr) == 0) {
			memset (viz, 0, sizeof (viz));
			
			nr = 0;
			while (nr < 25) {
				poz = rand () % N; 
				if (!viz[poz])  {
					viz[poz] = 1;
					value[nr] = value2[poz];
					nr++;
				}
			}
		}
		 	
	}

	return 0;
}
