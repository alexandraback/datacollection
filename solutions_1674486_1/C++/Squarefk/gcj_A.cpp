#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
const int MaxN= 1111, inf= ~0u>>3;
const char ans[2][5]= {
	"No",
	"Yes"
};
int T, N, CaseCount, flag= 1, hsh[MaxN], L, x, root[MaxN], RES;
struct __node{
	int v;
	__node*nxt;
	__node(int v, __node*nxt) : v(v), nxt(nxt) {}
}*g[MaxN];
void dfs(int x){
	hsh[x]= flag;
	for(__node*cur= g[x];cur && !RES;cur= cur->nxt) if(hsh[cur->v]!=flag)
		dfs(cur->v);
	else
		RES= 1;
}
bool check(){
	RES= 0;
	for(int i= 1;i<= N;++ i)
		if(root[i]){
			++ flag;
			dfs(i);
			if(RES)
				return 1;
		}
	return 0;
}
int main(){
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	scanf("%d", &T);
	while(T --){
		memset(g, 0, sizeof g);
		memset(root, 1, sizeof root);
		scanf("%d", &N);
		for(int i= 1;i<= N;++ i){
			scanf("%d", &L);
			while(L --){
				scanf("%d", &x);
				g[i]= new __node(x, g[i]);
				root[x]= 0;
			}
		}
		printf("Case #%d: %s\n", ++ CaseCount, ans[check()]);
	}
}
