//acm header include 
#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int T, t, ks, p, s, n;

	scanf("%d", &T);
	for (ks=1; ks<=T; ++ks)
	{
		int ans = 0;
		scanf("%d %d %d", &n, &s, &p);
		for (int i=0; i<n; ++i)
		{
			scanf("%d", &t);
			if ((t+2) / 3 >= p) ++ans;

			else if (s>0) {
				if (t % 3 == 0 && t>=3 && (t/3 + 1 >= p))
				{
					++ans; --s;
				}

				if (t%3 == 2 && t/3+2>=p) {++ans; --s;}
			}
		}
		printf("Case #%d: %d\n", ks, ans);
	}
}