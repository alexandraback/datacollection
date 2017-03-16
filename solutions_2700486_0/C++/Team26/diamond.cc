#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

#define MAXN 5000
int t, n, x, y;
long double pas[MAXN][MAXN];
int count(int s) { return (2*s+1)*(s+1); }
long long rec(int n, int l, int r, int lmin, int rmin, int st);

main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    for(int i=0;i<MAXN;i++) for(int j=0;j<MAXN;j++) pas[i][j]=0; //init
    pas[0][0]=1.0;
    for(int i=1;i<MAXN;i++) pas[i][i]=pas[i][0]=pas[i-1][0];
    for(int i=1;i<MAXN;i++) {
	for(int j=1;j<i;j++) pas[i][j] = (pas[i-1][j-1]+pas[i-1][j]);
	}
    scanf("%d", &t);
    for(int test=1;test<=t;test++) {
	scanf("%d %d %d", &n, &x, &y);
	int s = (abs(x) + abs(y))/2; //shell number
	int st = count(s)-count(s-1); //shell total

	long double ans=0;
	if(n <= count(s-1)) ans=0.0;
	else if(n >= count(s)) ans=1.0;
	else if(x==0) ans=0.0; //must be last in shell
	else {
	    n -= count(s-1); //num in this shell
	    long double poss = (1LL<<n); //total poss
	    int lmin=0, rmin=0;
	    if(x<0) lmin=y+1;
	    else rmin=y+1;
	    ans = rec(n, 0, 0, lmin, rmin, st)/poss;
	    }
	printf("Case #%d: %.10Lf\n", test, ans);
	}
    }
		
long long rec(int n, int l, int r, int st) {
    if(n==0) return l>=lmin && r>=rmin;
    long long sum=0;
    if(l < st) sum += rec(n-1,l+1,r,st);
    if(r < st) sum += rec(n-1,l,r+1,st);
    return sum;
    }








	
