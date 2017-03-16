#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

#define ll long long
#define PII pair<int,int>
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define SIZE(v) (int)v.size()
#define MAX 8000

double C[8000][8000];
int T,cs,X,Y,N;

int main() {
	for(int i=0;i<MAX;++i) C[i][i] = C[i][0] = 1;
	for(int i=1;i<MAX;++i) for(int j=1;j<MAX;++j)
		C[i][j] = (C[i-1][j] + C[i-1][j-1]);

	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	scanf("%d",&T);
	for(cs=1;cs<=T;++cs) {
		scanf("%d%d%d",&N,&X,&Y);
		if(X == 0 && Y == 0) {
			printf("Case #%d: %.10lf\n",cs, 1.);
			continue;
		}
		ll L = abs(X) + abs(Y); L = L / 2 + 1;
		ll LL = L - 1;
		if(2 * L * L - L <= N) {
			printf("Case #%d: %.10lf\n",cs, 1.);
			continue;
		}
		if(2 * LL * LL - LL >= N) {
			printf("Case #%d: %.10lf\n",cs, 0.);
			continue;
		}
		int rest = N - (2 * LL * LL - LL);
		int len = 2 * (L - 1);
		if(rest == len * 2 + 1) {
			printf("Case #%d: %.10lf\n",cs, 1.);
			continue;
		}
		int level = len - abs(X) + 1;
		if(level > rest) {
			printf("Case #%d: %.10lf\n",cs, 0.);
			continue;
		}
		double tot = 0, cnt = 0;
		for(int left=min(len,rest);left>=0;--left) {
			int right = rest - left;
			if(right > len) break;
			tot += C[left+right][right];
			if(X < 0 && left >= level) cnt += C[left+right][right];
			if(X > 0 && right >= level) cnt += C[left+right][right];
		}
		printf("Case #%d: %.10lf\n",cs, cnt / tot);
	}
}