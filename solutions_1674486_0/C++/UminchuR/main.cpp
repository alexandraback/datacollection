#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define M 5002

int f[M];
int g[M];

typedef struct _edge{int to, cap, rev;}edge;
vector<edge> G[M];
int used[M];
int N;

vector<edge> Gd[M];

void add_edge(int from, int to, int cap){
	edge e1, e2;
	e1.cap = cap;
	e1.rev = G[to].size();
	e1.to = to;
	G[from].PB(e1);
	e2.cap = 0;
	e2.rev = G[from].size()-1;
	e2.to = from;
	G[to].PB(e2);
}

int dfs(int S, int F, int flow){
	if(S==F)return flow;
	used[S] = 1;
	for(int i=0; i<Gd[S].size(); i++){
		edge &e = Gd[S][i];
		if(!used[e.to] && e.cap > 0){
			int d = dfs(e.to, F, min(flow, e.cap));
			if(d>0){
				e.cap -= d;
				Gd[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;

}

int max_flow(int S, int T){
	int flow = 0;
	REP(i, N)Gd[i] = vector<edge>(G[i]);
	while(1){
		REP(i, M)used[i] = 0;
		int f = dfs(S,T,2);
		if(f==0)return flow;
		flow += f;
		if(flow >= 2)return flow;
	}
}

void main(int argc, char *argv[]){//GCJTemp
	int Test;
	int flag;
	ifstream ifs("as.in");
	FILE *ofp = fopen("as.out", "w");
	ifs >> Test;
	REP(test, Test){
		REP(i, M)f[i] = 0;
		REP(i, M)g[i] = 0;
		REP(i, M)G[i].clear();
		flag = 0;
		ifs >> N;
		REP(i, N){
			int Mi;
			ifs >> Mi;
			f[i] = Mi;
			REP(j ,Mi){
				int tmp;
				ifs >> tmp;
				tmp--;
				add_edge(i, tmp, 1);
				g[tmp]++;
			}
		}

		REP(i, N){
			REP(j, N){
				if(i == j)continue;
				if(f[i] >= 2 && g[j] >= 2){
					if(max_flow(i, j) >= 2){
						flag = 1;
						break;
					}
				}
			}
			if(flag){
				break;
			}
		}
		if(flag)fprintf(ofp, "Case #%d: Yes\n", test+1);
		else fprintf(ofp, "Case #%d: No\n", test+1);
	}
	fclose(ofp);
}