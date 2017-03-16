#include<stdio.h>
#include<algorithm>

using namespace std;

char D[1005];
int sum[1005];

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		int N;
		scanf("%d%s", &N, D);
		sum[0] = D[0] - '0';
		for(int i = 1; i <= N; i++){
			sum[i] = sum[i-1] + D[i] - '0';
		}
		int mx = 0;
		for(int i = 0; i <= N; i++) mx = max(i - sum[i] + 1, mx);
		printf("Case #%d: %d\n", t, mx);
	}
	return 0;
}