#include <bits/stdc++.h>

using namespace std;

int n,v,cnt[2505];

void init(){
	int T;
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		for(int i = n*(2*n - 1); i > 0; i--){
			scanf("%d",&v);
			cnt[v]++;
		}
		printf("Case #%d:",t);
		for(int i = 1; i < 2501 and n; i++){
			if(cnt[i] & 1){
				printf(" %d",i);
				n--;
			}
		}
		printf("\n");
	}
}

void fread(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main(){
	fread();
	init();
	return 0;
}