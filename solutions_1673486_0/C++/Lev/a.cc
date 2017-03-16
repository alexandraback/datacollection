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

int main( int argc, char ** argv )
{
	int T;
	cin>>T;
	for( int CASE =1 ; CASE <= T; ++CASE)
	{
		int A,B;
		cin>>A>>B;
		vector<double> p;
		for( int i = 0; i < A; ++i )
		{
			double t;
			cin>>t;
			p.push_back(t);
		}
		vector<double> ret(A,0);
		//ret.push_back(p[0]);
		ret[0] = p[0];
		for( int i = 1; i < A; ++i )
		{
			ret[i] = ret[i-1] * p[i];
		}
		double press_enter = 2 + B;
		//double keep_typing = ret[A-1]*(B-A+1) + (1-ret[A-1])*(B-A+2+B);
		double min_exp = press_enter;
		for( int i = 0; i < A; ++i )
		{
			double t = ret[A-1-i]*(B-(A-i)+1+i) + (1-ret[A-1-i])*(B-(A-i)+1+i+B+1);
			min_exp = min(t,min_exp);
		}
		cout<<"Case #"<<CASE<<": ";
		printf( "%6f", min_exp);
		cout<<endl;
	}
}
