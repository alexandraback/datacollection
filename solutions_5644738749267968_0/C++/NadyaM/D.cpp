// WA
#include <stdio.h>
#include <algorithm>
using namespace std;

int T, N;
double a[1005], b[1005];

int main()
{	int tt, i, j, cnt1, cnt2, jN;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for(tt=1; tt<=T; ++tt)
	{
		scanf("%d", &N);
		for(i=1; i<=N; ++i)
			scanf("%lf", &a[i]);
		sort(a, a+N+1);
		for(i=1; i<=N; ++i)
			scanf("%lf", &b[i]);
		sort(b, b+N+1);
		cnt1=0;
		for(i=1, j=1; i<=N && j<=N; ++i)
		{
			while(j<=N && b[j]<a[i])
			{
				cnt1++;
				++j;
			}
			++j;
		}
		cnt2=0;
		for(i=N, j=N; i>0 && j>0; --i)
		{
			while(j>0 && a[i]<b[j])
			{
				cnt2++;
				--j;
			}
			--j;
		}
		/*for(i=1, j=1, jN=N+1; i<=N && j<jN; ++i)
		{
			if(a[i] < b[j])
			{
				jN--;
				continue;
			}
			while(j<jN && b[j] < a[i])
			{
				cnt2++;			
				++j;
			}
		}*/
		printf("Case #%d: %d %d\n", tt, N-cnt2, cnt1);
	}

	return 0;
}
