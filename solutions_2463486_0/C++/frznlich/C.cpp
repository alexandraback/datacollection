// Template
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define fi first
#define sc second
#define MP make_pair
#define pb push_back
#define PI acos(-1.0) //alternative #define PI (2.0 * acos(0.0))
#define vi vector<int>
#define vii vector<pii>
#define ALL(c) (c).begin(), (c).end()
#define RESET( c,a ) memset( (c), a, sizeof(c) )
#define REP( a,b,c ) for ( int a=b, _c=c; a<_c; ++a )
#define RED( a,b,c ) for ( int a=b, _c=c; a>=_c; --a )
#define REPI( it, c ) for ( __typeof( (c).begin() ) it=(c).begin(); it!=(c).end(); ++it )

const int big = 1000000000;
const double INF = 1e9;
const double EPS = 1e-9;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;

int check(int n){
	stringstream ss, ss2;
	string s;
	ss << n;
	ss >> s;
	int k = s.size();
	REP(i,0,k) if(s[i] != s[k-i-1]) return 0;
	n*=n;
	ss2 << n;
	ss2 >> s;
	k = s.size();
	REP(i,0,k) if(s[i] != s[k-i-1]) return 0;
	return 1;
}

int main(){
	int tc;
	scanf("%d",&tc);
	REP(tci,1,tc+1){
		int ret = 0;
		int a,b;
		scanf("%d%d",&a,&b);
		int x = (int)(sqrt(a));
		if(x*x < a) x++;
		int y = (int)(sqrt(b));
		REP(i,x,y+1){
			if(check(i)) ++ret;
		}
		printf("Case #%d: %d\n",tci,ret);
	}
	return 0;
}
	
