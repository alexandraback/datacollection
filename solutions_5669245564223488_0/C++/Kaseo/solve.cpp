#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <functional>
#include <iostream>
 
using namespace std;
 
//const int INF = 5003;
const long long INF = 1000000007;
const int MAXN = 100005;
typedef pair <int, int> ii;
//typedef pair <long long, long long> ii;
long long gcd( long long b, long long s ){
    return (s!=0) ? gcd( s, b%s ) : b;
}

string s[105];
int l[105];
int alp[35];

bool can( string &t ){
	memset( alp, 0, sizeof( alp ) );
	char prev = '-';
	int l = t.size();
	for(int i=0; i<l; i++){
		if( prev != t[i] ) {
			if( alp[t[i]-'a'] )
				return 0;
			alp[t[i]-'a'] = 1;
			prev = t[i];
		}
	}
	return 1;
}
 
int main(){ //freopen("in.txt", "r",  stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int R=1; R<=T; R++){
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			cin >> s[i];
			l[i] = s[i].length();
		}

		long long res = 0;
		
		vector <int> v;
		for(int i=0; i<n; i++)
			v.push_back( i );
		
		do{
			
			string t = "";
			for(int i=0; i<n; i++)
				t = t + s[v[i]];	

			if( can( t ) ) ++res;
		}while( next_permutation( v.begin(), v.end() ) ); 
		
		v.clear();

		printf("Case #%d: ", R);
		printf("%lld\n", res);
	}
}  