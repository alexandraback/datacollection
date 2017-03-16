#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2e3;

int N, tot, Ans, top, Time, Dfn[MAXN], Low[MAXN], Pre[MAXN], D[MAXN];
int Last[MAXN], Next[MAXN * 2], Go[MAXN * 2];
bool Flag[MAXN];

void Link(int a, int b) {
	Next[++ tot] = Last[a], Last[a] = tot, Go[tot] = b;  
}

void Dfs(int Now) {
	Dfn[Now] = Low[Now] = ++ Time;
	D[++ top] = Now, Flag[Now] = 1;
	int u = Pre[Now];
	if (!Dfn[u]) {
		Dfs(u);
		Low[Now] = min(Low[Now], Low[u]);
	} else if (Flag[u]) Low[Now] = min(Low[Now], Dfn[u]);
	if (Dfn[Now] == Low[Now]) {
		int Cnt = 0;
		while (D[top] != Now) {
			Cnt ++;
			Flag[D[top --]] = 0;
		}
		Ans = max(Ans, Cnt + 1);
		Flag[D[top --]] = 0;
	}
}

int GetChain(int Now, int S) {
	int Ans = S;
	for (int p = Last[Now]; p; p = Next[p])
		if (Go[p] != Pre[Now]) Ans = max(Ans, GetChain(Go[p], S + 1));
	return Ans;
}

bool Judge(int Now) {
	return (Pre[Pre[Now]] == Now);
}

int main() {
	freopen("C.in", "r", stdin), freopen("C.out", "w" ,stdout);
	
	int Test;
	scanf("%d", &Test);
	for (int Num = 1; Num <= Test; Num ++) {
		tot = 0;
		Ans = 0;
		memset(Last, 0, sizeof Last);
		memset(Dfn, 0, sizeof Dfn);
		scanf("%d", &N);
		for (int i = 1; i <= N; i ++) {
			scanf("%d", &Pre[i]);
			Link(Pre[i], i);
		}
		for (int i = 1; i <= N; i ++) if (!Dfn[i]) Dfs(i);
		int Sum = 0;
		for (int i = 1; i <= N; i ++) if (Judge(i)) Sum += GetChain(i, 1);
		printf("Case #%d: %d\n", Num, max(Ans, Sum));
	}
}