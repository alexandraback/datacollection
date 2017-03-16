#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#ifdef _DEBUG_
	#define debug(...) printf(__VA_ARGS__)
#else
	#define debug(...) (void)0
#endif
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int MAXN=1010;
int F[MAXN];
int N;
VI me[MAXN];

int ans_c;
int lev[MAXN];
int line[MAXN];

int find(int x) {
	int mm=0;
	for(int u:me[x])
		if(lev[u]==-1)
			mm=max(mm, find(u)+1);
	return mm;
}

void DFS(int x,int p,int l) {
	debug("DFS(%d,%d,%d)\n",x,p,l);
	if(lev[x]!=-1) {
		int load=max(x,p);
		if(p==F[x])
			line[load]=max(line[load],(l-1+find(p)));
		else
			ans_c=max(ans_c, l-lev[x]);
		return;
	}
	lev[x]=l;
	DFS(F[x],x,l+1);
}

int main() {
	int all_kase;
	scanf("%d",&all_kase);
	for(int num_kase=1;num_kase<=all_kase;num_kase++) {
		scanf("%d",&N);
		for(int i=1;i<=N;i++)
			me[i].clear();
		for(int i=1;i<=N;i++) {
			scanf("%d",F+i);
			me[F[i]].PB(i);
		}
		ans_c=0;
		fill(line,line+N+1,0);
		for(int i=1;i<=N;i++) {
			fill(lev,lev+N+1,-1);
			DFS(i,0,1);
		}
		int sum=0;
		for(int i=1;i<=N;i++)
			sum+=line[i];
		debug("--%d %d\n",ans_c,ans_a);
		printf("Case #%d: ",num_kase);
		printf("%d\n",max(ans_c,sum));
	}
	return 0;
}
