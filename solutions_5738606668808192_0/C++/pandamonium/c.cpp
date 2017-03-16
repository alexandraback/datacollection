#include <bits/stdc++.h>
using namespace std;
int l=16,j=50;
vector <int> v1[20],v2[20];
int main(){
	printf("Case #1:\n");
	for(int x=1;x<(1<<(l/2));x++){
		int k=x,cnt=0;
		while(k){
			cnt+=(k&1);
			k>>=1;
		}
		if(x&1) v1[cnt].push_back(x);
		if(x>=(1<<(l/2-1))) v2[cnt].push_back(x);
	}
	int done=0;
	for(int x=1;x<=(l/2);x++){
		for(int y=0;y<v1[x].size();y++){
			for(int z=0;z<v2[x].size();z++){
				int k2=v2[x][z],k1=v1[x][y];
				for(int w=0;w<(l/2);w++){
					printf("%d%d",k1&1,k2&1);
					k1>>=1;k2>>=1;
				}
				for(int w=3;w<=11;w++) printf(" %d",w);
				printf("\n");
				j--;
				if(!j){
					done=1;
					break;
				}
			}
			if(done) break;
		}
		if(done) break;
	}
	return 0;
}
