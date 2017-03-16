#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cassert>
#include<bitset>

using namespace std;

const int N = 2100;
int nxt[N], to[N], last[N], tot = 0;
int a[N], fa[N], view[N];
int l, r, que[N], f;

void add(int x, int y){
	to[tot] = y;
	nxt[tot] = last[x];
	last[x] = tot;
	tot++;
}

void dfs(int x, int father){
	view[x] = 1;
	fa[x] = father;
	int ed = last[x];
	while(ed != -1){
		if(!view[to[ed]]){
			dfs(to[ed], ed);
		} else {
			if(ed != (father^1)){
				//			printf("%d   %d   %d  %d  ed %d   father %d\n", l, r, x, to[ed], ed, father);
				assert(l == -2 || (x == r && l == to[ed]));
				if(l == -2){
					l = x, r = to[ed];
				}
			}
		}
		ed = nxt[ed];
	}
}

int no(int x, int y){
	int ed = last[x];
	int ret = 1;
	while(ed != -1){
		if(to[ed] != y){
			ret = max(ret, 1 + no(to[ed], x));
		}
		ed = nxt[ed];
	}
	return ret;
}

int main() {
	int TT;
	scanf("%d", &TT);
	for(int cc = 1; cc <= TT; ++cc){
		tot = 0;
		l = r = -2;
		f = 0;
		memset(view, 0, sizeof(view));
		memset(last, -1, sizeof(last));
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			int x;
			scanf("%d", &x);
			x--;
			a[i] = x;
			add(i, x);
			add(x, i);
		}
		int ans = 0, free = 0;
		for(int i = 0; i < n; ++i){
			if(!view[i]){
				l = r = -2;
				dfs(i, -1);
				f = 0;
				que[f++] = l;
				while(que[f - 1] != r){
					int x = que[f - 1];
					que[f++] = to[fa[x] ^ 1];
				}
				ans = max(ans, f);
				if(f == 2){
					free+=no(l, r) + no(r, l);
				}
			}
		}
		ans = max(ans, free);
		printf("Case #%d: %d\n", cc, ans);
	}
	return 0;
}

