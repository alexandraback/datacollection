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
	__int64 A;
	std::multiset<__int64> N;
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
				
				p.A = _strtoi64( split_line[0].c_str() , NULL , 10 );
				auto n = _strtoi64( split_line[1].c_str() , NULL , 10 );
				getline( ifs , line );
				split_line = split( line , " ");
				for(__int64 i=0;i<n;++i){
					p.N.insert(_strtoi64( split_line[i].c_str() , NULL , 10 ));
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

__int64 solve(PROBLEM &p)
{
	auto n = p.A;
	__int64 opco = 0;
	__int64 min = p.N.size();
	auto i = p.N.begin();
	while(i!=p.N.end())
	{
		auto c = *i;
		auto r = std::distance(i, p.N.end())-1;
		if(n>c){
			n+=c;
			++i;
			min = std::min(min, opco + r);
		}else{
			if(n!=1){
				n+=n-1;
			}else{
				++i;
			}
			++opco;
		}
	}
	return min;
}

int main(int argc, char *argv[])
{
	vector<PROBLEM> problems;
	if( argc != 2 ) return -1;
	if( !read_problem( argv[1] , problems ) ) return -2;
	
	int count = 0;
	for( auto itr = problems.begin(); itr != problems.end() ; ++itr )
	{
		PROBLEM &problem = *itr;
		
		auto x = solve(problem);

		printf("Case #%d: %lld\n",++count,x);
	}

	return 0;
}
