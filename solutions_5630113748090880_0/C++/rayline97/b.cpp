#include <cstdio>
#include <cstring>


int main(){
	int T;
	scanf("%d",&T);
	for(int Case = 1;Case<=T;Case++){
		bool cnt[2586];
		memset(cnt, 0, sizeof(cnt));
		int n;
		scanf("%d",&n);
		for(int i=0;i<2*n-1;i++){
			for(int j=0;j<n;j++){
				int k;
				scanf("%d",&k);
				cnt[k] = !cnt[k];
			}
		}
		printf("Case #%d:", Case);
		for(int i=1;i<=2500;i++){
			if(cnt[i]) printf(" %d", i);
		}
		putchar('\n');
	}
}