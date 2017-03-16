#include<cstdio>
#include<iostream>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<iomanip>
#include<fstream>
#include<ctime>
using namespace std;
typedef vector<int> VI;
typedef pair <int,int> ii;
typedef long long LL;
#define pb push_back
const int INF = 2147483647;
const int N = 102;

int q,z,kmp[N],k,l,s,tab1[N], tab2[N], pass[N][N], next, i, j, d, maxx, m, sx;
double P[N][N], res;
char t1[N], t2[N];
bool bad, contains;

void dokmp() {
     int i, s;
     kmp[1] = kmp[0] = s = 0;
     for (i=2;i<=l;i++) {
		while (s > 0 && tab2[s] != tab2[i-1]) s = kmp[s];
        if (tab2[s] == tab2[i-1]) s++;
        kmp[i] = s;
//        printf("%d %d\n", i, kmp[i]);
	}
}

int main() {
scanf("%d", &z);
for (q=1;q<=z;q++) {
	scanf("%d %d %d",&k, &l, &s);
	scanf("%s %s", t1, t2);
	for (i=0;i<k;i++) tab1[i] = t1[i] - 'A';
	for (i=0;i<l;i++) tab2[i] = t2[i] - 'A';
	bad = false;
	for (i=0;i<l;i++) {
		contains = false;
		for (j=0;j<k;j++) if (tab2[i] == tab1[j]) contains = true;
		if (!contains) bad = true;
	}
	if (bad) {
		printf("Case #%d: 0.0\n", q);
		continue;
	}
	dokmp();
	d = l - kmp[l];
	maxx = 1 + (s - l) / d;
//	printf("%d\n", maxx);
	for (j=0;j<l;j++) {
		for (m=0;m<k;m++) {
			if (tab2[j] == tab1[m]) pass[j][m] = j + 1;
			else {
				sx = kmp[j];
				while (sx > 0 && tab2[sx] != tab1[m]) sx = kmp[sx];
				if (tab2[sx] == tab1[m]) sx++;
				pass[j][m] = sx;
			}
//			printf("%d %d\n",)
		}
	}
	res = 0.0;
	for (j=1;j<=l;j++) P[0][j] = 0.0;
	P[0][0] = 1.0;
	for (i=1;i<=s;i++) {
		for (j=0;j<=l;j++) P[i][j] = 0.0;
		for (j=0;j<l;j++) {
			for (m=0;m<k;m++) {
				next = pass[j][m];
//				printf("%d\n",next);
				if (next == l) {
					res += P[i-1][j] * 1.0 / k;
					next = kmp[l];
				}
				P[i][next] += P[i-1][j] * 1.0 / k;
			}
		}
//		printf(" %d %.3lf\n",i, res);
//		for (j=0;j<l;j++) printf("%d %.3lf\n",j, P[i][j]);
	}
	printf("Case #%d: %.9lf\n", q, maxx - res);
}
return 0;
}

