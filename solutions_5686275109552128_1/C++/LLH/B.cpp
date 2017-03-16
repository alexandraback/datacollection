#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int64;
const int maxn=1100;

int n;
int P[maxn];
void solve(int icase) {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",P+i);
	
	int ans=1001;
	for(int bound=1;bound<=1000;bound++) {
		int cnt=bound;
		for(int i=1;i<=n;i++)
			cnt+=(P[i]-1)/bound;
		ans=min(ans,cnt);
	}

	printf("Case #%d: %d\n",icase,ans);
}
int main() {
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
		solve(i);
	scanf("%*s");
	return 0;
}
