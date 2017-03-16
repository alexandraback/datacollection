
//by allenlyh
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <complex>

using namespace std;

typedef long long LL;

#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define sqr(x) (x)*(x)
#define sign(x) (((x)<-eps)?-1:(x)>eps)
#define foreach(ite,s) for (__typeof(s.begin()) ite=s.begin();ite!=s.end();ite++)
#define lowbit(x) ((x) & (-(x)))
const double eps=1e-6;
const int INF=0x3f3f3f3f;

const int maxn=1000+10;
int n;
double a[maxn];
double b[maxn];
int ansy,ansz;

int check(int st) {
	int res = n;
	res -= st;
	for (int i=st,p=0;i<n;i++,p++) {
		if (sign(a[i] - b[p]) == -1) res--;
	}
	return res;
}

void work() {
	scanf("%d", &n);
	for (int i=0;i<n;i++) scanf("%lf", &a[i]);
	for (int i=0;i<n;i++) scanf("%lf", &b[i]);
	sort(a, a+n);
	sort(b, b+n);
//	cout<<endl;
//	for (int i=0;i<n;i++) cout<<a[i]<<' ';cout<<endl;
//	for (int i=0;i<n;i++) cout<<b[i]<<' ';cout<<endl;
	ansy = n;
	for (int i=0, p=0;i<n;i++) {
		if (sign(a[i] - b[p]) == -1) {
			ansy--;
		} else p++;
	}
	ansz = n;
	for (int i=0,p=0;i<n;i++) {
		while (sign(a[i] - b[p]) >= 1 && p < n) p++;
		if (p == n) break;
		ansz--;
		p++;
		if (p == n) break;
	}
	printf("%d %d\n", ansy, ansz);
}

int main() {
	int T;
	int cas=0;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ++cas);
		work();
	}
	return 0;
}
