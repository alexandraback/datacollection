#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T, t=1, a, b, k, i, j;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d %d", &a, &b, &k);
		if(a>b) swap(a, b);
		int ans=0;
		for(i=0; i<a; i++) for(j=0; j<b; j++) if((i&j)<k) ans++;
		printf("Case #%d: %d\n", t++, ans);
	}
	return 0;
}
