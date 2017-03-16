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
	long long int X;
	long long int Y;
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
				
				p.X = _strtoi64( split_line[0].c_str() , NULL , 10 );
				p.Y = _strtoi64( split_line[1].c_str() , NULL , 10 );

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


class PT
{
public:
	std::string A;
	long long int X;
	long long int Y;
	PT(long long int x,long long int y){
		X=x;
		Y=y;
	}
	bool operator<(const PT& r)const {
		if(X!=r.X) return X<r.X;
		return Y<r.Y;
	}
	PT(){X=0;Y=0;}
	bool N(__int64 x){
		Y+=x;
		A.push_back('N');
		if(X==0&&Y==0) return true;
		return false;
	}
	bool S(__int64 x){
		A.push_back('S');
		Y-=x;
		if(X==0&&Y==0) return true;
		return false;
	}
	bool E(__int64 x){
		A.push_back('E');
		X+=x;
		if(X==0&&Y==0) return true;
		return false;
	}
	bool W(__int64 x){
		A.push_back('W');
		X-=x;
		if(X==0&&Y==0) return true;
		return false;
	}
	
};


std::string solve(PROBLEM &p)
{
	std::vector<PT> table;
	PT x;
	x.X = -p.X;
	x.Y = -p.Y;
	table.push_back(x);
	std::set<PT> ptSet;
	long long int co=1;
	while(true){
		std::vector<PT> table2=table;
		table.clear();
		for(auto i=table2.begin();i!=table2.end();++i){
			PT n = *i;
			if(n.N(co)){return n.A;};
			PT s = *i;
			if(s.S(co)){return s.A;};
			PT e = *i;
			if(e.E(co)){return e.A;};
			PT w = *i;
			if(w.W(co)){return w.A;};
			if(ptSet.insert(n).second){
				table.push_back(n);
			}
			if(ptSet.insert(s).second){
				table.push_back(s);
			}
			if(ptSet.insert(e).second){
				table.push_back(e);
			}
			if(ptSet.insert(w).second){
				table.push_back(w);
			}
		}
		++co;
	}
	return "";
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