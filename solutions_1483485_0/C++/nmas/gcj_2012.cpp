#include<stdio.h>
#include<vector>
#include<string>
#include<fstream>
#include<map>
#include<set>
#include<algorithm>
#include<cstdio>

using namespace std;

char* code = "\
ejp mysljylc kd kxveddknmc re jsicpdrysi\
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd\
de kr kd eoya kw aej tysr re ujdr lkgc jv\
y qee\
z";

char* org = "\
our language is impossible to understand\
there are twenty six factorial possibilities\
so it is okay if you want to just give up\
a zoo\
q";

typedef struct
{
	std::string text;
}PROBLEM;

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
				p.text = line;
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

std::map<char,char> code_map;
std::string solve(PROBLEM &p)
{
	std::set<char> asdf;
	if(!code_map.size()){
		for(char *ptr = code;*ptr != '\0';++ptr){
			code_map.insert(make_pair(*ptr,*(org+(ptr-code))));
			asdf.insert(*(org+(ptr-code)));
		}
	}
	std::string x;
	for(auto i = p.text.begin();i != p.text.end(); ++i)
	{
		auto t = code_map.find(*i);
		if(t != code_map.end()){
			x.push_back(t->second);
		}
	}
	return x;
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

		printf("Case #%d: %s\n",++count,x.c_str());
	}

	return 0;
}
