#include<cstdio>
#include<cstdlib>
#include<queue>
#include<cmath> 
#include<cstring> 
#include<map> 
#include<set>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
	//freopen("B-large.in", "r", stdin);
	//freopen("B-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas ++)
	{
		int A, B, K;
		int i, j, k;
		long long ans = 0;
		scanf("%d %d %d", &A, &B, &K);
		for(i = 0; i < A; i ++)
		{
			for(j = 0; j < B; j ++)
			{
				if((i&j) < K)ans ++;
			}
		}
		printf("Case #%d: ", cas);
		cout << ans << endl;
	}
	return 0;
}
