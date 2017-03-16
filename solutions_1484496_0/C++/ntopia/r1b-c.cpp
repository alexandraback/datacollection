#include <cstdio>
#include <vector>
#include <string>
#include <map>
using namespace std;

int n;
int s[1000];
int dap1, dap2;
multimap< int, int > data;

int prochap( int idx )
{
	int r[100] = {0,};
	int length = 0;

	while ( idx > 0 ) {
		r[length] = idx % 2;
		length++;
		idx = idx / 2;
	}

	int hap = 0;
	for ( int i = 0; i < 20; ++i ) {
		if ( r[i] == 1 )
			hap += s[i];
	}
	return hap;
}

void printnum( int idx, FILE* fout )
{
	int r[100] = {0,};
	int length = 0;

	while ( idx > 0 ) {
		r[length] = idx % 2;
		length++;
		idx = idx / 2;
	}

	for ( int i = 0; i < 20; ++i ) {
		if ( r[i] == 1 )
			fprintf( fout, "%d ", s[i] );
	}
	fprintf( fout, "\n" );
}

void process()
{
	data.clear();
	for ( int i = 1; i < 1048576; ++i ) {
		int k = prochap( i );

		data.insert( make_pair( k, i ) );
	}

	for ( multimap< int, int >::iterator it = data.begin(); it != data.end(); ++it ) {
		pair< int, int > test = *it;

		if ( data.count( test.first ) > 1 ) {
			pair< multimap<int,int>::iterator,multimap<int,int>::iterator > tt = data.equal_range( test.first );

			for ( multimap< int, int >::iterator it1 = tt.first; it1 != tt.second; ++it1 ) {
				for ( multimap< int, int >::iterator it2 = it1; it2 != tt.second; ++it2 ) {

					if ( ( it1->second & it2->second ) == 0 ) {
						dap1 = it1->second;
						dap2 = it2->second;
						return;
					}
				}
			}

			it = tt.second;
			--it;
		}
	}

	dap1 = dap2 = -1;
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

		fprintf( fout, "Case #%d:\n", casei + 1 );

		if ( dap1 == -1 || dap2 == -1 )
			fprintf( fout, "Impossible\n" );
		else {
			printnum( dap1, fout );
			printnum( dap2, fout );
		}
	}

	fclose( fp );
	fclose( fout );
	return 0;
}
