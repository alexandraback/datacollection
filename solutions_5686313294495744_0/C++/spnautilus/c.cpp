// spnauT
//
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int _b=(b),i=(a);i<_b;++i)
#define ROF(i,b,a) for(int _a=(a),i=(b);i>_a;--i)
#define REP(n) for(int _n=(n);_n--;)
#define _1 first
#define _2 second
#define PB(x) push_back(x)
#define SZ(x) int((x).size())
#define ALL(x) (x).begin(),(x).end()
#define MSET(m,v) memset(m,v,sizeof(m))
#define MAX_PQ(T) priority_queue<T>
#define MIN_PQ(T) priority_queue<T,vector<T>,greater<T>>
#define IO(){ios_base::sync_with_stdio(0);cin.tie(0);}
#define nl '\n'
#define cint1(a) int a;cin>>a
#define cint2(a,b) int a,b;cin>>a>>b
#define cint3(a,b,c) int a,b,c;cin>>a>>b>>c
typedef long long LL;typedef pair<int,int> PII;
typedef vector<int>VI;typedef vector<LL>VL;typedef vector<PII>VP;
template<class A,class B>inline bool mina(A &x,const B &y){return(y<x)?(x=y,1):0;}
template<class A,class B>inline bool maxa(A &x,const B &y){return(x<y)?(x=y,1):0;}

class BipartiteGraph1
{
private:
	int U, V, N, M;
	int en, rit;
	vector<VI> E;
	VI eu, dep, Q, S;
	VI ea, eb, vst;

	int dfs(int x)
	{
		if(eu[x] == -1 && x < U) return 1;
		vst[x] = rit;
		static int y;

		if(x >= U) { // x in V
			for(int e: E[x]) if(e != eu[x]) {
				y = ea[e];
				if(vst[y] == rit-1 && dep[y] == dep[x]-1 && dfs(y)) {
					eu[x] = eu[ea[e]] = e; return 1;
				}
			}
		} else { // x in U and eu[x] != -1
			y = eb[eu[x]];
			if(vst[y] == rit-1 && dep[y] == dep[x]-1 && dfs(y)) return 1;
		}
		return 0;
	}

#define FG3_C1(e) {int y = adj((e), x); if(vst[y] != rit) {vst[y] = rit; dep[y] = dep[x] + 1; Q[tail++] = y;}}

	int bfs()
	{
		++rit;
		int sn = 0;
		int head = 0, tail = 0;
		FOR(i,0,U) if(eu[i] == -1)
		{
			dep[i] = 0;
			vst[i] = rit;
			Q[tail++] = i;
		}
		while(head < tail)
		{
			int x = Q[head];
			if(eu[x] == -1 && x >= U)
			{
				FOR(i,head,tail) if(eu[Q[i]] == -1) S[sn++] = Q[i];
				break;
			}
			++head;
			if(x < U)
			{
				for(int e: E[x]) if(e != eu[x]) FG3_C1(e)
			}
			else FG3_C1(eu[x]) // x in V and eu[x] != -1
		}
		return sn;
	}

public:
	BipartiteGraph1(int u, int v, int m)
	{
		U = u; V = v; N = u+v; M = m; en = 0, rit = 0;
		E.resize(N); eu.resize(N, -1); ea.resize(m); eb.resize(m);
		vst.resize(N, 0); dep.resize(N); Q.resize(N); S.resize(v);
	}
	int adj(int e, int a) const {return a ^ ea[e] ^ eb[e];}
	void addEdge(int a, int b)
	{
		E[a].PB(en);
		E[b+U].PB(en);
		ea[en] = a;
		eb[en] = b+U;
		++en;
	}
	int matching()
	{
		int res = 0, sn;
		while((sn = bfs()) > 0)
		{
			++rit;
			FOR(i,0,sn) res += dfs(S[i]);
		}
		return res;
	}
	VP getPairs()
	{
		int n = 0;
		FOR(i,0,U) n += eu[i] != -1;
		VP P(n);
		n = 0;
		FOR(i,0,U) if(eu[i] != -1) P[n++] = PII(i, adj(eu[i], i)-U);
		return P;
	}
};

#define MAXN (1004)

int X[MAXN];
int Y[MAXN];

int main()
{
	IO();
	cint1(TT);
	FOR(T,1,TT+1)
	{
		map<string,int> AA, BB;
		cint1(N);
		FOR(i,0,N)
		{
			string A, B;
			cin >> A >> B;
			int a, b;
			if(AA.count(A) == 0)
			{
				a = SZ(AA);
				AA[A] = a;
			}
			else a = AA[A];
			if(BB.count(B) == 0)
			{
				b = SZ(BB);
				BB[B] = b;
			}
			else b = BB[B];

			X[i] = a;
			Y[i] = b;
		}

		BipartiteGraph1 G(SZ(AA), SZ(BB), N);
		FOR(i,0,N) G.addEdge(X[i], Y[i]);
		int sol = N + G.matching() - SZ(AA) - SZ(BB);

		cout << "Case #" << T << ": " << sol << nl;
	}

	return 0;
}