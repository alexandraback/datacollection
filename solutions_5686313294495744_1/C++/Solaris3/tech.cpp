#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
//#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 1
#define DEB printf
#else
#define DEB(...)
#endif

typedef long long ll;
typedef long long LL;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int mod = 1000000007;
const int MAXN = 1000006;

namespace HK{ //Hopcroft-Karp: O(msqrt(n))
	const int MAXN = 50005;//musi pomiescic c+d
	vector<int> V[MAXN];//krawedzie tylko w jedna strone: od C do D
	int M[MAXN];
	bool odw[MAXN];
	int dist[MAXN];
	queue<int> Q;

	inline bool dfs(int u)
	{
		odw[u]=1;
#define s M[*it]
		tr(it,V[u]) if((s==-1) || (!odw[s] && dist[s]==dist[u]+1 && dfs(s)))
		{
			M[u]=*it;
			M[*it]=u;
			return 1;
		}
		return 0;
	}
	int c,d; //chlopcy 0..c-1, dziewczyny: c..c+d-1
	bool bfs(){
		fru(i,c) odw[i]=0;
		fru(i,c) if(M[i]==-1) {dist[i]=0; Q.push(i);} else dist[i]=-1;
		bool ret=0;
		while(!Q.empty()){
			int u=Q.front(); 
			Q.pop();
			tr(it,V[u]) if(s!=-1 && dist[s]==-1){
				dist[s]=dist[u]+1;
				Q.push(s);
			}
			else if(s==-1) ret=1;
		}
		return ret;
	}
	int matching()
	{
		fru(i,c+d) { odw[i]=0;M[i]=-1;}
		int ret=0;
		while(bfs()) fru(i,c) if(M[i]==-1 && dfs(i)) ++ret;
		fru(i,c)V[i].clear();
		return ret;
	}
}
map<string,int> M1,M2;
void solve() {
	int n;
	scanf("%d",&n);
	vector<pii> E;
	M1.clear();
	M2.clear();
	string s1,s2;
	int nr1=0,nr2=0;
	fru(i,n){
		cin>>s1>>s2;
		int a,b;
		if(M1.find(s1)==M1.end())M1[s1]=nr1++;
		if(M2.find(s2)==M2.end())M2[s2]=nr2++;
		a=M1[s1];b=M2[s2];
		E.pb(pii(a,b));
	}
	HK::c=nr1;
	HK::d=nr2;
	tr(it,E)HK::V[it->x].pb(HK::c+it->y);
	int w=HK::matching();
	printf("%d\n",n-(nr1+nr2-w));
}

int main() {
	int te = 1;
	scanf("%d",&te);
	fru(ti,te) {
		printf("Case #%d: ",ti+1);
		solve();
	}
	return 0;
}
