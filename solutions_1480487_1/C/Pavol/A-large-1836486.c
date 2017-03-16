#include <stdio.h>

int main() {

	int i, t;
	scanf("%d", &t);

	for ( i = 0; i < t; ++i ) {

		int n;
		scanf("%d", &n);
		int x[n];

		int j;
		for ( j = 0; j < n; ++j )
			scanf("%d", &x[j]);

		int sum = 0;
		for ( j = 0; j < n; ++j )
			sum += x[j];

		printf("Case #%d:", i+1);

		long double y[n];

		for ( j = 0; j < n; ++j )
			y[j] = (long double)100 * ((long double)2/n - (long double)x[j]/sum);

		int z[n];
		int z2[n];
		int zn = 0;
		int z2n = 0;
		for ( j = 0; j < n; ++j )
			if ( y[j] < 0 )
				z[zn++] = j;
			else
				z2[z2n++] = j;

		int k;
		for ( j = 0; j < zn; ++j ) {

			for ( k = 0; k < z2n; ++k )
				y[z2[k]] += y[z[j]]/z2n;

			y[z[j]] = 0;

		}

		zn = 0;
		z2n = 0;
		for ( j = 0; j < n; ++j )
			if ( y[j] < 0 )
				z[zn++] = j;
			else
				z2[z2n++] = j;

		for ( j = 0; j < zn; ++j ) {

			for ( k = 0; k < z2n; ++k )
				y[z2[k]] += y[z[j]]/z2n;

			y[z[j]] = 0;

		}

		zn = 0;
		z2n = 0;
		for ( j = 0; j < n; ++j )
			if ( y[j] < 0 )
				z[zn++] = j;
			else
				z2[z2n++] = j;

		for ( j = 0; j < zn; ++j ) {

			for ( k = 0; k < z2n; ++k )
				y[z2[k]] += y[z[j]]/z2n;

			y[z[j]] = 0;

		}

				zn = 0;
		z2n = 0;
		for ( j = 0; j < n; ++j )
			if ( y[j] < 0 )
				z[zn++] = j;
			else
				z2[z2n++] = j;

		for ( j = 0; j < zn; ++j ) {

			for ( k = 0; k < z2n; ++k )
				y[z2[k]] += y[z[j]]/z2n;

			y[z[j]] = 0;

		}


		for ( j = 0; j < n; ++j )
			printf(" %Lf", y[j]);
		printf("\n");

	}

	return 0;

}
