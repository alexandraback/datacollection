#include <climits>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <cassert>
#include <fstream>

using namespace std;

#define rep(i,a,b) for(typeof(a) i=(a);i<(b);i++)
#define ll unsigned long long int
#define ii pair<int,int>
#define gi(x) scanf("%d",&x)
#define gl(x) scanf("%lld",&x)
#define CLEAR(x,val) memset(x,val,sizeof(x))
#define SZ(v) (v).size()

template <class T>inline string itos( T n ) {return (n)< 0?"-"+itos(-(n)):(n)<10?(string)("")+(char('0'+(n))):itos((n)/10)+itos((n)%10);}

vector<string> dict;
void load_dict() {
	ifstream fin("garbled_email_dictionary.txt");
	dict.clear();
	while( fin.good() ) {
		string s; fin >> s;
		if( s.size() > 0 ) dict.push_back(s);
	}
	sort(dict.begin()  , dict.end());
}


int isless( string s1 , string s2 ) {
	int sz1 = s1.size() , sz2 = s2.size() , i = 0;
	for(;i<sz1 && i <sz2;i++ ) {
		if( s1[i] == '?' || s1[i]==s2[i] ) continue;
		else break;
	}
	if( i == sz2 && i == sz1 ) return 2;
	if( i == sz1 && (sz2>sz1) ) return 1;
	if( i == sz2 && (sz1>sz2) ) return 0;
	return (s1[i]<s2[i]);	
}

bool isMatch( string s ) {
	int l = 0 , h = dict.size();
	while( l < h ) {
		int mid = (l+h)/2;
		int status = isless( s , dict[mid]); 
		if(  status == 1 ) { h = mid; }
		else if( status == 0 ) l = mid+1;
		else {  return 1; }
	}
	return 0;
}

int dp[5][4002];
string crypt_str;
int CSZ;

int f( int cw , int id ) {
	if( id == CSZ ) return 0;
	int &ret = dp[cw][id];
	if( ret == -1 ) {
		ret =  5000;string s ="";
		rep( i , 0 , 10 ) if( (i+id) < CSZ ) {
			s += crypt_str[i+id];
			if( isMatch(s) ) ret = min( ret , f( min(cw+i+1  , 4) , i+id+1 ) );

			rep( j , (4-cw) , i+1 ) {
				string tmps;
				if( j == 0 ) {
					tmps = "?"+s;
				}
				else tmps = s.substr( 0 , j ) + "?" + s.substr( j+1 );
				if( isMatch(tmps) ) ret = min( ret , 1+f( min( i-j , 4 ) , i+id+1 ) );
			}
			rep( j , (4-cw) , i+1 ) rep( k , j+5 , i+1 ) {
				string tmps;
				if( j == 0 ) {
					tmps = '?'+s.substr( j , (k-j-1) ) + "?" + s.substr( k+1 );
				}
				else tmps = s.substr( 0 , j ) +"?"+s.substr( j+1 , (k-j-1) ) + "?" + s.substr( k+1 );
				if( isMatch( tmps ) ) ret = min( ret , 2+f( min( i-k , 4 ) , i+id+1 ) );
			} 
		}
	}
	return ret;
}
void Solve() {
		CLEAR( dp , -1 );
		cin >> crypt_str;CSZ=crypt_str.size();
		cout << f( 4 , 0 ) << "\n";
}
int main() {
	int T  , cs = 1;
	cin >> T;	load_dict();
	while( cs <= T ) {		cout << "Case #" << cs++ <<": ";
		Solve();
	}
	return 0;
}