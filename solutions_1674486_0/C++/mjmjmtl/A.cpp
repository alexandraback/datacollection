// A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstring>

#define maxn 1010
#define maxm 1000010

struct Nod {
	int b, nxt;
	void init(int b, int nxt) {
		this->b = b;
		this->nxt = nxt;
	}
};
struct Topo {
	int E[maxn];	int n;	//图
	Nod buf[maxm];	int len;//资源
	
	int ans[maxn];			//拓扑排序后的结果
	
	void init(int n) {
		this->n = n;
		memset(E, 255, sizeof(E));
		len = 0;
	}
	void addEdge(int a, int b) {
		buf[len].init(b, E[a]);
		E[a] = len ++;
	}
	//0没解，1有解不唯一，2唯一解
	int solve() {
		static int stk[maxn], dgr[maxn];	//栈，入度
		int stkLen = 0;
		memset(dgr, 0, sizeof(dgr));
		for(int i=0; i<len; i++)	dgr[buf[i].b] ++;
		for(int i=0; i<n; i++)		if(dgr[i]==0)	stk[stkLen ++]=i;
		bool unique = true;
		for(int idx = 0; idx < n; idx ++) {
			if(stkLen == 0)	return 0;
			if(stkLen >= 2)	unique = false;
			int now = stk[-- stkLen];
			ans[idx] = now;
			for(int i = E[now]; i != -1; i = buf[i].nxt)
				if(--dgr[buf[i].b] == 0)	stk[stkLen ++] = buf[i].b;
		}
		return unique+1;	//有解
	}
	bool judge() {
		static bool canReachMe[1010][1010];
		memset(canReachMe, 0, sizeof(canReachMe));
		for(int idx = 0; idx < n; idx ++) {
			int a = ans[idx];
			for(int i = E[a]; i != -1; i = buf[i].nxt) {
				int b = buf[i].b;
				canReachMe[b][a] = true;
				for(int j = 0; j < n; j ++) {
					if(canReachMe[a][j]) {
						if(canReachMe[b][j]) {
							return true;
						}
						canReachMe[b][j] = true;
					}
				}
			}
		}
		return false;
	}
} topo;

bool test() {
	int n, m, tmp;
	scanf("%d", &n);
	topo.init(n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &m);
		while(m --) {
			scanf("%d", &tmp);
			topo.addEdge(i-1, tmp-1);
		}
	}
	if(topo.solve() == 0) {
		printf("NO............\n");
	}
	return topo.judge();
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int idx = 1; idx <= t; idx ++) {
		if(test()) {
			printf("Case #%d: Yes\n", idx);
		} else {
			printf("Case #%d: No\n", idx);
		}
	}
	return 0;
}

