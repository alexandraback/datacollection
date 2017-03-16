#include <cstdio>
#include <map>
using namespace std;

char inpstr[1000];

int main()
{
	map< char, char > google;
	google['a'] = 'y';
	google['b'] = 'h';
	google['c'] = 'e';
	google['d'] = 's';
	google['e'] = 'o';
	google['f'] = 'c';
	google['g'] = 'v';
	google['h'] = 'x';
	google['i'] = 'd';
	google['j'] = 'u';
	google['k'] = 'i';
	google['l'] = 'g';
	google['m'] = 'l';
	google['n'] = 'b';
	google['o'] = 'k';
	google['p'] = 'r';
	google['q'] = 'z';
	google['r'] = 't';
	google['s'] = 'n';
	google['t'] = 'w';
	google['u'] = 'j';
	google['v'] = 'p';
	google['w'] = 'f';
	google['x'] = 'm';
	google['y'] = 'a';
	google['z'] = 'q';

	FILE* fp = fopen( "input.txt", "r" );
	int casen = 0;
	fscanf( fp, "%d\n", &casen );

	FILE *fout = fopen( "output.txt", "w" );

	for ( int casei = 0; casei < casen; ++casei ) {
		fgets( inpstr, 1000, fp );

		for ( char* sp = inpstr; *sp != '\0'; ++sp ) {
			if ( *sp == '\n' ) {
				*sp = '\0';
				break;
			}
			if ( *sp == ' ' )
				continue;

			*sp = google[ *sp ];
		}
		fprintf( fout, "Case #%d: %s\n", casei + 1, inpstr );
	}

	fclose( fp );
	fclose( fout );
	return 0;
}
