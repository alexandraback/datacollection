#include <bits/stdc++.h>
#define M 1010

using namespace std;

int Nxt[M], Sz[M], Ans1, Ans2, Mx[M];

bool is_two[M], Vis[M], has_tail[M], R[M];

int DFS(int x, int Cnt, int fir)
{
	if(is_two[x])
	{
		if(Cnt) Sz[x]++;
		Mx[x] = max(Mx[x], Cnt);
		return 0;
	}
	if(Vis[x] && x == fir) return Ans2 = max(Ans2, Cnt), 0;
	if(Vis[x]) return 0;
	Vis[x] = 1;
	DFS(Nxt[x], Cnt + 1, fir);
	Vis[x] = 0;
}

int main()
{
//	freopen("C-small-attempt2.in", "r", stdin);
//	freopen("C-small1.out", "w", stdout);
	int _;
	scanf("%d", &_);
	for(int s = 1; s <= _; s++)
	{
		int n;
		scanf("%d", &n), Ans1 = Ans2 = 0;
		printf("Case #%d: ", s);
		for(int i = 1; i <= n; i++) scanf("%d", &Nxt[i]);
		for(int i = 1; i <= n; i++) is_two[i] = Nxt[Nxt[i]] == i;
		for(int i = 1; i <= n; i++) R[i] = 1;
		for(int i = 1; i <= n; i++) R[Nxt[i]] = 0;
		memset(Sz, 0, sizeof Sz);
		memset(Mx, 0, sizeof Mx);
		memset(has_tail, 0, sizeof has_tail);
		for(int i = 1; i <= n; i++) DFS(i, 0, i);
		for(int i = 1; i <= n; i++) if(is_two[i]) Ans1 += Mx[i] + Mx[Nxt[i]] + 2;
		printf("%d\n", max(Ans1 / 2, Ans2));
	}
	return 0;
}
