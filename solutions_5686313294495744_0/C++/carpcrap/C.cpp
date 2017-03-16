#include<iostream>
#include<stdio.h>
#include<string.h>
#include <algorithm>
#define FR(i,a,b) for(i=a;i<b;++i)
#define FRS(i,a,b,s) for(i=a;i<b;i+=s)
#define FRE(i,a,b) for(i=a;i<=b;++i)
#define FRES(i,a,b,s) for(i=a;i<=b;i+=s)
// 0->tt-1		FR(i, 0, tt) printf(" 1");
// 0,2,4->tt-1	FRS(i, 0, tt, 2) printf(" 2");
// 0->tt		FRE(i, 0, tt) printf(" 3");
// 0,2,4->tt	FRES(i, 0, tt, 2) printf(" 4");
using namespace std;

int i, j, k;
int tt;
string s[3][1005];

int getOne(int x) {
	int ones = 0;
	for (; x > 0; ones += (x & 1), x = x >> 1);
	return ones;
}

void run(){
	int n;
	cin >> n;
	FR(i, 0, n) cin >> s[0][i] >> s[1][i];
	int maxFake = 0;
	FR(i, 0, 1 << n) {
		int num = getOne(i);
		//printf("@@@ %d\n", i);
		if (maxFake < num) {
			bool ok = true;
			FR(j, 0, n) {
				int first = 0;
				int second = 0;
				if ((i & (1 << j)) > 0) {
					FR(k, 0, n) if (k != j && ((i& (1<<k))==0)) {
						if (s[0][k] == s[0][j]) first++;
						if (s[1][k] == s[1][j]) second++ ;
					}
					if (first == 0 || second == 0) ok = false;
				}
			}
			if (ok) maxFake = num;
			//printf("!!! %d %d %d\n", i, num, maxFake);
		}
	}
	printf(" %d", maxFake);

}

int main(){
	int T;
	scanf("%d", &T);
	for(tt =1; tt<=T; tt++){
		printf("Case #%d:",tt); // standard
		run();
		printf("\n"); // endline
	}
	return 0;
}
