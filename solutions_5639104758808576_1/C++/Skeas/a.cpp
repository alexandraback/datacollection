#include<cstdio>

using namespace std;

int n;
char str[10000];

int main() {
	int T,cs; scanf("%d",&T);
	for(cs=1;cs<=T;++cs) {
		scanf("%d%s",&n,str);
		printf("Case #%d: ",cs);
		int sum = str[0] - '0';
		int ans = 0;
		for(int i=1;i<=n;++i) {
			int cur = str[i] - '0';
			if(i > sum) ans += i - sum, sum = i;
			sum += cur;
		} printf("%d\n",ans);
	}
}
