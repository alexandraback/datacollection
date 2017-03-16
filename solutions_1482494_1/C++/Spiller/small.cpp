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


struct s_level{
	int a;
	int b;
};

int main(){
	FILE *f = fopen( "small.txt", "r" );
	FILE *o = fopen( "small-result.txt", "w" );
	
	if( f ){
		int amount = atoi( read_line(f).c_str() );
		for( int i=1; i <= amount; i++ ){
			//Get amount of levels
			int levels;
			fscanf( f, "%d", &levels );
			
			//Get levels
			s_level *level = new s_level[ levels ];
			for( int j=0; j<levels; j++ )
				fscanf( f, "%d %d", &level[j].a, &level[j].b );
			
			int played = 0;
			int star1 = 0;
			int star2 = 0;
			while( true ){
				bool stop = true;
				
				//Get all star2 avaiable
				for( int j=0; j<levels; j++ ){
					if( level[j].b >= 0 && level[j].b <= star1+star2 ){
						star2++;
						played++;
						level[j].b = -1;
						if( level[j].a >= 0 ){
							star1++;
							level[j].a = -1;
						}
						stop = false;
					}
					
					//Stop if all gotten
					if( star2 == levels )
						break;
				}
				if( star2 == levels )
					break;
				
				if( stop ){
					//No star2 gotten, get a single star1
					int l = -1;
					for( int j=0; j<levels; j++ ){
						if( level[j].a >= 0 && level[j].a <= star1+star2 ){
							if( l == -1 || level[j].b > level[l].b ){
								l = j;
							}
						}
					}
					
					//Play the level
					if( l != -1 ){
						played++;
						star1++;
						level[l].a = -1;
						stop = false;
					}
				}
				
				if( stop )
					break;
			}
			
			printf( "Case #%d: %d, %d\n", i, star1, star2 );
			
			if( star2 != levels )
				fprintf( o, "Case #%d: Too Bad\n", i );
			else
				fprintf( o, "Case #%d: %d\n", i, played );
		}
	}
	
	
	return 0;
}

