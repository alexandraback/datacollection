#include <cstdio>
using namespace std;

int main()
{
	int N, S, p, i, T;
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		scanf("%d %d %d" , &N, &S, &p);
		int cnt = 0;
		for (i = 0; i < N; i++)
		{
			int x;
			scanf("%d", &x);
			int r = x / 3;
			int m = x % 3;
			if (r >= p) {cnt++; continue;}
			if (m == 0) { if (r >= p) {cnt++; continue;}}
			if (m == 1) { if (r + 1 >= p && r + 1 <= 10) {cnt++; continue;}}
			if (m == 2) { if (r + 1 >= p && r + 1 <= 10) {cnt++; continue;}}
			
			if (m == 0) { if (r - 1 >= 0 && r + 1 <= 10 && S > 0 && r + 1 >= p) {cnt++; S--; continue;}}
			if (m == 2) { if (r + 2 <= 10 && r + 2 >= p && S > 0) {cnt++; S--; continue;}}
		}
		printf("%d\n", cnt);
	}
	return 0;
}