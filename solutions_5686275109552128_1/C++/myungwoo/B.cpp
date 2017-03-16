#include <bits/stdc++.h>
using namespace std;

int T, N, M, A[1001];

int main()
{
	int ts = 0;
	for (scanf("%d", &T);T--;){
		printf("Case #%d: ", ++ts);
		scanf("%d", &N); M = 0;
		for (int i=1;i<=N;i++) scanf("%d", A+i), M = max(M, A[i]);
		int ans = M;
		for (int i=1;i<=M;i++){
			int cnt = 0;
			for (int j=1;j<=N;j++)
				if (A[j] > i) cnt += (A[j] - i - 1) / i + 1;
			ans = min(ans, cnt + i);
		}
		printf("%d\n", ans);
	}
}
