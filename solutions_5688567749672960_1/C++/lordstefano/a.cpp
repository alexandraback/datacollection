#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++ )
#define FORV(it,A) for(vector<int>::iterator it = A.begin(); it!= A.end(); it++)
#define FORS(it,A) for(set<int>::iterator it = A.begin(); it!= A.end(); it++)
#define quad(x) (x) * (x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

#define N 2000000

int dist[N];

char s[1000];
ll rev (ll v){
	int topo = 0;
	while (v){
		s[topo++] = '0' + v%10;
		v /= 10;
	//	printf("v = %d %c\n", v, s[topo-1]);
	}
	s[topo] = '\0';
	ll ret = 0;
	ll mul = 1;
	reverse (s, s+topo);
	f (i, 0, topo){
		ret += mul*(s[i]-'0');
		mul *= 10LL;
	}
	return ret;
}

void bfs (){
	clr (dist, -1);
	dist[1] = 1;
	queue <int> Q; Q.push(1);
	while (!Q.empty()){
		int v = Q.front();
		Q.pop();
		if (v >= N) continue;
		int viz = v+1;
		if (viz < N && dist[viz] == -1){
			dist[viz] = dist[v]+1;
			Q.push(viz);
		}
		viz = rev(v);
		if (viz < N && dist[viz] == -1){
			dist[viz] = dist[v]+1;
			Q.push(viz);
		}
	}
}

bool zero(ll v){
	int topo = 0;
	while (v){
		s[topo++] = '0' + v%10;
		v /= 10;
	}
	s[topo] = '\0';
	for (int i = 0; i < (topo+1)/2; i++){
		if (s[i] != '0') return 0;
	}
	return 1;
}

bool um (ll v){
	int topo = 0;
	while (v){
		s[topo++] = '0' + v%10;
		v /= 10;
	}
	s[topo] = '\0';
	if (s[0] != '1') return 0;
	for (int i = 1; i < (topo+1)/2; i++){
		if (s[i] != '0') return 0;
	}
	return 1;
}

ll nxt (ll v){
	int topo = 0;
	while (v){
		s[topo++] = '0' + v%10;
		v /= 10;
	}
	s[topo] = '\0';
	s[0] = '1';
	for (int i = 1; i < (topo+1)/2; i++){
		s[i] = '0';
	}
	ll ret = 0;
	ll mul = 1;
	f (i, 0, topo){
		ret += mul*(s[i]-'0');
		mul *= 10LL;
	}
	return ret;
}


ll solve (ll n){
	//if (n < N) return dist[n];
	if (n <= 100) return dist[n];
	if (zero(n)){
		return 1+solve(n-1);
	}
	if (um(n)){
		ll x = rev(n);
		if (x == n) return 1+solve(n-1);
		return 1+solve(x);
	}
	ll x = nxt (n);
   	return n-x+solve(x);	

}	



int main (){
	
	bfs();
	
	int tt; cin >> tt;
	f (kase, 1, tt+1){
		ll n; cin >> n;
		printf("Case #%d: %lld\n", kase, solve(n));
	}
	return 0;
}

