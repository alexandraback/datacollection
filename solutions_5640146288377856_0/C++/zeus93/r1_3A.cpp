#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int r, c, w;
	int t;
	scanf("%d", &t);
	for(int id = 1; id <= t; id++){
		scanf("%d%d%d", &r, &c, &w);
		int ans = (c / w) * r + w;
		if(c % w == 0){
			ans -= 1;
		}
		printf("Case #%d: %d\n", id, ans);
	}
	return 0;
}
