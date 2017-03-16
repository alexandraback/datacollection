#include<stdio.h>

int que[2000000], i, h, t, D[2000000], N, M,T;

void inque(int x){
	que[t++] = x;
}

void outque(int &x){
	x = que[h++];
}

void bfs(int x){
	h = 0;
	t = 0;
	inque(x);
	if (x == N)return;
	while (h != t){
		outque(x);
		if (M < x + 1)M = x + 1;
		if (D[x + 1] == 0){
			D[x + 1] = D[x] + 1;
			inque(x + 1);
			if (x + 1 == N)break;
		}
		int pos = 0,P=x;
		while (x != 0){
			 pos *= 10;
			 pos += (x % 10);
			 x /= 10;
		}
		if (pos > 2000000)continue;
		if (D[pos] == 0){
			D[pos] = D[P] + 1;
			inque(pos);
		}
		if (M < pos)M = pos;
		if (pos == N)break;
	}
}

int main(){
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (int t = 1; t <= T; t++){
		M = 0;
		scanf("%d", &N);
		D[1] = 1;
		bfs(1);
		printf("Case #%d: %d\n", t, D[N]);
		for (i = 1; i <= M; i++)D[i] = 0;
	}
	return 0;
}