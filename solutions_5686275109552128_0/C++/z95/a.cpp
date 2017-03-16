#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#define FOR(i,n) for(int i=0;i<n;++i)

using namespace std;

int ops[4][4] = {{0,1,2,3},{1,4,3,6},{2,7,4,1},{3,2,5,4}};
/*
 * 1-  0
 * i-  1
 * j-  2
 * k-  3
*/

int next(int x,int y) {
	int a = x&3;
	int b = y&3;
	int sa = x&4;
	int sb = y&4;
	return ops[a][b]^sa^sb;
}


int round_up(int x,int y) {
	return (x/y)+(x%y==0?0:1);
}

int main(void) {
	int t;
	int pole[5000];
	scanf("%d",&t);
	FOR(k,t) {
		int n;
		scanf("%d",&n);
		int ans = 0;
		FOR(i,n) {
			scanf("%d",&pole[i]);
			ans = pole[i]>ans?pole[i]:ans;
		}
		for(int i=1;i<=1000;++i) {
			int sol = 0;
			FOR(j,n) sol+=round_up(pole[j],i)-1;
			sol+=i;
			ans = sol<ans?sol:ans;
		}
		printf("Case #%d: %d\n",k+1,ans);
	}

}