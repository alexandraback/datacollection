#include<stdio.h>
#include<vector>
#include<string>
#include<fstream>
#include<map>
#include<set>
#include<algorithm>
#include<cstdio>
#include<deque>

using namespace std;

typedef struct
{
	long long int N;
	long long int M;
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
				p.M = _strtoi64( split_line[1].c_str() , NULL , 10 );

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

long long int next_v(long long int d,long long int x)
{
	long long int t = 10;
	while(x%t==0){t*=10;}

	return x/t + (d/t)*(x%t);
}

long long int solve(PROBLEM &p)
{
	long long int h = 0;
	std::set<std::pair<long long int,long long int>> g;

	for( long long int i = p.N; i <= p.M; ++i )
	{
		long long int t = i;
		long long int d = 10;
		while(t/d){d*=10;}
		t = next_v(d,i);
		while(t!=i){
			if( p.N <= t && t <= p.M){
				if(g.insert(std::make_pair(std::min(t,i),std::max(t,i))).second){
					++h;
				}
			}
			t = next_v(d,t);
		}
	}
	return h;
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
