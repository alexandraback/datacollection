#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXK = 210;
const int MAXN = 25;

int InitKeys, n;
int inikeys[MAXK];
bool open[MAXN];
int T[MAXN]; int tot[MAXN], g[MAXN][500];
int f[1<<22];

void init() {
	cin>>InitKeys>>n;
	memset(inikeys, 0, sizeof(inikeys));
	for (int i = 0; i < InitKeys; i ++) {
		int x;
		cin >> x;
		inikeys[x] ++;
	}
	memset(g, 0, sizeof(g));
	for (int i = 0; i < n; i ++) {
		cin >> T[i];
		cin >> tot[i];
		for (int j = 0; j < tot[i]; j ++) {
			cin>>g[i][j];
		}
	}
	/*
	fprintf(stderr,"\n");
	for (int i = 0; i < InitKeys; i ++)
		fprintf(stderr, "%d ", inikeys[i]);
	fprintf(stderr, "\n");
	for (int i = 0; i < n; i ++) {
		fprintf(stderr, "T[%d] = %d, tot=%d: ", i, T[i], tot[i]);
		for (int j = 0; j < tot[i]; j ++)
			fprintf(stderr, "%d ", g[i][j]);
		fprintf(stderr, "\n");	
	}*/
}

int search(int state) {
	if (f[state] != -1) return f[state];
	
	int haskey[MAXK];
	for (int i = 1; i <= MAXK; i ++) haskey[i] = inikeys[i];
	for (int i = 0; i < n; i ++) {
		if (state&(1<<i)) {
			for (int j = 0; j < tot[i]; j ++)
				haskey[g[i][j]] ++;
			haskey[T[i]] --;
		}
	}
		
	for (int i = 0; i < n; i ++) {
		if (!(state&(1<<i))) {
			if (haskey[T[i]] > 0) {
				int newstate = (state | (1<<i));
				int ret = search(newstate);
				if (ret > -1) {
					f[state] = i;
					return f[state];
				}
			}
		}
	}
	f[state] = -2;
	return f[state];
}

void work() {
	memset(f, -1, sizeof(f));
	f[(1<<n)-1] = 0;
	search(0);
	if (f[0] == -2) 
		printf("IMPOSSIBLE");
	else {
		int s = 0;
		for (int step = 0; step < n; step ++) {
			int act = f[s];
			printf("%d",act+1);
			if (step != n-1) printf(" ");
			s = (s | (1<<act));
		}	
	}
}

int main() {
	freopen("D-small.in","r",stdin);
	freopen("D-small.out","w",stdout);
	
	int T;
	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti ++) {
		printf("Case #%d: ", ti);
		init();
		work();
		printf("\n");
		fprintf(stderr,"Case %d done.", ti);
	}
}
