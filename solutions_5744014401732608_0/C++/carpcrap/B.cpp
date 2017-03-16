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
long long pow[100], num[100];	
void run(){
	long long b, m;
	cin >> b >> m;
	if(m>num[b]) {printf(" IMPOSSIBLE\n"); return;}
	else printf(" POSSIBLE\n");
	bool full = false;
	long long remain = m;
	FR(i,0,b){
		if(full)
		{
			FR(j,0,b) printf("%d", (j>i)?1:0);
		}
		else if(remain >= num[b-1-i])
		{
			full = true;
			FR(j,0,b) {
				if(j<=i) printf("0");
				else if(remain >= num[b-j-1]){
					printf("1"); remain-=num[b-j-1];
				} else printf("0");
			}
		}
		else
		{
			FR(j,0,b) printf("%d",(j==i+1)? 1 :0);
		}
		printf("\n");
	}
}

int main(){
	pow[0] = 1;
	pow[1] = 2;
	FR(i,2,52) pow[i] = pow[i-1]*2;
	num[0] = 1;
	num[1] = 1;
	num[2] = 1;
	num[3] = 2;
	FR(i,3,52) num[i] = num[i-1]*2;
	int T;
	scanf("%d", &T);
	for(tt =1; tt<=T; tt++){
		printf("Case #%d:",tt); // standard
		run();
		//printf("\n"); // endline
	}
	return 0;
}
