#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define SZ(c) ((int)(c).size())

int cs;
int D[5005];

int N, X, Y;
void output(double ans) {
	printf("Case #%d: %.9f\n", cs, ans);
	fprintf(stderr, "Case #%d: %.9f\n", cs, ans);
}
void solve() {
	int m=0;
	scanf("%d%d%d", &N, &X, &Y);
	for(m=0;m<5000;m++) if(D[m]>N) break;
	int R=N-D[m-1];
	//printf("R=%d, H=%d\n", R, 2*(m-1));
	int lev=(abs(X)+Y)/2+1;
	if(lev<m) { output(1.0); return; }
	if(lev>m) { output(0.0); return; }
	int H = 2*(m-1);
	if(R >= H) {
		int V = R-H;
		R -= 2*V;
		Y -= V;
		if(Y<0) { output(1.0); return; }
	}
	Y++;
	if(Y>H) { output(0.0); return; }
	double sol=0.0, cn=1.0, sol2=0.0;
	/*for(int i=R,j=1;i>=0;i--,j++) {
		if(i>=Y && i<=H && R-i<=H) sol += cn;
		if(i<=H && R-i<=H) sol2 += cn;
		cn=cn*i/j;
	}*/
	for(int i=R,j=1;i>=Y;i--,j++) {
		sol+=cn;
		cn=cn*i/j;
	}
	for(int i=0;i<R;i++) sol/=2.0;
	//output(sol/sol2);
	output(sol);
}
int main(void) {
	int T;
	scanf("%d", &T);
	for(int i=1;i<=5000;i++) D[i] = D[i-1]+2*i-2+2*i-1;
	for(cs=1;cs<=T;cs++) solve();
	return 0;
}
