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
	multimap<long long int,long long int> M;
	multimap<long long int,long long int> Mr;

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

				auto i = _strtoi64(split_line[0].c_str() , NULL , 10);
				for( auto ii = 1 ; ii <= i ; ++ii )
				{
					getline( ifs , line );
					split_line = split( line , " ");
					auto t = _strtoi64(split_line[0].c_str() , NULL , 10);
					for( auto s = 1 ; s <= t ; ++s )
					{
						p.M.insert(std::make_pair(_strtoi64(split_line[s].c_str() , NULL , 10),ii));
						p.Mr.insert(std::make_pair(ii,_strtoi64(split_line[s].c_str() , NULL , 10)));
					}
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
	multimap<long long int,long long int> xy(p.M);
	set<std::pair<long long int,long long int>> st;
	set<std::pair<long long int,long long int>> st2;

	for(auto i = xy.begin();i != xy.end(); ++i )
	{
		st.insert(std::make_pair((*i).first,(*i).second));
		st2.insert(std::make_pair((*i).first,(*i).second));
	}

	while(1){
		set<std::pair<long long int,long long int>> tmp;
		for(auto i = st.begin();i != st.end(); ++i )
		{
			auto t = xy.equal_range(i->second);
			for(auto g = t.first;g != t.second;++g)
			{
				auto k = st2.find(std::make_pair(i->first,g->second));
				if(k != st2.end()){
					return 1;
				}
				st2.insert(std::make_pair(i->first,g->second));
				tmp.insert(std::make_pair(i->first,g->second));
			}
		}
		if(tmp == st)return 0;
		st = tmp;
	}
	return 0;
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

		if(x!=0){
			printf("Case #%d: Yes\n",++count);
		}else{
			printf("Case #%d: No\n",++count);
		}
	}

	return 0;
}
