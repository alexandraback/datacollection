#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) ((int)(a).size())
#define VAR(x) #x ": " << x << " "
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define gcd __gcd
#define x first
#define y second
#define st first
#define nd second
#define pb push_back

using namespace std;

template<typename T> ostream& operator<<(ostream &out, const vector<T> &v){ out << "{"; for(const T &a : v) out << a << ", "; out << "}"; return out; }
template<typename S, typename T> ostream& operator<<(ostream &out, const pair<S,T> &p){ out << "(" << p.st << ", " << p.nd << ")"; return out; }

typedef long long int64;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

namespace ek{
const int N = 2010;
int n, cap[N][N];
int flow[N][N];

int edmonds(int s, int t) {
    int b,e,q[n],p[n],d,FLOW=0;
    REP(i,n) REP(j,n) flow[i][j]=0;
    for(;;) {
        REP(i,n) p[i]=-1;
        for(q[b=e=0]=s;b<=e;b++)
            REP(v,n) 
                if (flow[q[b]][v] < cap[q[b]][v] && p[v]<0)
                    p[q[++e]=v] = q[b];
        if (p[t]<0) break;
        d = cap[p[t]][t] - flow[p[t]][t];
        for(int i=t;i!=s;i=p[i]) d=min(d,cap[p[i]][i]-flow[p[i]][i]);
        for(int i=t;i!=s;i=p[i]) {
            flow[p[i]][i] += d;
            flow[i][p[i]] -= d;
        }
        FLOW += d;
    }
    return FLOW;
}
}

int get_id(map<string, int> &m, string s){
	if(m.find(s) == m.end()){
		int k = SIZE(m);
		m[s] = k;
		return k;
	}
	return m[s];
}

int n;
map<string, int> st, nd;
char buff[33];

void solve(){
	scanf("%d", &n);
	FWD(i,0,2*n+2) FWD(j,0,2*n+2) ek::cap[i][j] = ek::flow[i][j] = 0;
	FWD(i,0,n){
		scanf("%s", buff);
		int u = get_id(st, string(buff));
		scanf("%s", buff);
		int v = get_id(nd, string(buff));
		++ek::cap[u][v+n];
	}
	FWD(i,0,n){
		ek::cap[2*n][i] = 1;
		ek::cap[n+i][2*n+1] = 1;
	}
	ek::n = 2*n+2;
	int r = ek::edmonds(2*n, 2*n+1);
	FWD(i,0,SIZE(st)) if(!ek::flow[2*n][i]) ++r;
	FWD(i,0,SIZE(nd)) if(!ek::flow[n+i][2*n+1]) ++r;
	printf("%d\n", n-r);
	st.clear();
	nd.clear();
}

int main(){
	int zzz;
	scanf("%d", &zzz);
	FWD(zz,1,zzz+1){
		printf("Case #%d: ", zz);
		solve();
	}
	return 0;
}
