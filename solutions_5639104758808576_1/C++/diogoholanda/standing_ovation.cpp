#include <stdio.h>
#include <string.h>

int T, u, resp, sum, N;
char s[1010];

int main(){
	scanf(" %d", &T);
	u=0;
	while(u<T){
		u++;
		scanf(" %d %s", &N, &s);
		resp = 0;
		sum = 0;
		for(int i=0; i<=N; i++){
			if(sum >= i){
				sum += s[i]-'0';
			}
			else{
				resp += i - sum;
				sum = i;
				sum += s[i]-'0';
			}
		}
		printf("Case #%d: %d\n", u, resp);
	}
	return 0;
}
