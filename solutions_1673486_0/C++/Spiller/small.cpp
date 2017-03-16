#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;

string read_line( FILE *f ){
	string s = "";
	char c;
	while( ((c = getc(f)) != '\n') && (c != EOF) )
		s += c;
	return s;
}

int main(){
	FILE *f = fopen( "small.txt", "r" );
	FILE *o = fopen( "small-result.txt", "w" );
	
	if( f ){
		int amount = atoi( read_line(f).c_str() );
		for( int i=1; i <= amount; i++ ){
			//Get amount of characters
			int entered, required;
			fscanf( f, "%d %d", &entered, &required );
			int left = required - entered;
			int retype = required + 1;
			
			//Get probabilities
			double *probabilities = new double[ entered ];
			for( int j=0; j<entered; j++ )
				fscanf( f, "%lf", &probabilities[j] );
			
			double optimal = 2 + required;	//Option 3 calculated first
			
			//Calculate option 2
			double P = 1;
			for( int j=entered-1; j>=0; j-- ){
				P *= probabilities[entered-j-1];
				
				int success = j*2 + left + 1;
				double expected = success * P + ( success + retype ) * ( 1.0-P);
				if( expected < optimal )
					optimal = expected;
			}
			
			
			
			fprintf( o, "Case #%d: %f\n", i, optimal );
		}
	}
	
	
	return 0;
}

