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
	std::string S;
	long long int N;
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
				
				p.S = split_line[0].c_str();
				p.N = _strtoi64( split_line[1].c_str() , NULL , 10 );

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

bool is_vowel(char c)
{
	if(c!='a'&&c!='i'&&c!='u'&&c!='e'&&c!='o')
	{
		return false;
	}
	return true;
}

__int64 solve(PROBLEM &p)
{

	std::vector<__int64> pt;
	auto e = p.S.length();
	for(auto i=0;i<=e-p.N;++i)
	{
		if(!is_vowel(p.S[i])){
			bool r=true;
			for(int j=i+1;j<e&&j<i+p.N;++j){
				if(is_vowel(p.S[j]))
				{
					r=false;
					break;
				}
			}
			if(r){
				pt.push_back(i);
			}
		}
	}
	__int64 n=-1;
	__int64 sum=0;
	for(auto i=pt.begin();i!=pt.end();++i)
	{
		auto x=*i;
		sum+=(x-n)*(e-x-p.N+1);
		n=x;
	}
	return sum;
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