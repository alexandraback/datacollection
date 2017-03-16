#include <cstdio>
#include <vector>
#include <string>
#include <map>
using namespace std;

int n;
int s[1000];
double dap[1000];

double oneexp( double a, double k, double y )
{
	////	y = kx + a 에서 x를 구함
	return ( y - a ) / k;
}

void process()
{
	int hap = 0;
	for ( int i = 0; i < n; ++i )
		hap += s[i];

	for ( int i = 0; i < n; ++i ) {

		double left = 0.0;
		double right = 1.0;
		double mid;

		while ( fabs( right - left ) > 0.000000001 ) {
			mid = ( left + right ) / 2.0;

			double test = (double)s[i] + (double)hap * mid;

			double result = 0.0;
			for ( int j = 0; j < n; ++j ) {
				if ( i == j )
					continue;
				double temp = oneexp( (double)s[j], (double)hap, test );
				if ( temp < 0.0 )
					temp = 0.0;

				result += temp;
			}

			if ( result + mid > 1.0 )
				right = mid;
			else
				left = mid;
		}

		dap[i] = left;
	}
}

int main()
{
	FILE* fp = fopen( "input.txt", "r" );
	int casen = 0;
	fscanf( fp, "%d\n", &casen );

	FILE *fout = fopen( "output.txt", "w" );

	for ( int casei = 0; casei < casen; ++casei ) {
		fscanf( fp, "%d", &n );
		for ( int i = 0; i < n; ++i )
			fscanf( fp, "%d", &s[i] );

		process();

		fprintf( fout, "Case #%d:", casei + 1 );
		double test = 0.0;
		for ( int i = 0; i < n; ++i ) {
			fprintf( fout, " %f", dap[i] * 100.0 );
			test += dap[i] * 100.0;
		}
		fprintf( fout, "\n" );
	}

	fclose( fp );
	fclose( fout );
	return 0;
}
