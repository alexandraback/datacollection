#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <hash_map>
#include <hash_set>
#include <map>
#include <memory>
#include <numeric>
#include <random>
#include <regex>
#include <set>
#include <stdexcept>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
#define all( cont ) cont.begin(), cont.end()
#define rep( i, n ) for( int i=0; i<n; i++ )
#define repd( i, n, d ) for( int i=0; i<n; i+=d )

const char* inname = "Bs.in";
const char* outname = "Bs.out";


int main( int argc, char** argv )
{
	typedef pair<int,int> pt;
	map<pt, string> ps1, ps2;

	ps1.clear();
	ps2.clear();

	int T;
	freopen( inname, "r", stdin );
	freopen( outname, "w", stdout );

	scanf( "%d", &T );
	for( int iT=1; iT<=T; iT++ ) {
		ps1.clear();
		ps2.clear();

		pt p(0,0);
		string str;
		ps1[pt(0,0)] = string("");
		int n = 500;
		int x, y;
		scanf( "%d %d", &x, &y );
		bool flag;
		for( int in=1; in<=n; in++ ) {
			if( in %2 ) {
				ps2.clear();
			
				flag =false;
				for( map<pt,string>::iterator i=ps1.begin(); i!=ps1.end(); i++ ) {
					p = (*i).first;
					str = (*i).second;
					if( p.first==x && p.second==y ){flag = true; break;}
					ps2[pt(p.first+in,p.second)]=str+"E";
					ps2[pt(p.first-in,p.second)]=str+"W";
					ps2[pt(p.first,p.second+in)]=str+"N";
					ps2[pt(p.first,p.second-in)]=str+"S";
				}
				if( flag ) break;
			}
			else {
				ps1.clear();
			
				flag =false;
				for( map<pt,string>::iterator i=ps2.begin(); i!=ps2.end(); i++ ) {
					p = (*i).first;
					str = (*i).second;
					if( p.first==x && p.second==y ){flag = true; break;}
					ps1[pt(p.first+in,p.second)]=str+"E";
					ps1[pt(p.first-in,p.second)]=str+"W";
					ps1[pt(p.first,p.second+in)]=str+"N";
					ps1[pt(p.first,p.second-in)]=str+"S";
				}
				if( flag ) break;
			}
			
		}
		cout << "Case #" << iT << ": " << str << endl;
	}
}


/*
inline bool IsCon( char c )
{
	switch(c)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return false;
	default:
		return true;
	}
}

int main( int argc, char** argv )
{
	int T;
	//freopen( inname, "r", stdin );
	//freopen( outname, "w", stdout );
	
	char str[1000001];
	int *accum;
	int n;

	int f, b;

	int sum;

	accum = (int*)malloc( 1000001*4 );

	scanf( "%d", &T );
	for( int iT=1; iT<=T; iT++ ) {
		printf( "Case #%d: ", iT );
		memset( str, 0, 1000001 );
		scanf( "%s %d", str, &n );

		int len = strlen( str );
		sum = 0;
		for( int i=0; i<len; i++ ){
			if( IsCon(str[i]) ) sum++;
			accum[i] = sum;
		}

		sum = 0;
		
		f = b = 0;
	
		for( int f=0; f<len; f++ ) {
			for( int b=0; b<=f; b++ ) {
				if( b==0 ) {
					if( accum[f] >= n ) sum++;
				}
				else{
					if( accum[f] - accum[b-1]>=n ) sum++;
				}
			}

		}

		printf( "%d\n", sum );
	}
	free( accum );
	return 0;
}*/
