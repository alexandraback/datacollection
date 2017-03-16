#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int rev(int x) {
	int r = 0;
	while(x) {
		r = r * 10 + x % 10;
		x /= 10;
	}
	return r;
}

int f[2000000];
int rv[2000000];
bool inQ[2000000];
int main() {
	for(int i=0;i<=1000000;++i) {
		f[i] = i+1;
		rv[i] = rev(i);
	}
	queue<int> Q;
	Q.push(1);
	inQ[1] = true;
	f[1] = 1;
	while(!Q.empty()) {
		int x = Q.front();
		Q.pop();
		if( x > 1000000 ) break;
		inQ[x] = false;
		int r = rv[x];
		
		if( f[r] > f[x] + 1 && !inQ[r] ) {
			Q.push(r);
			inQ[r] = true;
			f[r] = f[x] + 1;
		}
		
		if( f[x+1] > f[x]+1 && !inQ[x+1]) {
			Q.push(x+1);
			inQ[x+1] = true;
			f[x+1] = f[x] + 1;
		}
	}
	int T,ics=0;
	scanf("%d",&T);
	while(T--) {
		int x;
		scanf("%d",&x);
		printf("Case #%d: %d\n",++ics,f[x]);
	}
	return 0;
}