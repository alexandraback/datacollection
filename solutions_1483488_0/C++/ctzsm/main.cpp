#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

bool used[2000005];
int T,A,B;
int calc(int xx){
	int ret = 0,x = xx,t = 1;
	int a[30],cnt = 0;
	while(x){ a[cnt++] = x % 10;x /= 10; }
	for(int i = 0;i < cnt; ++i) a[cnt+i] = a[i],t *= 10;
	t /= 10;
	for(int i = 0;i < cnt; ++i){
		int c = 0;
		for(int j = cnt - 1;j >= 0; --j){
			c *= 10;
			c += a[i+j];
		}
		if(c >= A && c <= B && c / t >= 1 && !used[c]){
			ret ++;
			used[c] = true;
		}
	}
	return (ret - 1) * ret / 2;
}
int solve(){
	memset(used,false,sizeof(used));
	scanf("%d%d",&A,&B);
	int ans = 0;
	for(int i = A;i <= B; ++i){
		if(used[i]) continue;
		ans += calc(i);
//		printf("%d ",i);
	}
//	printf("\n");
	return ans;
}
int main(int argc, char** argv) {
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	scanf("%d",&T);
	for(int cas = 1;cas <= T; ++cas){
		printf("Case #%d: %d\n",cas,solve());
	}
	return 0;
}

