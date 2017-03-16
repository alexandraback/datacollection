#include <bits/stdc++.h>
using namespace std;

int T, N;
int A[1004];

bool proc(int m)
{
	int aud = A[0]+m;
	for (int i=1;i<=N;i++){
		if (i > aud) return 0;
		aud += A[i];
	}
	return 1;
}

int main()
{
	int ts = 0;
	for (scanf("%d", &T);T--;){
		printf("Case #%d: ", ++ts);
		scanf("%d", &N);
		for (int i=0;i<=N;i++) scanf("%1d", A+i);
		int s = 0, e = 9*N, ans = -1;
		while (s <= e){
			int m = (s+e)>>1;
			if (proc(m)) e = m-1, ans = m;
			else s = m+1;
		}
		printf("%d\n", ans);
	}
}
