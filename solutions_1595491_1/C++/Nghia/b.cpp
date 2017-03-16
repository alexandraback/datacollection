#include "stdio.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
 	ifstream file1("b.txt");
	ofstream file2("b.res");
	int T;
	file1 >> T;
	int N,S,p,score;	
	for(int i = 0; i < T; ++i)
	{
		file1 >> N >> S >> p;
		int res = 0;
		for( int j = 0 ; j < N; ++j)		
		{
			file1 >> score;

			int r = score % 3;
			int d = score / 3;
			switch( r )
			{
				case 0 : 
					if (score > 0)
					{
						if ( d >= p ) ++res;
						else if ( S>0 && d+1==p) {
							--S;
							++res;
							//rintf("hmm %d %d %d\n", S, d+1, p); 
						}					
					}else{
					        if (p == 0) ++res;
					}
					break;
				case 1: if ( d+1 >=p ) ++res; break;
				case 2: if ( d+1 >=p ) ++res; 
					else if ( S>0 && d+2>=p){
						--S; ++res;
					}
					break;
			}
		}
		file2 << "Case #"<<i+1<<": "<<res<<endl;
		
		
	}

	
	return 0;
}

