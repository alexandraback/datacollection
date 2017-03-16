#include <bits/stdc++.h>

using namespace std;


int main(){
	int t;
	scanf("%d", &t);
	for(int k = 1; k <= t; k++){
		int r, c, w;
		scanf(" %d %d %d", &r, &c, &w);
		int i;
		for(i = 0; c >= w; i++){
			c-= w;
		}
		if(c == 0)
			printf("Case #%d: %d\n", k, i*r+w-1);
		else
			printf("Case #%d: %d\n", k, i*r+w);

	}
	return 0;
}