#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

#define a(i,j) (a[i*m+j])

const int maxn = 104;
FILE *in, *out;
int n, m, a[maxn*maxn];
int id[maxn*maxn];

int cmp(const void* p, const void* q) {
	return a[*(int*)p]-a[*(int*)q];
}

int bfs(int s, int t, int val) {
	int yes = 1;
	for (int j=0; j < m; j++) {
		if (a(s,j)!=val && a(s,j)!=-1) {
			yes = 0;
			break;
		}
	}
	if (yes == 1) {
		for (int j=0; j < m; j++) a(s,j)=-1;
		return 1;
	}
	yes = 1;
	for (int i=0; i < n; i++) {
		if (a(i,t)!=val && a(i,t)!=-1) {
			yes = 0;
			break;
		}
	}
	if (yes == 1) {
		for (int i=0; i < n; i++) a(i,t)=-1;
		return 1;
	}
	return 0;
}

int solve() {
	int prod = n*m;
	for (int i=0; i < prod; i++) {
		id[i] = i;
	}
	qsort(id, prod, sizeof(id[0]), cmp);
	for (int i=0; i < prod; i++) {
		int s=id[i]/m, t=id[i]%m;
		if (a(s,t)==-1) continue;
		if (!bfs(s,t,a(s,t))) return 0;
	}
	return 1;
}

int main()
{
	in = fopen("jam.in", "r");
	out = fopen("jam.out", "w");
	int T;
	fscanf(in, "%d", &T);
	for (int cc=1; cc <= T; cc++) {
		fprintf(out, "Case #%d: ", cc);
		memset(id, 0, sizeof(id));
		fscanf(in, "%d%d", &n, &m);
		for (int i=0; i < n; i++) {
			for (int j=0; j < m; j++) {
				fscanf(in, "%d", &a(i,j));
			}
		}
		if (solve()) fprintf(out, "YES\n");
		else fprintf(out, "NO\n");
	}
	return 0;
}
