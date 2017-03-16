#include<functional>
#include<algorithm>
//#include<iostream>
#include<numeric>
#include<cassert>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
//#include<cmath>
#include<set>
#include<map>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b);i>=(e);--i)
#define FOReach(it,V) for(__typeof((V).begin()) it=(V).begin();it!=(V).end();++it)

#define PB push_back
#define ALL(V) (V).begin(),(V).end()
#define SIZE(V) ((int)(V).size())

#define MP make_pair
#define ST first
#define ND second

#define DBG

#ifdef DBG
	#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
	#define debug(...)
#endif

int stmp;
#define scanf stmp=scanf


const int MAX = 20;
const int INF = 1000000001;

VI res;
bool vis[1<<MAX];
VI K[MAX], R[200];
int T[MAX];
int cnt[200];

int n, k;

bool dfs(int mask) {
	if(mask == (1<<n)-1) return true;
	if(vis[mask]) return false;
	vis[mask] = true;
	VI p;
	REP(i,200)
		if(cnt[i])
			FOReach(it,R[i])
				p.PB(*it);
	sort(ALL(p));
//	printf("mask %d:", mask); FOReach(it,p) printf(" %d", *it); printf("\n");
	FOReach(it,p)
		if(!(mask & (1<<(*it)))) {
			--cnt[T[*it]];
			FOReach(i,K[*it]) ++cnt[*i];
			if(dfs(mask | (1<<(*it)))) {
				res.PB(*it);
				return true;
			}
			++cnt[T[*it]];
			FOReach(i,K[*it]) --cnt[*i];
		}
	return false;
}

int main(int argc, char *argv[]) {
	int Z;
	scanf("%d", &Z);
	FOR(z,1,Z)
	{
		printf("Case #%d: ", z);
		scanf("%d %d", &k, &n);
		res.clear();
		memset(vis, 0, 1<<n);
		memset(cnt, 0, sizeof cnt);
		REP(i,n) K[i].clear();
		REP(i,200) R[i].clear();
		while(k--)
		{
			int a;
			scanf("%d", &a);
			--a;
			++cnt[a];
		}
		REP(i,n)
		{
			int l;
			scanf("%d %d", T+i, &l);
			--T[i];
			R[T[i]].PB(i);
			while(l--)
			{
				int a;
				scanf("%d", &a);
				--a;
				K[i].PB(a);
			}
		}
		if(dfs(0)) {
			reverse(ALL(res));
			FOReach(it,res) printf("%d ", *it+1);
			printf("\n");
		}
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}

