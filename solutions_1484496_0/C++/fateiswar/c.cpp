#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;

int a[50];
bool gao(int N){
	for(int i=1; i<(1<<N); i++)
		for(int j=1; j<(1<<N); j++) if(!(i&j)){
			int s1=0, s2=0;
			for(int z=0; z<N; z++){
				if((1<<z)&i) s1+=a[z];
				if((1<<z)&j) s2+=a[z];
			}
			if(s1==s2){
				for(int z=0; z<N; z++)
					if((1<<z)&i) printf("%d ", a[z]);
				printf("\n");
				for(int z=0; z<N; z++)
					if((1<<z)&j) printf("%d ", a[z]);
				printf("\n");
				return 1;
			}
		}
	return 0;
}
int main(){
	freopen("C-small-attempt0(1).in", "r", stdin);
	freopen("c-small-out.txt", "w", stdout);
	int T; cin>>T;
	for(int cas=1; cas<=T; cas++){
		int N; cin>>N;
		int i, j;
		for(i=0; i<N; i++) cin>>a[i];
		printf("Case #%d:\n", cas);
		if(!gao(N))
			printf("Impossible\n");
	}
	return 0;
}