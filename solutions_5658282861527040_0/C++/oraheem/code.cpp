#include<stdio.h>

int main(){
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int c = 1; c <= t;c++){
		int a,b,k;
		int total = 0;
		scanf("%d %d %d",&a,&b,&k);
		for(int i = 0; i < a;i++){
			for(int j = 0; j < b;j++){
				if ((i&j) < k) total ++;
			}
		}
		printf("Case #%d: %d\n", c, total);
	}
	//while(true);
}