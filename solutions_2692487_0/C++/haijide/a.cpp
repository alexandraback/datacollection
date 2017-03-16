#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int M = 105;

int T;
ll A;
int N;
ll mt[M];
ll at[M];

int main()
{
	freopen("A-small-attempt2.in", "r", stdin);
	freopen("out.out", "w", stdout);
	int cs = 1;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld%d", &A, &N);
//		ll ta = A;
		for(int i = 0; i < N; i++)
			scanf("%lld", &mt[i]);
		if(A == 1)
		{
			printf("Case #%d: %lld\n", cs++, (ll)N);
			continue;
		}
		sort(mt, mt + N);
		ll ans = 0;
		for(int i = 0; i < N; i++)
		{
			if(A > mt[i])
				A += mt[i];
			else
			{
				while(A + A - 1 <= mt[i])
				{
					A = A + A - 1;
					ans++;
					if(ans > N)
						break;
				}
				A = A + A - 1 + mt[i];
				ans++;
			}
			at[i] = ans;
//			if(ans > N)
//				break;
//		else if(A + A - 1 > mt[i])
//			{
//				ans++;
//				A = A + A - 1 + mt[i];
//			}
		}
		ans = at[N - 1];
		for(int i = 0; i < N; i++)
		{
			ans = min(ans, at[i] + N - 1 - i);
		}
		printf("Case #%d: %lld\n", cs++, min(ans, (ll)N));
	}
	return 0;
}
