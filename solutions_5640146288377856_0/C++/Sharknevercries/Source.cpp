#include<bits\stdc++.h>
using namespace std;
int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t ,ta = 1;
	scanf("%d", &t);
	while (t--){
		int r, c, w, ans;
		scanf("%d%d%d", &r, &c, &w);
		ans = r * ceil((double)c / w) + (w - 1);
		printf("Case #%d: %d\n", ta++, ans);
	}
	return 0;
}