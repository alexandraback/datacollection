#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int tt;
	scanf("%d", &tt);
	for(int ii = 1; ii <= tt; ii++)
	{
		int a, b, k, ans = 0;
		scanf("%d %d %d\n", &a, &b, &k);
		for(int i = 0; i < a; i++)
			for(int j = 0; j < b; j++)
			{
				if( (i&j) < k)
					ans++;
			}

		printf("Case #%d: %d\n", ii, ans);
	}
	return 0;
}