#include <cstdio>
#include <algorithm>

using namespace std;

int vet[100];
int mod[3];

int main()
{
	int t, n, s, p, res, tmp, c = 1;
	scanf("%d", &t);
	
	while (t--)
	{
		scanf("%d%d%d", &n, &s, &p);
		mod[0] = mod[1] = mod[2] = 0;
		res = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &vet[i]);
			tmp = vet[i]/3;
			if (vet[i]%3 != 0) ++tmp;
			if (tmp >= p) ++res;
			else if (tmp == p-1 && vet[i] > 1) mod[vet[i]%3]++;
		}
		res += min(s, mod[0]+mod[2]);
		printf("Case #%d: %d\n", c++, res);
	}
	
	return 0;
}

