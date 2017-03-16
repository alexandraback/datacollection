#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
	int T, K, C, S;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i)
	{
		set<ll> Set;
		scanf("%d%d%d", &K, &C, &S);
		printf("Case #%d: ", i);
		if(S < (K + C - 1)/C)
			puts("IMPOSSIBLE");
		else
		{
			ll tmp = 0;
			int mnozono = 0;
			int i = 0;
			while(i != K || mnozono != 0)
			{
				tmp *= K;
				tmp += min(i, K-1);
				++mnozono;
				if(mnozono == C)
				{
					mnozono = 0;
					//printf("%lld ", tmp+1);
					Set.insert(tmp+1);
					tmp = 0;
				}
				if(i != K) ++i;
			}
			for(auto it = Set.begin(); it != Set.end(); ++it)
				printf("%lld ", *it);
			Set.clear();
			puts("");
			
		}
		
		
	}
	return 0;
}
