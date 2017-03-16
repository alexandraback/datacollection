#include <bits/stdc++.h>
using namespace std;

#define bit(n) (1<<(n))

int T, X, R, C;
bool D[21][21][1<<20];
vector < vector<int> > __log__;

void inq(queue <int> &que, int y, int x, int msk)
{
	if (!D[y][x][msk]){
		D[y][x][msk] = 1;
		__log__.push_back({y, x, msk});
		que.push(y); que.push(x); que.push(msk);
	}
}

int main()
{
	int ts = 0;
	for (scanf("%d", &T);T--;){
		printf("Case #%d: ", ++ts);
		scanf("%d%d%d", &X, &R, &C);
		if (X >= 4){ puts("RICHARD"); continue; }
		if (X == 1){ puts("GABRIEL"); continue; }
		if (X == 2){ puts(((R*C)&1) ? "RICHARD" : "GABRIEL"); continue; }
		if (R*C%X){ puts("RICHARD"); continue; }
//		memset(D, 0, sizeof(D));
		queue <int> que;
		inq(que, 0, 0, 0);
		bool ans = 0;
		while (!que.empty()){
			int y = que.front(); que.pop();
			int x = que.front(); que.pop();
			int msk = que.front(); que.pop();
			if (y == R){
				ans = 1;
				break;
			}
			if (x == C){
				for (int i=0;i<=C;i++){
					if (!(msk&bit(i))){
						inq(que, y+1, i, msk);
						break;
					}
					msk ^= bit(i);
				}
				continue;
			}
			if (y+1 < R && x > 0 && !(msk&bit(x)) && !(msk&bit(x-1))){
				int nmsk = msk ^ bit(x) ^ bit(x-1);
				for (int i=x+1;i<=C;i++){
					if (!(nmsk&bit(i))){
						inq(que, y, i, nmsk);
						break;
					}
					nmsk ^= bit(i);
				}
			}
			if (y+1 < R && x+1 < C && !(msk&bit(x))){
				int nmsk = msk ^ bit(x);
				if (!(nmsk&bit(x+1))) nmsk ^= bit(x+1);
				for (int i=x+1;i<=C;i++){
					if (!(msk&bit(i))){
						inq(que, y, i, nmsk);
						break;
					}
					if (i > x+1 && (nmsk&bit(i))) nmsk ^= bit(i);
				}
			}
			if (y+1 < R && x+1 < C && !(msk&bit(x+1))){
				int nmsk = msk ^ bit(x+1);
				for (int i=x+2;i<=C;i++){
					if (!(nmsk&bit(i))){
						inq(que, y, i, nmsk);
						break;
					}
					nmsk ^= bit(i);
				}
			}
			if (y+1 < R && x+1 < C && !(msk&bit(x)) && !(msk&bit(x+1))){
				int nmsk = msk ^ bit(x);
				for (int i=x+2;i<=C;i++){
					if (!(nmsk&bit(i))){
						inq(que, y, i, nmsk);
						break;
					}
					nmsk ^= bit(i);
				}
			}
		}
		for (auto &t: __log__){
			D[t[0]][t[1]][t[2]] = 0;
		}
		__log__.clear();
		puts(ans ? "GABRIEL" : "RICHARD");
	}
}
