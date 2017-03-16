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
	std::vector<std::pair<unsigned long long int ,unsigned long long int >> A;
	std::vector<std::pair<unsigned long long int ,unsigned long long int >> B;

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
/*
4
3 3
10 1 20 2 25 3
10 2 30 3 20 1
3 5
10 1 6 2 10 1
5 1 3 2 10 1 3 2 5 1
3 5
10 1 6 2 10 1
5 1 6 2 10 1 6 2 5 1
1 1
5000000 10
5000000 100
*/
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
				
				auto n = _strtoi64(split_line[0].c_str() , NULL , 10);
				auto m = _strtoi64(split_line[1].c_str() , NULL , 10);
				
				getline( ifs , line );
				split_line = split( line , " ");
				
				for( auto i = 0 ; i < n*2 ; i+=2 )
				{
					p.A.push_back(std::make_pair(_strtoui64(split_line[i].c_str() , NULL , 10),_strtoi64(split_line[i+1].c_str() , NULL , 10)));
				}

				getline( ifs , line );
				split_line = split( line , " ");
				for( auto i = 0 ; i < m*2 ; i+=2 )
				{
					p.B.push_back(std::make_pair(_strtoui64(split_line[i].c_str() , NULL , 10),_strtoi64(split_line[i+1].c_str() , NULL , 10)));
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

unsigned long long int  sc(int n,int m,PROBLEM p)
{
	unsigned long long int  score=0;
	unsigned long long int  s[2];
	s[0] = s[1] = 0;

	if(p.A.size() > n && p.B.size() > m)
	{
		if(p.A[n].second==p.B[m].second){
			score += min(p.A[n].first,p.B[m].first);
			p.A[n].first -= score;
			p.B[n].first -= score;
		}
	}
	if(p.A.size() > n){	
		s[0] = sc(n+1,m,p);
	}

	if(p.B.size() > m){	
		s[1] = sc(n,m+1,p);
	}
	return max(s[0],s[1]) + score;
}

unsigned long long int  solve(PROBLEM &p)
{	
	return sc(0,0,p);
}

int main(int argc, char *argv[])
{
	
	vector<PROBLEM> problems;
	if( argc != 2 ) return -1;
	if( !read_problem( argv[1] , problems ) ) return -2;
	
	int count = 0;
	for( auto itr = problems.begin(); itr != problems.end() ; ++itr )
	{
		unsigned long long int  x;
		PROBLEM &problem = *itr;
		
		x = solve(problem);

		printf("Case #%d: %llu\n",++count,x);
	}

	return 0;
}
