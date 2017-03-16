#include <stdio.h>
#include <string.h>

int main(){
	int T;
	scanf("%d",&T);
	for(int tt=0; tt<T; tt++){
		char S[1005];
		scanf(" %s",S);
		int len = strlen(S);
		char ans[len+1];
		int t=0,b=len-1;
		for(int i=len-1; i>=0; i--){
			char flg = 0;
			for(int j=0; j<i; j++)
				if(S[j] > S[i])
					flg = 1;
			if(flg){
				ans[b] = S[i];
				b--;
			}else{
				ans[t] = S[i];
				t++;
			}
		}
		ans[len] = '\0';
		printf("Case #%d: %s\n",tt+1,ans);
	}
	return 0;
}
