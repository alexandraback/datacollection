#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<iomanip> 
#include<utility> 
#include<climits>
#include<climits>
#include<cmath>
#include<algorithm>


using namespace std;


#define LL long long int
#define sc1(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d%d", &x, &y)
#define sc3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define pr1(x) printf("%d\n", x)
#define FOR(i, a, n) for(int i=a;i<n;i++)
#define pp pair<int, int>

#define MAX 1000001


LL exp(LL x, LL n) {
	LL result = 1;
	while(n) {
		if(n&1) {
			result = (result * x);
		}
		x = (x*x);
		n >>= 1;
	}
	return result;
}


void func(int k, int c, int s) {
	if(c==1) {
		if(s < k) { printf("IMPOSSIBLE\n"); return; }

		FOR(i, 1, k+1) {
			if(i != 1) putchar(' ');
			printf("%d ", i);
		}
		printf("\n");
	} else {
		if(s < ((k+1)/2)) { printf("IMPOSSIBLE\n"); return; }

		for(int i=1;i<k;i+=2) {
			LL base = (i-1)*exp(k, c-1);

			if(i != 1) putchar(' ');
			printf("%lld", base+(i+1));
		}
		if(k&1) {
			if(k > 1) putchar(' ');
			printf("%lld", exp(k, c));
		}
		printf("\n");
	}	
}


int main() {

	int t, k, c, s;

	sc1(t);
	FOR(i, 1, t+1) {
		sc3(k, c, s);

		printf("Case #%d: ", i);
		func(k, c, s);
	}

	return 0;
}













