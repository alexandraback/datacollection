#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	int cc,ca;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		long long K,C,S;
		cin >> K >> C >> S;
		if (S*C < K)
		{
			printf("Case #%d: IMPOSSIBLE\n", cc);
			continue;
		}
		vector<long long> r;
		long long i,j,k;
		for(i=0;i<K;)
		{
			k = i++;
			for(j=0; j<C-1; j++)
			{
				k*=K;
				long long t=i++;
				if (t >= K) t = 0;
				k+=t;
			}
			r.push_back(k);
		}
		printf("Case #%d:", cc);
		for(i=0; i<r.size(); i++)
			printf(" %lld", r[i]+1);
		printf("\n");
	}
}
