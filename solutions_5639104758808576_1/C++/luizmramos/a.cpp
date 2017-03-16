#include <stdio.h>


int main(){
	int t;
	scanf("%d", &t);
	for(int xxx = 0; xxx < t; xxx++) {
		int smax;
		scanf("%d",&smax);
		int ans = 0;
		int total = 0;
		for (int i=0;i<=smax;i++) {
			int x;
			char c;
			scanf(" %c",&c);
			x = c - '0';		
			if (total < i) {
				ans += i - total;
				total = i;
			}
			total += x;
		}
		printf("Case #%d: %d\n",xxx+1, ans);
	}
}