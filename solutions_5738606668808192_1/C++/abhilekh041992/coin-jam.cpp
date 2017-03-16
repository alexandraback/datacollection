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
#define MOD 1000000007LL


int getNum(LL x, int n, int base) {
	FOR(num, 2, 100) {
		LL result = 1 % num;
		LL power = base;
		for(int k=0;k<=(n-3);k++) {
			if((1LL<<k) & x) {
				result = (result + power) % num;
			}
			power = (power*base) % num;
		}
		result = (result + power) % num;

		if(!result) return num;
	}
	return 0;
}


bool check(LL x, int n) {
	FOR(base, 2, 11) {
		if(getNum(x, n, base) == 0) return false;
	}
	return true;
}


void printResult(int n, int j) {
	for(LL i = 0;j && (i < (1LL<<(n-2)));i++) {
		if(check(i, n)) {
			j--;
			putchar('1');
			for(int k=n-3;k>=0;k--) {
				if((1LL<<k) & i) putchar('1');
				else putchar('0');
			}
			printf("1 ");

			printf("%d", getNum(i, n, 2));
			FOR(base, 3, 11) {
				printf(" %d", getNum(i, n, base));
			}
			putchar('\n');
		}
	}
}

int main() {

	int t, n, j;

	sc1(t);
	FOR(i, 1, t+1) {
		sc2(n, j);

		printf("Case #%d:\n", i);
		printResult(n, j);
	}
	return 0;
}













