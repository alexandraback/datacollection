#include<bits/stdc++.h>
#define ALL(X)        X.begin(),X.end()
#define FOR(I,A,B)    for(int (I) = (A); (I) <= (B); (I)++)
#define FORW(I,A,B)   for(int (I) = (A); (I) < (B);  (I)++)
#define FORD(I,A,B)   for(int (I) = (A); (I) >= (B); (I)--)
#define FOREACH(I,A)  for(__typeof(A.begin()) I = A.begin(); I != A.end(); ++I)
#define CLEAR(X)      memset(X,0,sizeof(X))
#define SIZE(X)       int(X.size())
#define CONTAIN(A,X)  (A.find(X) != A.end())
#define PB            push_back
#define MP            make_pair
#define X             first
#define Y             second
using namespace std;
typedef signed long long slong;
typedef long double ldouble;
const slong Infinity = 1000000100;
const ldouble Epsilon = 1e-9;

template<typename T, typename U> ostream& operator << (ostream& os, const pair<T,U>&p) { return os << "(" << p.X << "," << p.Y << ")"; }
template<typename T> ostream& operator << (ostream &os, const vector<T>& V) { os << "["; FORW(i,0,SIZE(V)) os << V[i] << ((i==SIZE(V)-1) ? "" : ","); return os << "]"; }
template<typename T> ostream& operator << (ostream &os, const set<T>& S) {os << "("; for(T i: S) os << i << (i==*S.rbegin()?"":","); return os << ")"; }
template<typename T, typename U> ostream& operator << (ostream &os, const map<T, U>& M){os << "{"; for(pair<T,U> i: M) os << i << (i.X==M.rbegin()->X?"":","); return os << "}"; }
template<typename T, typename F> T lbound(T p, T q, F f) { while(p < q) { T r = p+(q-p)/2; if(f(r)) q = r; else p = r+1; } return p; }
template<typename T, typename F> T lboundl(T p, T q, F f) { FOR(i,1,70) { T r = (p+q)/2; if(f(r)) q = r; else p = r; } return p; }

const int MAXN = 5000;

int L, R;
vector<int> G[MAXN];

int A[MAXN];
int B[MAXN];
int TS[MAXN];
int ts;

bool dfs(int v) {
	TS[v] = ts;
	for(int u: G[v]) if(B[u] == 0 or (TS[B[u]] != ts and dfs(B[u]))) {
		A[v] = u;
		B[u] = v;
		return true;
	}
	return false;
}

int matching() {
    FOR(i,1,L) random_shuffle(ALL(G[i]));
    ts = 0;
	int result = 0;
    int improvement = -1;
	while(improvement != 0) {
        improvement = 0;
        ++ts;
		FOR(i,1,L) if(A[i] == 0 and TS[i] != ts and dfs(i)) ++improvement;
        result += improvement;
    }
    return result;
}

void solve(int num)
{
    int N;
    cin >> N;
    FOR(i,0,MAXN-1)
    {
        G[i].clear();
        A[i] = B[i] = TS[i] = 0;
        ts = 0;
    }

    int cnt[2] = {0,0};
    map<string,int> words[2];

    vector<pair<int,int> > V(N+1);

    FOR(i,1,N)
    {
        string s[2];
        int no[2];
        FOR(j,0,1)
        {
            cin >> s[j];
            if(!words[j].count(s[j]))
            {
                cnt[j]++;
                words[j][s[j]] = cnt[j];
            }
            no[j] = words[j][s[j]];
        }
        V[i] = MP(no[0], no[1]);
    }

    L = cnt[0];
    R = cnt[0] + cnt[1];

    FOR(i,1,N)
    {
        G[V[i].X].PB(L + V[i].Y);
        G[L + V[i].Y].PB(V[i].X);
    }

    cout << "Case #" << num << ": " << N + matching() - R << "\n";

}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        solve(i);
    }
}
