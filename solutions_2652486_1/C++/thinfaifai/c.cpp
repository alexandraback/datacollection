#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
#define LL long long

int r,n,m,k,a[15],now[15],end,ini;
set<LL> s;

void doit(int at,int mi) {
	if (end) return;
	if (at == n) {
		s.clear();
		for (int i=0; i<(1<<(n-ini)); i++) {
			int ti = i;
			ti <<= ini;
			LL pro = 1;
			for (int j=ini; j<n; j++)
				if ((1<<j) & ti) pro *= now[j];
			s.insert(pro);
		}
		int ok = 1;
		for (int i=0; i<k; i++)
			if (s.find(a[i]) == s.end()) { ok = 0; break; }
		if (ok) {
			for (int i=0; i<n; i++) printf("%d",now[i]);
			puts("");
			end = 1;
		}
		return;
	}
	for (int i=mi; i<=m; i++) {
		if (i == 5 || i == 7) continue;
		now[at] = i;
		doit(at+1,i);
	}
}

int c[10];

void calculate() {
	sort(a,a+k);
	memset(c,0,sizeof(c));
	for (int i=0; i<k; i++) {
		int tot = 0;
		for (int j=2; j<=8; j++) {
			int cnt = 0;
			int ti = a[i];
			while (ti%j == 0) {
				ti /= j;
				cnt++; tot++;
			}
			c[j] = max(c[j],cnt);
		}
	}
}

int main() {
	int tc;
	scanf("%d",&tc);
	for (int t=1; t<=tc; t++) {
		printf("Case #%d:\n",t);
		scanf("%d%d%d%d",&r,&n,&m,&k);
		while (r--) {
			end = 0;

			memset(c,0,sizeof(c));
			for (int i=0; i<k; i++) {
				scanf("%d",&a[i]);
				for (int j=2; j<=8; j++) {
					int cnt = 0;
					int ti = a[i];
					while (ti%j == 0) {
						ti /= j;
						cnt++;
					}
					c[j] = max(c[j],cnt);
				}
			}
			int at = 0;
			for (int i=0; i<c[5]; i++) { now[at++] = 5; }
			for (int i=0; i<k; i++) {
				while (a[i]%5 == 0) a[i] /= 5;
			}
			for (int i=0; i<c[7]; i++) { now[at++] = 7; }
			for (int i=0; i<k; i++) {
				while (a[i]%7 == 0) a[i] /= 7;
			}

			//printf("%d %d\n",c[5],c[7]);
			sort(a,a+k);
			for (int i=0; i<k; i++)
				if (a[i] == 2) {
					now[at++] = a[i];
					for (int j=0; j<k; j++)
						if (a[j]%2 == 0) a[j] /= 2;
					break;
				}
			for (int i=0; i<k; i++)
				if (a[i] == 3) {
					now[at++] = a[i];
					for (int j=0; j<k; j++)
						if (a[j]%3 == 0) a[j] /= 3;
					break;
				}

			if (at < 3) {
				calculate();
				while (c[2]+c[3] > n-at && c[8] > 0) {
					//printf("%d %d\n",c[2]+c[3],n-at); fflush(stdout);
					//for (int i=0; i<k; i++) printf("%d ",a[i]); puts("");
					if (c[8] > 0) {
						now[at++] = 8;
						for (int j=0; j<k; j++)
							if (a[j]%8 == 0) a[j] /= 8;
					}
					/*
					else if (c[4] > 0) {
						now[at++] = 4;
						for (int j=0; j<k; j++)
							if (a[j]%4 == 0) a[j] /= 4;
					}
					else if (c[6] > 0) {
						now[at++] = 6;
						for (int j=0; j<k; j++)
							if (a[j]%6 == 0) a[j] /= 6;
					}
					*/
					//for (int i=0; i<k; i++) printf("%d ",a[i]); puts("");
					calculate();
				}
			}

			if (at < 3) {
				for (int i=0; i<n; i++) printf("2");
				puts("");
			}
			else {
				ini = at;
				doit(at,2);
			}
			fflush(stdout);
		}
	}
	return 0;
}
