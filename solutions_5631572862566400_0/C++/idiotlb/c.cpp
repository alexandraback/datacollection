#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e4+10;
int T, n, tot, dfncount, top, ans, ans2;
int a[N], Last[N], dfn[N], low[N], stack[N];
bool b[N];
struct Edge{
	int to, next;
	Edge(int X = 0, int Y = 0){to = X, next = Y;}
} E[N*10];

void Link(int x, int y){
	E[++ tot] = Edge(y, Last[x]); Last[x] = tot;
}

void Tarjan(int x){
	dfn[x] = low[x] = ++ dfncount;
	stack[++ top] = x;
	b[x] = 1;
	
	if(!dfn[a[x]]){
		Tarjan(a[x]);
		low[x] = min(low[x] , low[a[x]]);
	} 
	else if(b[a[x]]) low[x] = min(low[x] , dfn[a[x]]);
	
	if(dfn[x] == low[x]){
		int sum = 0;
		int stacktop;
		do {
			b[top] = 0;
			stacktop = stack[top --];
			sum ++;
		} while(stacktop != x);
		ans = max(ans, sum);
	}
}

int Dfs(int x, int y){
	int ret = y;
	for(int p = Last[x]; p; p = E[p].next)
		if(E[p].to != a[x]) 
			ret = max(ret, Dfs(E[p].to, y + 1));
	return ret;
}

void Work(){
	memset(dfn, 0, sizeof(dfn));
	memset(Last, 0, sizeof(Last));
	memset(b, 0, sizeof(b));
	ans = 0;
	tot = top = dfncount = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		scanf("%d", &a[i]);
		Link(a[i], i);
	}
	for(int i = 1; i <= n; i ++)
		if(!dfn[i]) Tarjan(i);
	
	int ans2 = 0;
	for(int i = 1; i <= n; i ++) 
		if(a[a[i]] == i) ans2 += Dfs(i, 1) + Dfs(a[i],1);
	printf("%d\n", max(ans, ans2/2));
}

int main(){
	//freopen("c.in", "r", stdin), freopen("c.out", "w", stdout);
	
	scanf("%d", &T); int t = 0;
	while(T --){
		t ++;
		printf("Case #%d: ", t);
		Work();
	}
	
	return 0;
}