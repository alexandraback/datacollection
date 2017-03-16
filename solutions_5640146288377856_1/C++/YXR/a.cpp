#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;



int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	scanf("%d", &T);
	int r,c,w;
	for (int t = 1; t <= T; t++){
		scanf("%d %d %d",&r, &c, &w);
		int ans = 0;
		ans = c/w + w;
		if (w == 1 || c % w == 0)
			ans -= 1;
		ans = ans + (r - 1) * (c / w);
		printf("Case #%d: ", t);
		printf("%d\n", ans);
	}
	return 0;
}
