#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	for(int tc=1; tc <= T; tc++)
	{
		char a[101];
		scanf("%s", a);

		int len = strlen(a);
		int ans = 1;
		for(int i=1; a[i]; i++)
			if(a[i-1] != a[i])
				ans++;

		if(a[len-1] == '+')
			ans--;

		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}