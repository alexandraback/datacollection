#include <cstdio>
#include <cstring>
#include <cstdlib>

int T, R, N, M, K;
int lst[3];
int blst[3], bval;
int fq[4] = {1, 1, 2, 6};
int prod[10], nprod[10];

void search(int p, int cnt, int val) {
	if(cnt == N) { // test & calc
		int tval = 0;

		for(int i=0; i<8; i++) {
			nprod[i] = 1;
			if(i & 1) nprod[i] *= lst[0];
			if(i & 2) nprod[i] *= lst[1];
			if(i & 4) nprod[i] *= lst[2];
		}

		for(int k=0; k<K; k++) {
			int tcnt = 0;
			for(int i=0; i<8; i++) {
				if(nprod[i] == prod[k]) {
					tval ++;
					tcnt ++;
				}
			}
			if(tcnt == 0) val = -2;
		}

		//printf("val:%d   %d %d %d\n", tval*val, lst[0], lst[1], lst[2]);

		if(tval*val > bval) {
			for(int i=0; i<3; i++)
				blst[i] = lst[i];
			bval = tval*val;
		}

		return ;
	}
	if(p == M+1) return ;
	for(int cc=0; cc<=(N-cnt); cc++) {
		for(int i=0; i<cc; i++) lst[i+cnt] = p;
		search( p+1, cnt+cc, val/fq[cc] );
	}
}


int main() {

	puts("Case #1:");

	scanf("%d", &T);
	scanf("%d%d%d%d", &R, &N, &M, &K);
	for(int tc=1; tc<=R; tc++) {

		for(int i=0; i<3; i++) lst[i] = 1;

		memset(blst, 0, sizeof(blst));
		bval = -1;
		for(int i=0; i<K; i++) scanf("%d", &prod[i]);
		search(2, 0, fq[N]);
		for(int i=0; i<N; i++) printf("%d", blst[i]);
		puts("");
	}
}
