#include <cstdio>
#include <vector>
#include <string>
#include <map>
using namespace std;

int A, B;
long long dap;
map< int, int > checkmap;

void process()
{
	dap = 0;

	for ( int i = A; i < B; ++i ) {
		if ( i < 10 )
			continue;

		string cur = to_string( (long long)i );
		int curlen = cur.length();

		checkmap.clear();
		for ( int j = 0; j < curlen - 1; ++j ) {
			char temp = cur[0];
			cur.erase( 0, 1 );
			cur.append( 1, temp );

			int test = stoi( cur );
			if ( i < test && test <= B ) {
				if ( checkmap.find( test ) == checkmap.end() ) {
					++dap;
					checkmap[ test ] = 1;
				}
			}
		}
	}
}

int main()
{
	FILE* fp = fopen( "input.txt", "r" );
	int casen = 0;
	fscanf( fp, "%d\n", &casen );

	FILE *fout = fopen( "output.txt", "w" );

	for ( int casei = 0; casei < casen; ++casei ) {
		fscanf( fp, "%d %d", &A, &B );

		process();

		fprintf( fout, "Case #%d: %d\n", casei + 1, dap );
	}

	fclose( fp );
	fclose( fout );
	return 0;
}
