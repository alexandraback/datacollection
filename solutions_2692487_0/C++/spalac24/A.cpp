using namespace std;
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>
#include <iterator>
#include <bitset>
#include <cstdlib>
#include <set>

template <class T> string toStr (T x){stringstream ss;ss << x;return ss.str();}
template <class T> long long toInt (T x){stringstream ss; ss << x; long long r; ss >> r; return r;}


#define FOR(i,a,b) for(int i = (a); i <(b); ++i)
#define foreach(x,v) for(typeof (v).begin() x = v.begin(); x != v.end(); ++x)
#define sz(x) (int)(x).size()
#define DEBUG
#ifdef DEBUG
#define REACH  cout<<" reached line "<<__LINE__<<endl
#define D(x) cout<<#x " is "<<(x)<<endl
#else
#define REACH
#define D(x)
#endif	
#define D2(x) cout<<#x " is "<<(x)<<endl
typedef unsigned long long ull; 

int cases = 0;

const int MAXN = 105;
int memo [MAXN];
int size[MAXN];
int size_u[MAXN];
int a,n;

int f (int m) {
	int tam = size_u[m-1];
	assert(memo[m-1]> -1);
	if (tam > size[m]) {
		size_u[m] =tam + size[m];
		return memo[m] = memo[m-1];
	}
	int ans = 0;
	if (tam == 1) {
		size_u[m]= 1;
		return memo[m] = 1<<30;
	}
	while(tam <= size[m]) {
		tam = 2*tam-1;
		ans++;
	}
	tam += size[m];
	size_u[m] = tam;
	return memo[m] = memo[m-1]+ans;
}

int main (){
	ios::sync_with_stdio(false);
	cin>>cases;
	for (int run = 1; run <= cases; ++run) {
		cout<<"Case #"<<run<<": ";
		memset(memo,-1,sizeof memo);

		cin>>a>>n;
		for(int i = 1; i <= n; ++i) {
			cin>>size[i];
		}
		sort(&size[1],&size[n+1]);
		memo[0] = 0;
		size_u[0] = a;
		int best = n;
		for (int i = 1; i <= n; ++i) {
			best = min(best,f(i)+(n-i));
		}
		cout<<best<<endl;
	}
}
