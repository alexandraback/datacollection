#include<stdio.h>
#include<algorithm>

using namespace std;

int D[1005];
int sum[1005];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		int N, ans;
		scanf("%d", &N);
		ans = 0x7fffffff;
		for(int i = 1; i <= N; i++){
			scanf("%d", D+i);
		}
		for(int i = 1; i <= 1000; i++){
			int tot = i;
			for(int j = 1; j <= N; j++){
				tot += (D[j]-1) / i;
			}
			ans = min( ans, tot );
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}