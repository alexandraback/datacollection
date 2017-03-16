#include<cstdio>
#include<cassert>
#include<cstring>
#include<map>
#include<set>
#include<time.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<utility>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include <limits>
   
using namespace std;
  
long long gcd( long long b, long long s ){
    return (s!=0) ? gcd( s, b%s ) : b;
}
  
long long Pow( long long a, long long b, long long c ){
    if( b == 0 ) return 1%c;
    else if( b == 1 ) return a%c;
    else{
        long long A = Pow( a, b/2, c );
        A = (A*A) % c;
        if( b & 1 ) A = (A*a) % c;
        return A;
    }
}

const long long INF = 1e9 + 7;
const long long INF9 = 1e9 + 9;
typedef pair <int, int> ii;

char a[105], t[105];

vector <string> v;

void go( int k, int s, string c ){
	if( s ) {
		for(int i=0; i<k; i++)
			go( k, s-1, c+a[i] );
	}else
		v.push_back( c );
}

double get(string s, int l ){
	double ss = 0;
	for(int i=0; i+l-1<s.length(); i++){
		bool ok = 1;
		for(int j=0; j<l; j++)
			if( s[i+j] != t[j] ) {
				ok = 0;
				break;
			}
		if( ok )
			ss += 1.0;
	}
	return ss;
}

void solve(){
	int k, l, s;
	scanf("%d %d %d", &k, &l, &s);
	scanf("%s", a);
	scanf("%s", t);
	
	v.clear();
	go( k, s, "" );
	double sc = 0.0, mx = 0.0;
	for(int i=0; i<v.size(); i++){
		double ret = get( v[i], l );
		sc += ret;
		mx = max( mx, ret );
	}
	sc /= (double)v.size();
	printf("%.9lf\n", mx-sc);
}

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int R=1; R<=T; R++){
		printf("Case #%d: ", R);
		solve();
	}
}