#include <stdio.h>

int main(){
	int tn, t;
	scanf("%d", &tn);
	
	int n, i;
	int s[250];
	int x;
	
	for(t=0;t<tn;t++){
		scanf("%d", &n);
		
		x = 0;
		for(i=0;i<n;i++){
			scanf("%d", &s[i]);
			x += s[i];
		}
		printf("Case #%d: ", t+1);
		for(i=0;i<n;i++){
			printf("%f ", (float)s[i]*100 / x);
		}
		printf("\n");
	}
}
