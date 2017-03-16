#include<bits/stdc++.h>
#define ALL(X)      X.begin(),X.end()
#define FOR(I,A,B)  for(int (I) = (A); (I) <= (B); (I)++)
#define FORW(I,A,B) for(int (I) = (A); (I) < (B);  (I)++)
#define FORD(I,A,B) for(int (I) = (A); (I) >= (B); (I)--)
#define CLEAR(X)    memset(X,0,sizeof(X))
#define PB          push_back
#define MP          make_pair
#define X           first
#define Y           second
using namespace std;
typedef signed long long slong;
typedef long double ldouble;
const slong Infinity = 1000000100;
const ldouble Epsilon = 1e-9;
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T,U>&p) {return os << "(" << p.X << "," << p.Y << ")"; }
template<typename T> ostream& operator << (ostream &os, const vector<T>& V) { os << "["; FORW(i,0,size(V)) os << V[i] << ((i==size(V)-1) ? "" : ","); return os << "]"; }
template<typename T> ostream& operator << (ostream &os, const set<T>& S) {os << "("; for(auto i: S) os << i << (i==*S.rbegin()?"":","); return os << ")"; }
template<typename T, typename U> ostream& operator << (ostream &os, const map<T, U>& M){os << "{"; for(auto i: M) os << i << (i.X==M.rbegin()->X?"":","); return os << "}"; }
template<typename T, typename F> T lbound(T p, T q, F f) { static_assert(is_integral<T>::value, "integral type required"); while(p < q) { T r = p+(q-p)/2; if(f(r)) q = r; else p = r+1; } return p; }
template<typename T, typename F> T lboundl(T p, T q, F f) { static_assert(is_floating_point<T>::value, "floating point type required"); FOR(i,1,70) { T r = (p+q)/2; if(f(r)) q = r; else p = r; } return p; }
template<typename T, typename U> bool contain(T t, U u) { return t.find(u) != t.end(); }
template<typename T> int size(T t) { return t.size(); }

const int MAXN = 100;
int N, M;
vector<int> G[MAXN];
string Q[MAXN];

void read_data()
{
	FORW(i,0,MAXN) G[i].clear();
	scanf("%d %d", &N, &M);
	FOR(i,1,N) cin >> Q[i];
	FOR(i,1,M)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		G[a].PB(b);
		G[b].PB(a);
	}
}

bool V[MAXN];
string r;

void dfs(int v)
{
	V[v] = true;
	r += Q[v];
	while(true)
	{
		int t = -1;	
		for(int u: G[v]) if(!V[u] and (t == -1 or Q[u] < Q[t])) t = u;
		if(t == -1) break;
		else dfs(t);
	}
}

void solve()
{
	string result = "qqq";
	FOR(i,1,N) 
	{
		CLEAR(V);
		r = "";
		dfs(i);
		result = min(result, r);
	}
	cout << result;
}

int main()
{
	int z;
	scanf("%d", &z);
	FOR(_,1,z)
	{
		printf("Case #%d: ", _);
		read_data();
		solve();
		printf("\n");
//		return 0;
	}
	return 0;
}
