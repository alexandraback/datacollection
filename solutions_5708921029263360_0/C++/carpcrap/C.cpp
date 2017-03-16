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
	
int x, s, r, t, n;
int w[1005];
int st[1005], en[1005], len[1005];
long double used = 0;
long double available = 0;
void run(){
	int jj,pp,ss,kk;
	cin >> jj >> pp >> ss >> kk;
	int loop = min(ss,kk);
	int sum = jj*pp*loop;
	printf(" %d\n", sum);
	int x,y,z;
	FRE(i,1,jj) FRE(j,1,pp){
		FRE(k,1,loop){
			printf(" %d %d %d\n", i, j, (i+j+k-3)%ss +1);
		}
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for(tt =1; tt<=T; tt++){
		printf("Case #%d:",tt); // standard
		run();
		//printf("\n"); // endline
	}
	return 0;
}
