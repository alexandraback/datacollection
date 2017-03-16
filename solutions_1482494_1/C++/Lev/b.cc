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

bool cmp(const pair<int,int> & a, const pair<int,int> & b )
{
	//return (a.second-a.first) < (b.second-b.first);
	//if( a.first == b.first )
	{
		return a.second > b.second;
	}
	return a.first < b.first;
	//if( a.second == b.second ) return a.first > b.first;
	//return a.second< b.second;
}


int main( int argc, char ** argv )
{
	int T;
	cin>>T;
	for( int CASE=1; CASE<=T; ++CASE)
	{
		int N;
		cin>>N;
		vector<pair<int,int> > S;
		for( int i = 0; i < N ; ++i )
		{
			int A,B;
			cin>>A>>B;
			S.push_back(make_pair(A,B));
		}
		sort(ALL(S),cmp);
		//cout<<"===="<<endl;
		for( int i =0; i < N; ++i )
		{
			//cout<<S[i].first<<" : "<<S[i].second<<endl;
		}

		vector<int> C(N,0);
		int stars = 0;
		int num = 0;
		while(true)
		{
			bool done = true;
			int lev = -1;
			for( int i = 0; i < N; ++i )
			{
				if( C[i] == 2 )
					continue;
				if( stars >= S[i].second )
				{
			//		cout<<"2 star "<<i<<" with "<<stars<<endl;
					++num;
					stars += 2 - C[i];
					C[i] = 2;
					done = false;
					break;
				}
			}
			if(!done)continue;
			for( int i = 0; i < N; ++i  )
			{
				if( C[i] == 2 ) continue;
				if( stars >= S[i].first && C[i] == 0)
				{
				//	cout<<"1 star "<<i<<" with "<<stars<<endl;
					++num;
					stars += 1;
					C[i] = 1;
					done = false;
					break;
				}
			}
			if( done ) break;
		}
		for( int i = 0; i < N; ++i )
		{
			if( C[i] != 2 )
			{
				num = -1;
				break;
			}
		}
		cout<<"Case #"<<CASE<<": ";
		if( num == -1 )
			cout<<"Too Bad";
		else cout<<num;
		cout<<endl;

	}
}
