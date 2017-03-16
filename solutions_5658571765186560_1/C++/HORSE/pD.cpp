#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
	freopen("D-large.in", "r", stdin);
	freopen("pD_large.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for(int cnt = 1; cnt <= t; cnt ++){
		int x, r, c;
		scanf("%d%d%d", &x, &r, &c);
		printf("Case #%d: ", cnt);
		if((r * c) % x || x >= 7)
			puts("RICHARD");
		else if(min(r, c) >= x - 1)
			puts("GABRIEL");
		else
			puts("RICHARD");
	}
	return 0;
}
