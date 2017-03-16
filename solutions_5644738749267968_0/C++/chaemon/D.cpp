// #includes {{{
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cmath>
using namespace std;
// }}}
// pre-written code {{{
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define RREP(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define LET(x,a) __typeof(a) x(a)
//#define IFOR(i,it,c) for(__typeof((c).begin())it=(c).begin();it!=(c).end();++it,++i)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair

#define EXIST(e,s) ((s).find(e)!=(s).end())

#define RESET(a) memset((a),0,sizeof(a))
#define SET(a) memset((a),-1,sizeof(a))
#define PB push_back
#define DEC(it,command) __typeof(command) it=command

const int INF=0x3f3f3f3f;

typedef long long Int;
typedef unsigned long long uInt;
#ifdef __MINGW32__
typedef double rn;
#else
typedef long double rn;
#endif

typedef pair<int,int> pii;

/*
#ifdef MYDEBUG
#include"debug.h"
#include"print.h"
#endif
*/
// }}}

//{{{ Graph
typedef int Weight;
struct Edge {
	int src, dst, rev;
	Weight weight;
	Edge(int src, int dst, Weight weight=1,int rev=-1) :
		src(src), dst(dst), weight(weight), rev(rev) { }
};
bool operator < (const Edge &e, const Edge &f) {
	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
		e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

//add bi-directional edge
void addBiEdge(Graph &g,int from ,int to, Weight w=1){
	while(g.size()<max(from,to)+1)g.push_back(Edges());
	g[from].push_back(Edge(from,to,w,g[to].size()));
	g[to].push_back(Edge(to,from,w,g[from].size()-1));
}
//add directional edge
void addEdge(Graph &g,int from ,int to, Weight w=1){
	while(g.size()<from+1)g.push_back(Edges());
	g[from].push_back(Edge(from,to,w));
}
#ifdef DEBUG
#include"graph/graphviz.h"
#endif
//}}}

//{{{ bipartite Match (hopcroft karp)
bool augment(const Graph &g,int left,const int &n,vector<bool> &visited,vector<int> &levels,vector<int> &matching) {
	if (left == n)return true;
	if (visited[left])return false;
	visited[left] = true;
	REP(i, g[left].size()) {
		int right = g[left][i].dst;
		int next = matching[right];
		if (levels[next] > levels[left] && augment(g,next,n,visited,levels,matching)) {
			matching[right] = left;
			return true;
		}
	}
	return false;
}

int bipartiteMatching(const Graph &g,int n,int m,Edges &ans) {
	vector<bool> matched(n,false),visited;
	vector<int> levels,matching(m,n);
	bool cont;
	do {
		levels.assign(n+1, -1);
		levels[n] = n;
		queue<int> q;
		REP(left, n) {
			if (!matched[left]) {
				q.push(left);
				levels[left] = 0;
			}
		}
		while(!q.empty()) {
			int left = q.front();
			q.pop();
			REP(i, g[left].size()) {
				int right = g[left][i].dst, next = matching[right];
				if (levels[next] < 0) {
					levels[next] = levels[left] + 1;
					q.push(next);
				}
			}
		}
		visited.assign(n, false);
		cont = false;
		REP(left, n)
			if (!matched[left] && augment(g,left,n,visited,levels,matching))
				matched[left] = cont = true;
	} while(cont);
	ans.clear();
	REP(i,m)if(matching[i]!=n)ans.push_back(Edge(matching[i],i));
	return count(ALL(matched), true);
}
//}}}

int N;

rn a[1010],b[1010];

void main2(){
	cin>>N;
	REP(i,N)cin>>a[i];
	REP(j,N)cin>>b[j];

	Graph g(N);
	REP(i,N)REP(j,N)if(a[i]>b[j])addEdge(g,i,j,1);
	Edges ans;
	cout<<bipartiteMatching(g,N,N,ans)<<" ";


	set<rn> x,y;
	REP(i,N)x.insert(a[i]);
	REP(i,N)y.insert(b[i]);
	int ct=0;
	for(set<rn>::reverse_iterator it=x.rbegin();it!=x.rend();it++){
		set<rn>::iterator it2 = y.upper_bound(*it);
		if(it2==y.end()){
			ct++;
			y.erase(y.begin());
		}else{
			y.erase(it2);
		}
	}
	cout<<ct<<endl;
}

// main function {{{
int main() {
	int T;cin>>T;
	REP(ct, T){
		cout<<"Case #"<<ct+1<<": ";
		main2();
	}
	return 0;
}
//}}}
