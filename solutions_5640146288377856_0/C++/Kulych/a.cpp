#include <cstdio>
#include <algorithm>
#include <iostream>

#define rep(k,a) for(int k = 0; k < (a); k++)

using namespace std;

int main()
{
	int t,r,c,w;
	scanf("%d", &t);
	rep(i, t){
		scanf("%d %d %d", &r, &c, &w);
		if(w == 1){
			printf("Case #%d: %d\n", i+1, r*c);
		}
		else{
			if(c % w == 0){
				printf("Case #%d: %d\n", i+1, r*(c/w) + w-1);
			}
			else
				printf("Case #%d: %d\n", i+1, r*(c/w) + w);
		}
	}
	return 0;
}

