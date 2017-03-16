#include <stdio.h>
#include <string.h>

int main(){
	int T;
	scanf("%d",&T);
	for(int i=0; i<T; i++){
        char cakes[128];
		scanf(" %s",cakes);
        int S = strlen(cakes);
        int ans = 0;
        int k = S-1;
		while(k >= 0 && cakes[k] == '+')
			k--;
        while(k >= 0){
        	ans++;
            while(k >= 0 && cakes[k] == '-')
                k--;
            if(k < 0)
                break;
            ans++;
            while(k >= 0 && cakes[k] == '+')
                k--;
            if(k < 0)
                break;
        }
		printf("Case #%d: %d\n",i+1,ans);
	}
	return 0;
}
