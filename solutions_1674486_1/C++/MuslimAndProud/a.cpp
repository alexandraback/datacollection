#include <iostream>
#include <fstream>

#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>

#define All(v)			v.begin(),v.end()

#define REP(i,a,b)		for(i=(int)a ; i<=(int)b ; i++)
#define FOR(i,N)		REP(i,0,N-1)

#define VI				vector<int>
#define VVI				vector<VI>

#define VD				vector<double>
#define VVD				vector<VD>

#define x				first
#define y				second
#define II				pair<int,int>
#define VII				vector<II>
#define VVII			vector<VII>

using namespace std;

int N;
VVI Adj;
VI done;
VI done2;
VI order;
int pos;

void DFS(int u){
	int i,j,k;
	done[u] = 1;
	FOR(i,Adj[u].size())// Adj -> VVI
		if(!done[Adj[u][i]])
			DFS(Adj[u][i]);
	order[pos] = u; // order -> VI
	pos--; // pos -> int
}

bool DFS2(int u){
	int i,j,k;
	bool ret = false;
	FOR(i,Adj[u].size()){
		int v = Adj[u][i];

		if(done2[v])
			return true;
		done[v] = 1;
		done2[v] = 1;
		ret = DFS2(v);
		if(ret)
			break;
	}
	return ret;
}

void TopoSort(){
	int i,j,k;
	done.clear(); done.resize(N);
	order.resize(N);
	pos = N-1;
	FOR(i,N)
		if(!done[i])
			DFS(i);
}

int main(){
	ifstream cin("input.txt");
	ofstream cout("a2.out");
	int T;
	cin >> T;
	int cnt;
	REP(cnt,1,T){
		int i,j,k;
		Adj.clear();

		cin >> N;
		Adj.resize(N);
		FOR(i,N){
			cin >> k;
			Adj[i].resize(k);
			FOR(j,k){
				cin >> Adj[i][j];
				Adj[i][j]--;
			}
			sort(All(Adj[i]));
		}

		done.clear(); done.resize(N);
		order.clear(); order.resize(N);
		TopoSort();

		bool ans = false;
		done.clear(); done.resize(N);
		FOR(i,N){
			int u = order[i];
			if(done[u])
				continue;
			done2.clear(); done2.resize(N);
			done2[u] = 1;
			ans = DFS2(u);
			if(ans)
				break;
		}

		if(ans)
			cout<<"Case #"<<cnt<<": Yes"<<endl;
		else
			cout<<"Case #"<<cnt<<": No"<<endl;
	}
}