#include<bits\stdc++.h>
using namespace std; 
long long C, D, V;
long long d[105];
int main(){
	freopen("C-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t ,ta = 1;
	scanf("%d", &t);
	while (t--){
		scanf("%lld%lld%lld", &C, &D, &V);
		for (int i = 0; i < D; i++)
			scanf("%lld", d + i);
		sort(d, d + D);
		long long cnt = 0;
		long long K = C;
		int st = 0;
		if (d[0] != 1)
			cnt++;
		else
			st++;
		while (K < V){
			if (st >= D || d[st] - 1 > K)
				cnt++, K += (K + 1)*C;
			else
				K += d[st++] * C;
		}
		printf("Case #%d: %lld\n", ta++, cnt);

	}
	return 0;
}