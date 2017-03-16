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
# define M_PI           3.14159265358979323846
//#define DFS_WHITE -1
//#define DFS_BLACK 0

int rev(int s){
	stringstream ss;
	ss << s;
	string r = ss.str();
	reverse(r.begin(), r.end());
	return atoi( r.c_str() );
}

struct node
{
	int x, step; 
};

bool visited[1000010];

int main(){
	Rd;
	Wr;
	int n, T;
	sc(T);

	queue<node> Q;
	loop(t,0,T){
		while(!Q.empty()) 
			Q.pop();
		memset(visited , 0 , sizeof visited);
		node p;
		p.x = 1;
		p.step = 1;
		Q.push(p);
		visited[1] = 1;
		sc(n);
		while(!Q.empty()){
			p = Q.front();
			Q.pop();
			if(p.x == n){
				printf("Case #%d: %d\n", t+1, p.step);
				break;
			}
			node p1;
			p1.x = rev( p.x );
			p1.step = p.step + 1;
			if( p1.x <= n && p1.x > p.x && visited[ p1.x ] == 0 ){
				Q.push(p1);
				visited[ p1.x ] = 1;
			}

			p1.x = p.x + 1;
			if(visited[ p1.x ] == 0){
				visited[ p1.x ] = 1;
				Q.push(p1);
			}
		}
	}
	return 0;
}