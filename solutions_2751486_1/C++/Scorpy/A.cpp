#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <utility>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define vi vector<int>
#define rep(i,n) for( int i = 0; i < (n); i++ )
#define forn(i,a,b) for( int i = (a); i < (b); i++ )
#define fi first
#define se second

const int MXN = 1000100;

char s [MXN];

bool cons( char c ){
	return c!='a' && c!='u' && c!='i' && c!='e' && c!='o';
}

ll solve(){
	int n;
	scanf("%s%d", s, &n);
	int len = strlen(s);

	int cnt = 0;
	int lst = -1;

	ll res = 0;

	rep(i,len){
		if(cons(s[i])) cnt++;
		else cnt = 0;
		
		if( cnt>=n ) lst = i - n + 1;
		res += lst + 1;
	}

	return res;
}

int main(){
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int T;
	scanf("%d", &T);

	rep(i,T){
		printf("Case #%d: %lld\n", i+1, solve());
	}
}