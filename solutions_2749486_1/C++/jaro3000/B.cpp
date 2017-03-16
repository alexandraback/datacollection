#include<algorithm>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<deque>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<complex>
using namespace std;

typedef long long LL;
typedef long double LD;

#define dprintf(...) fprintf(stderr, __VA_ARGS__)
// #define dprintf(...)

int cond = 1;
#define DB(X) {if(cond){cerr<<"Line:"<<__LINE__<<", "<<#X<<" = "<<X<<endl;}}

bool ok(LL x, LL y, LL n){
	LL a=n*(n+1)/2;
	return (abs(x) + abs(y) <= a) &&
		(abs(x) + abs(y))%2 == a%2;
};

char dir[1000];
void solve(LL x, LL y, LL n)
{
	if(n == 0) {
		if(x!=0 || y!=0) fprintf(stderr, "ERROR! 0, %lld %lld\n", x, y);
		return;
	}
	if(ok(x+n, y, n-1)){
		dir[n]='W';
		solve(x+n, y, n-1);
	}else if(ok(x-n, y, n-1)){
		dir[n]='E';
		solve(x-n, y, n-1);
	}else if(ok(x, y+n, n-1)){
		dir[n]='S';
		solve(x, y+n, n-1);
	}else if(ok(x, y-n, n-1)){
		dir[n]='N';
		solve(x, y-n, n-1);
	}else fprintf(stderr, "ERROR! not ok at all, x: %lld, y:%lld, n: %lld\n", x,y,n);
};

void go(int C) {
	int q=1;
	LL x, y;
	scanf("%lld %lld", &x, &y);
	while(!ok(x, y, q)) q++;
	dir[q+1]=0;
	solve(x,y,q);
	printf("Case #%d: %s\n", C, dir+1);

};
int main() {
	int T;
	scanf("%d", &T);
	for(int C=1; C<=T; ++C) go(C);
	return 0;
		
}

