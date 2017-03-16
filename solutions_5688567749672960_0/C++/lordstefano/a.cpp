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
int rev (int v){
	int topo = 0;
	while (v){
		s[topo++] = '0' + v%10;
		v /= 10;
	//	printf("v = %d %c\n", v, s[topo-1]);
	}
	s[topo] = '\0';
	return atoi(s);
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


int main (){
	//cout << rev(100) << endl;
	bfs();
	int tt; cin >> tt;
	f (kase, 1, tt+1){
		int n; cin >> n;
		printf("Case #%d: %d\n", kase, dist[n]);
	}
	return 0;
}

