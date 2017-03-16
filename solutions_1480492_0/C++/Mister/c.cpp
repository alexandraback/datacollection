#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#define EPS 1e-9
using namespace std;
bool L[55], D[55][55];
int P[55], S[55], ei, N;
double ans;
struct evt {
	int a,b;
	double t;
	bool st;
	void init(int _a,int _b,double _t,bool _st) {
		a = _a; b = _b; t = _t; st = _st;
	}
} E[5005];
bool eq(double a,double b) {
	return (a > b-EPS && a < b+EPS);
}
bool cmp(evt a,evt b) {
	if(!eq(a.t,b.t)) return a.t < b.t;
	return a.st < b.st;
}
void go(int i) {
	if(i == ei) return;
	int a = E[i].a, b = E[i].b;
	if(!E[i].st) {
		D[a][b] = D[b][a] = 0;
		go(i+1);
		D[a][b] = D[b][a] = 1;
		return;
	}
	// check if it's impossible
	for(int j=0;j<N;++j)
		if(D[a][j] && D[b][j]) {
			ans = max(ans,E[i].t);
			return;
		}
	if(L[a] != L[b]) {
		D[a][b] = D[b][a] = 1;
		go(i+1);
		D[a][b] = D[b][a] = 0;
		return;
	}
	// check if we can switch their lanes before the meeting
	bool switcha = 1, switchb = 1;
	for(int j=0;j<N;++j) {
		if(D[a][j]) switcha = 0;
		if(D[b][j]) switchb = 0;
	}
	if(!switcha && !switchb) {
		ans = max(ans,E[i].t);
		// cannot switch, oops.
		return;
	}
	if(switcha && switchb) {
		// both can switch
		L[a] = !L[a];
		D[a][b] = D[b][a] = 1;
		go(i+1);
		L[a] = !L[a];
		L[b] = !L[b];
		go(i+1);
		D[a][b] = D[b][a] = 0;
		L[b] = !L[b];
		return;
	}
	if(switcha && !switchb) L[a] = !L[a];
	else L[b] = !L[b];
	D[a][b] = D[b][a] = 1;
	go(i+1);
	D[a][b] = D[b][a] = 0;
	if(switcha && !switchb) L[a] = !L[a];
	else L[b] = !L[b];
}
int main() {
	int T;
	scanf("%d",&T);
	for(int cn=1;cn<=T;++cn) {
		ans = -1;
		scanf("%d",&N);
		ei = 0;
		for(int i=0;i<N;++i) {
			char ch;
			scanf(" %c%d%d",&ch,&S[i],&P[i]);
			L[i] = (ch == 'L');
			for(int j=0;j<i;++j) {
				if(S[i] == S[j]) {
					if(abs(P[i]-P[j]) < 5) {
						// they must always be in different lanes
						E[ei++].init(i,j,0,1);
						E[ei++].init(i,j,1e100,0);
					}
				}
				else {
					int ii = i, jj = j;
					if(S[jj] < S[ii]) swap(jj,ii);
					double y = (P[ii]-P[jj]+5)/double(S[jj]-S[ii]);
					if(y < 0) continue;
					double x = max(0.0,(P[ii]-P[jj]-5)/double(S[jj]-S[ii]));
					E[ei++].init(i,j,x,1);
					E[ei++].init(i,j,y,0);
				}
			}
		}
		sort(E,E+ei,cmp);
		go(0);
		printf("Case #%d: ",cn);
		if(ans < 0) printf("Possible\n");
		else printf("%.9lf\n",ans);
	}
}
