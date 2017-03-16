#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <map>

using namespace std;
int typed = 0;
int total = 0;
std::vector< double > prop;

double run()
{
	double ans = 99999999.0;
	for (int bk=0; bk<=typed; bk++ )
	{
		double exp = 0.0;
		for (int i=0; i< (1<<typed); i++) {
			int keyStroke = 0;

			double p = 1;
			for(int k=0; k< (int)prop.size(); k++ ){
				int t = (1<<k);
				if( (i & t) > 0 )
					p *= (1.0-prop[ prop.size()-k-1 ]);
				else
					p *= prop[prop.size()-k-1];
			}
			
			keyStroke += bk * 2;
			keyStroke += total - typed + 1;
			
			if( (i >> bk) != 0 )
				keyStroke += total + 1;
			
			exp += p * keyStroke;
			
//			printf("p: %.2lf, key: %d, exp : %.2lf\n", p, keyStroke, exp );
		}
		
		ans = std::min<double>( ans, exp );
	}

	ans = std::min<double>( ans, total+2 );
	return ans;
}

int main()
{
	FILE *fin = fopen( "../../input.txt", "rt" );
//	FILE *fout = stdout;
	FILE *fout = fopen( "../../out.txt", "wt" );
	
	int tc = 0;
	fscanf( fin, "%d\n", &tc );
	
	for( int i=1; i<=tc; i++ )
	{
		fscanf( fin, "%d %d\n", &typed, &total );
		
		prop.clear();
		for( int j=0; j<typed; j++ ){
			double p;
			fscanf( fin, "%lf\n", &p );
			prop.push_back( p );
		}

		double ans = run();
		fprintf( fout, "Case #%d: %.6lf\n", i, ans );
	}
	
    return 0;
}