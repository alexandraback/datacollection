#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, S, P;
vector< int > scores;
int dap;

void process()
{
	sort( scores.begin(), scores.end(), greater< int >() );

	int current_s = S;
	dap = 0;
	for ( int i = 0; i < N; ++i ) {
		if ( scores[i] > (P-1)*3 ) {
			++dap;
			continue;
		}

		if ( scores[i] <= (P-2)*3 + 1 )
			break;

		if ( scores[i] <= 1 )
			break;

		if ( current_s > 0 ) {
			--current_s;
			++dap;
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
		scores.clear();

		fscanf( fp, "%d %d %d", &N, &S, &P );
		for ( int i = 0; i < N; ++i ) {
			int num = 0;
			fscanf( fp, "%d", &num );
			scores.push_back( num );
		}

		process();

		fprintf( fout, "Case #%d: %d\n", casei + 1, dap );
	}

	fclose( fp );
	fclose( fout );
	return 0;
}
