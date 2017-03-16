#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int N, S, P;
	scanf("%d%d%d", &N, &S, &P);
	int ans=0;
	for(int i=0;i<N;i++) {
		int sum, x;
		scanf("%d", &sum);
		x = sum/3;
		if(x*3==sum && x>=P) ++ans;
		else if(x*3!=sum && x+1>=P) ++ans;
		else if(x*3==sum && x>0 && x+1==P && S>0) ++ans,--S;
		else if(x*3+2==sum && x>=0 && x+2==P && S>0) ++ans,--S;
	}
	static int cs=0;
	printf("Case #%d: %d\n", ++cs, ans);
}
int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}
