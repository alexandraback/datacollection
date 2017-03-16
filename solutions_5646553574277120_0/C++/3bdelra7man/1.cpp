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

bool visited[110];
int c, d, v;
vi vec;

void fill(int i, int sum){
	if(i == vec.size()){
		if(sum <= v){
			visited[sum] = 1;			
		}
		return;
	}	
	fill(i+1, sum + vec[i]);
	fill(i+1, sum);
}
int main(){
	Rd;
	Wr;
	int T;
	sc(T); 
	loop(t,0,T){ 
		memset(visited, 0, sizeof visited);
		sc(c); sc(d); sc(v);
		vec.clear();
		vec.resize(d);
		loop(i,0,d){
			sc(vec[i]);
		}
		int ans = 0;
		fill(0, 0);
		while(1){
			bool done = 1;
			loop(i,1,v+1){
				if(!visited[i]) {
					visited[i] = 1;
					ans++;
					vec.PS( i );
					fill(0, 0);			
					done = 0;
				}
			}		
			if(done) break;	
		}
	    printf("Case #%d: %d\n", t+1, ans);
	    //break;
	}
	return 0;
}