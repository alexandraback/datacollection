// #includes {{{
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
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
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
//#define IFOR(i,it,c) for(__typeof((c).begin())it=(c).begin();it!=(c).end();++it,++i)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair
//#define PB push_back
#define CLEAR(c,d) memset((c),(d),sizeof(c))
#define TO_STRING(VariableName) # VariableName
//#define DB(c) cout<<TO_STRING(c)<<"="<<(c)<<endl

#define EXIST(e,s) ((s).find(e)!=(s).end())
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define debug2(x) cerr << #x << " = [";REP(__ind,(x).size()){cerr << (x)[__ind] << ", ";}cerr << "] (L" << __LINE__ << ")" << endl;

#define clr(a) memset((a),0,sizeof(a))
#define nclr(a) memset((a),-1,sizeof(a))
#define pb push_back

typedef long long Int;
typedef unsigned long long uInt;
typedef long double rn;

typedef pair<int,int> pii;
//{{{ io
struct IO{ }io;//dummy
#define endl "\n"
IO& operator>>(IO &io,int &n){scanf("%d",&n);return io;}
IO& operator>>(IO &io,unsigned int &n){scanf("%u",&n);return io;}
IO& operator>>(IO &io,long long &n){scanf("%lld",&n);return io;}
IO& operator>>(IO &io,unsigned long long &n){scanf("%llu",&n);return io;}
IO& operator>>(IO &io,double &n){scanf("%lf",&n);return io;}
IO& operator>>(IO &io,long double &n){scanf("%Lf",&n);return io;}
IO& operator>>(IO &io,char *c){scanf("%s",c);return io;}
IO& operator>>(IO &io,string &s){
    char c;s.clear();
    while(isspace(c=getc(stdin))){if(c==-1)return io;}
    do{
        s.push_back(c);
    }while(!isspace(c=getc(stdin)));
    if(c!=-1)ungetc(c,stdin);
    return io;
}
IO& operator<<(IO &io,const int &n){printf("%d",n);return io;}
IO& operator<<(IO &io,const unsigned int &n){printf("%u",n);return io;}
IO& operator<<(IO &io,const long long &n){printf("%lld",n);return io;}
IO& operator<<(IO &io,const unsigned long long &n){printf("%llu",n);return io;}
IO& operator<<(IO &io,const double &n){printf("%lf",n);return io;}
IO& operator<<(IO &io,const long double &n){printf("%Lf",n);return io;}
IO& operator<<(IO &io,const char c[]){printf("%s",c);return io;}
IO& operator<<(IO &io,const string &s){
    REP(i,s.size())putc(s[i],stdout);
}
//}}}
// }}}
typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;


void visit(const Graph &g, int v, vector< vector<int> >& scc,
    stack<int> &S, vector<bool> &inS,
    vector<int> &low, vector<int> &num, int& time) {
  low[v] = num[v] = ++time;
  S.push(v); inS[v] = true;
  FOR(e, g[v]) {
    int w = e->dst;
    if (num[w] == 0) {
      visit(g, w, scc, S, inS, low, num, time);
      low[v] = min(low[v], low[w]);
    } else if (inS[w])
      low[v] = min(low[v], num[w]);
  }
  if (low[v] == num[v]) {
    scc.push_back(vector<int>());
    while (1) {
      int w = S.top(); S.pop(); inS[w] = false;
      scc.back().push_back(w);
      if (v == w) break;
    }
  }
}
void stronglyConnectedComponents(const Graph& g,
    vector< vector<int> >& scc) {
  const int n = g.size();
  vector<int> num(n), low(n);
  stack<int> S;
  vector<bool> inS(n);
  int time = 0;
  REP(u, n) if (num[u] == 0)
    visit(g, u, scc, S, inS, low, num, time);
}


int N;
int f[1010];
int vis[1010],invalid[1010];
vector<vector<int> > rev;

int bfs(int u,int step=0){
	if(vis[u] or (step>0 and invalid[u]))return -1;
	vis[u]=1;
	int t = 0;
	REP(i,rev[u].size()){
		int r = bfs(rev[u][i],step+1);
		if(r==-1)continue;
		t = max(r+1,t);
	}
	return t;
}

void main2(){
	memset(vis,0,sizeof(vis));
	memset(invalid,0,sizeof(invalid));
	int ans = 0;
	cin>>N;
	rev.clear();
	rev.assign(N,vector<int>());
	REP(i,N)cin>>f[i],f[i]--;
	REP(i,N)rev[f[i]].push_back(i);
	Graph g(N);
	REP(u,N)g[u].push_back(Edge(u,f[u],1));
	vector<vector<int> > scc;
	stronglyConnectedComponents(g,scc);
	int sum = 0;
	REP(i,scc.size()){
		if(scc[i].size()>2){
			ans=max(ans,(int)scc[i].size());
		}else if(scc[i].size()==2){
//			cout<<"found: "<<scc[i][0]<<" "<<scc[i][1]<<endl;
			invalid[scc[i][0]]=invalid[scc[i][1]]=1;
			int b0 = bfs(scc[i][0])+1;
			int b1 = bfs(scc[i][1])+1;
//			cout<<"result: "<<b0<<" "<<b1<<endl;
			sum += b0+b1;
		}else{
			
		}
	}
//	cout<<sum<<" "<<ans<<endl;
	ans = max(ans,sum);
	cout<<ans<<endl;
}

//{{{ main function
int main() {
	int T;scanf("%d", &T);
	REP(ct, T){ printf("Case #%d: ",ct+1);main2();}
	return 0;
}
//}}}

