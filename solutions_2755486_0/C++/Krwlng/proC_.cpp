#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<climits>
#include<algorithm>
#include<map>
using namespace std;

#define LST 300
#define MST 1010
#define N 1010
int h[MST], th[MST], day[N], lst[N], mst[N], str[N], seq[N];
int n, m;

int cmp(const int &i, const int &j) { return day[i]<day[j]; }
int getmax(int x, int y) { return x>y?x:y; }

void conduct() {
	int i, j, td, tn, tx, ty, ts, dd, dl, ds, ans;
	scanf("%d", &n);
	memset(h, 0, sizeof(h)); memset(th, 0, sizeof(th));
	for (m=i=0; i<n; ++i) {
		scanf("%d%d%d%d%d%d%d%d", &td, &tn, &tx, &ty, &ts, &dd, &dl, &ds);
		day[m]=td; lst[m]=tx+LST; mst[m]=ty+LST; str[m]=ts; m++;
		for (j=1; j<tn; ++j) {
			day[m]=day[m-1]+dd; lst[m]=lst[m-1]+dl;
			mst[m]=mst[m-1]+dl; str[m]=str[m-1]+ds;
			m++;
		}
	}
	for (i=0; i<m; ++i) seq[i]=i; sort(seq, seq+m, cmp);
//	for (i=0; i<m; ++i) {
//		printf("day:%d lst:%d mst:%d, str:%d\n", day[seq[i]], lst[seq[i]], mst[seq[i]]-1, str[seq[i]]);
//	}
	for (ans=i=0; i<m; ++i) {
		if (i && day[seq[i]]!=day[seq[i-1]]) for (j=0; j<MST; ++j) h[j]=th[j];
		for (j=lst[seq[i]]; j<mst[seq[i]]; ++j) if (h[j]<str[seq[i]]) break;
		if (j==mst[seq[i]]) continue;
		ans++;
		for (j=lst[seq[i]]; j<mst[seq[i]]; ++j) if (h[j]<str[seq[i]]) th[j]=getmax(th[j], str[seq[i]]);
	}
	printf("%d\n", ans);
}

int main() {
	int time; scanf("%d", &time);
	for (int i=1; i<=time; ++i) {
		printf("Case #%d: ", i);
		conduct();
	}
	return 0;
}
