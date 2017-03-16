#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
using namespace std;

#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define f first
#define s second

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef vector<string> VS;

const int MAX = 1005;

int N,M,K;

int wx[4] = {-1,0,0,1};
int wy[4] = {0,-1,1,0};
bool vis[MAX][MAX];

bool ins(int x, int y){
	if(x>=0 && x<N && y>=0 && y<M) return true;
	return false;
}

int bfs(PII start){
	vector <PII> Q;

	Q.PB(start);

	int cou = 1;
	REP(i,N) REP(j,M) vis[i][j] = false;
	vis[start.first][start.second] = true;

	for(int i=0; i<Q.size(); ++i){
		if(cou == K) break;
		PII now = Q[i];
		for(int j=0; j<4; ++j)
			if(ins(now.first+wx[j],now.second+wy[j]))
				if(!vis[now.first+wx[j]][now.second+wy[j]]){
					Q.PB(MP(now.first+wx[j],now.second+wy[j]));
					vis[now.first+wx[j]][now.second+wy[j]] = true;
					++cou;
					if(cou == K) break;
				}	
	}

	REP(i,N) REP(j,M)
		if(vis[i][j]){
			int c = 0;
			REP(k,4)
				if(ins(i+wx[k],j+wy[k]) && vis[i+wx[k]][j+wy[k]]) ++c;
			if(c == 4) --cou;
		}

	return cou;
}

void testcase(){
	cin >> N >> M >> K;

	int res = N*M;
	REP(i,N) REP(j,M) res = min(res,bfs(MP(i,j)));

	cout << res; 
}

int main(){
	int t;
	cin >> t;

	FOR(i,1,t){
		cout << "Case #" << i << ": ";
		testcase();
		cout << endl;
	}

	return 0;
}

