#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;

#define MAXN 105
vector<int> v;

int main ()
{
	int t, A, N;

	scanf(" %d", &t);
	for (int T=1; T <= t; T++)
	{
		v.clear();
		scanf(" %d %d", &A, &N);
		for (int i = 0; i < N; i++)
		{
			int x;
			scanf(" %d", &x);
			v.push_back(x);
		}
		sort(v.begin(), v.end());

		// O(N log2(N*A))
		int i, j, tamAtual = A, operacoesTotais = 0;
		for (i = 0, j = 0; j < N; j++)
		{
			// O(log2(N*A))
			int tamAtualK = tamAtual;
			int operacoesK = j-i+1;
			for (int k = i; k <= j; k++)
			{
				while (operacoesK && tamAtualK <= v[k])
				{
					tamAtualK += tamAtualK-1;
					operacoesK--;
				}
				if (tamAtualK <= v[k])
					break;
				tamAtualK += v[k];
			}
			if (tamAtualK > v[j])
			{
				tamAtual = tamAtualK;
				operacoesTotais += (j-i+1) - operacoesK;
				i = j+1;
			}
		}

		printf("Case #%d: %d\n", T, operacoesTotais + (j-i));
	}
	return 0;
}

