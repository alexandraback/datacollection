#include<stdio.h>
#include<vector>
#include<string>
#include<fstream>
#include<map>
#include<set>
#include<algorithm>
#include<cstdio>

using namespace std;

typedef struct
{
	long long int N;
	long long int S;
	long long int P;
	std::vector<long long int>t;
}PROBLEM;

vector<string> split( const string& line , const string& sep )
{
	int pos[2];
	pos[0] = pos[1] = 0;
	vector<string> split_line;
	while( ( pos[1] = line.find(sep,pos[0]) ) != string::npos )
	{
		string sub_line = line.substr( pos[0] , pos[1] - pos[0] );
		split_line.push_back(sub_line);
		pos[0] = pos[1] + 1;
	}
	string sub_line = line.substr( pos[0] );
	split_line.push_back(sub_line);
	return split_line;
}

bool read_problem( const char *fname , vector<PROBLEM>& problems )
{
	fstream ifs;
	ifs.open( fname );

	if( !ifs.is_open() ) return false;

	int T = 0;
	try{
		std::string line;
		int line_num = 0;
		while( getline( ifs , line ) ){
			if( line_num == 0 )	{
				T = strtoul( line.c_str() , NULL , 10);
			}else{
				PROBLEM p;

				auto split_line = split( line , " ");
				
				p.N = _strtoi64( split_line[0].c_str() , NULL , 10 );
				p.S = _strtoi64( split_line[1].c_str() , NULL , 10 );
				p.P = _strtoi64( split_line[2].c_str() , NULL , 10 );
				for(int i = 0 ; i < p.N; ++i ) {
					p.t.push_back( _strtoi64( split_line[3+i].c_str() , NULL , 10 ));
				}
			
				problems.push_back(p);
			}
			++line_num;
		}
	}catch(...){
		return false;
	}
	if( problems.size() != T ) return false;
	return true;
}

long long int solve(PROBLEM &p)
{
	long long int c = p.P*3-2;
	long long int s = c - 2;

	long long int tc = 0;
	long long int sc = 0;
	for(auto itr = p.t.begin();itr != p.t.end(); ++itr )
	{
		if(*itr >= c) {
			++tc;
		}else{
			if(*itr >= s&&*itr >= 2) ++sc;
		}
	}
	tc += std::min(sc,p.S);
	return tc;
}

int main(int argc, char *argv[])
{
	vector<PROBLEM> problems;
	if( argc != 2 ) return -1;
	if( !read_problem( argv[1] , problems ) ) return -2;
	
	int count = 0;
	for( auto itr = problems.begin(); itr != problems.end() ; ++itr )
	{
		long long int x;
		PROBLEM &problem = *itr;
		
		x = solve(problem);

		printf("Case #%d: %lld\n",++count,x);
	}

	return 0;
}
