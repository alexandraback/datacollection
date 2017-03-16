#include <cstdio>
#include <algorithm>
using namespace std;
int a[105],n,s,p;
int Case;

int main() {
	scanf("%d",&Case);
	for (int i=1;i<=Case;++i) {
		printf("Case #%d: ", i);
		scanf("%d%d%d",&n,&s,&p);
		for (int j=1;j<=n;++j)
			scanf("%d",a+j);
		
		sort(a+1, a+1+n);
		int Ans = 0;
		for (int j=n;j>=1;--j) {
			if (a[j] >= p*3-2) ++ Ans;
			else if (p>1 && a[j]>=p*3-4 && s>0) s--, ++Ans;
		}
		printf("%d\n", Ans);
	}

	return 0;
}