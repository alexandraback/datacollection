
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )

typedef long long int LL;

using namespace std;
int t,r,n,m,k,h;
int ans[64];

inline int mat(int a,int b){return a==b?1:0;}

int go(int z,int h){
	int a = 2 + (z&3);
	int b = 2 + ((z>>2)&3);
	int c = 2 + ((z>>4)&3);
	return mat(1,h) + mat(a,h) + mat(b,h) + mat(c,h) +
		   mat(a*b,h) + mat(b*c,h) + mat(a*c,h) + mat(a*b*c,h);
}

int main(){

	scanf("%d%d%d%d%d",&t,&r,&n,&m,&k);
	printf("Case #1:\n");
	for(int i=0; i<r; i++){
		for(int z=0; z<64; z++)ans[z]=1;

		for(int j=0; j<k; j++){
			scanf("%d",&h);
			for(int z=0; z<64; z++){
				ans[z] *= go(z, h);
			}
		}
		int win=0;
	
		for(int j=0;j<64;j++){
			if(ans[win]<ans[j])win=j;
		}
		for(int j=0;j<n;j++)printf("%d",2 + ((win>>(j*2)) & 3) );puts("");
	}
	return 0;
}
