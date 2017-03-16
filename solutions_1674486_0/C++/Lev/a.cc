#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <complex>
#include <iomanip>

using namespace std;

int print_dbg = 1;

#define d_print(x) { if(print_dbg){  cerr << __LINE__ << " " << #x << " = " << x << endl; cerr.flush(); } }

typedef vector<string> vecs;
typedef vector<int> veci;
typedef unsigned long long ull;
typedef long long ll;

#define ALL(x) (x).begin(), (x).end()
#define IN(x,y) ((x).find((y)) != (x).end())
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();++(_it))


vector<string> expand( const string & input, string delimiters = " \t")
{
	#define string_find(del,k) ((del).find((k)) != string::npos)
	vector<string> out;
	size_t begin = 0;
	size_t i;
	for( i = 0; i < input.length( ); i++ )
	{
		if( i > 0 && string_find( delimiters, input[i] ) && !string_find( delimiters, input[i-1] ) )
		{
			out.push_back( input.substr( begin, i - begin ) );
			begin = i+1 ;
		}
		else
		{
			if( string_find( delimiters, input[i] ) ){ begin = i+1; }
		}
	}
	if( begin < i )
	{
		out.push_back( input.substr( begin ) );
	}
	return out;
}

bool yes( int i, map<int,vector<int> > & G, vector<bool> & visited )
{
	if( G[i].size() == 0 )
	{
	//	return false;
	}
	if( visited[i] ) return true;
	visited[i] = true;
	bool ret = false;
	for( int j = 0; j < G[i].size(); ++j )
	{
		ret |= yes(G[i][j], G, visited );
	}
	return ret;
}


int main( int argc, char ** argv )
{
	int T;
	cin>>T;
	for( int CASE = 1; CASE <= T; ++CASE  )
	{
		int N;
		cin>>N;
		map<int,vector<int> > inh;
		for( int i = 0; i < N; ++i )
		{
			int M;
			cin>>M;
			for( int j = 0; j < M; ++j )
			{
				int m;
				cin>>m;
				inh[i+1].push_back(m);
			}
		}
		bool has_one = false;
		for( int i = 1; i <= N; ++i )
		{
			vector<bool> v(N,false);
			if( yes(i,inh,v))
			{
				has_one = true;
				break;
			}
		}
		cout<<"Case #"<<CASE<<": ";
		if( has_one)
			cout<<"Yes";
		else
			cout<<"No";
		cout<<endl;
	}
}
