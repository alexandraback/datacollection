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

double ans = 0, tot = 0;
int mx = 0; 
string letters, w;
int k, l, s;

int get(string p){
	int c = 0, i;
	for(i = 0; i < p.size(); i++) {
	    int j = 0;
	    for(j = 0; j < w.size() && i + j < p.size(); j++) {
	      if(p[i + j] != w[j]) 
	      	break;	    	
	    } 
    	if(j == w.size()) c++; 
  	}
  	return c;
}

void solve(string p){
	if(p.size() == s){
		int gg = get( p );
		ans += gg;
		mx = max(mx, gg);
		tot++;
		//printf("%s %d\n", p.c_str(), get( p ));
		return;
	}

	loop(i,0,letters.size()){
		solve(p + letters[i]);
	}
}

int main(){
	Rd;
	Wr;
	int T;
	sc(T);
	loop(t,0,T){
		tot = 0;
		ans = 0;
		mx = 0;
	    sc(k); sc(l); sc(s);
	    cin >> letters >> w;
	    solve("");
	    double res = ans / tot;
	    printf("Case #%d: %0.10f\n", t+1, (double)mx - res);
	    //break;
	}
	return 0;
}