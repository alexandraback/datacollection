#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define sc(x) scanf("%d", &x)
#define scl(x) scanf("%I64d", &x)
#define loop(i,s,e) for(int i=s ; i<e ; i++)
#define rep(i,s,e) for(int i=s ; i>=e ; i--)
#define INF 1e6
#define MOD 1000000007  
#define f first
#define s second
#define EPS 1e-6
#define Rd freopen("in.txt", "r", stdin)
#define Wr freopen("out.txt", "w", stdout)
#define PS push_back
#define M_PI           3.14159265358979323846
//#define DFS_WHITE -1
//#define DFS_BLACK 0

int main(){
	Rd;
	Wr;
	int T;
	sc(T);
	loop(t,0,T){
		int r, c, w;
	    sc(r); sc(c); sc(w);
		printf("Case #%d: %d\n", t+1, (int)((w) + ( ceil((double)c/ (double)(w)) - 1) + (c/w)*(r-1) ) );
	}
	return 0;
}