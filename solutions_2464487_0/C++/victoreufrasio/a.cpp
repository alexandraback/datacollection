#include <stdio.h>


int main(){
	int T,test=0;
	int r, t;
	int i;
	int answer;

	scanf("%d", &T);

	while(T--){
		scanf("%d %d",&r, &t);

		i=0;
		answer = 0;

		while(t - (2*(r+i)+1) >= 0 ){
			answer++;
			t = t - (2*(r+i)+1);
			i = i+2;
		}
		printf("Case #%d: %d\n",++test, answer);
	}

}