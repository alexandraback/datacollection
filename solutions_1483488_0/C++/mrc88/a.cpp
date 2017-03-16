#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

inline int S(int x, int mn)
{
	int c = x%10;
	return x/10 + mn * c;
}

int main()
{
	int cases;
	scanf("%d", &cases);
	for(int icases = 1; icases <= cases; ++icases)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int d = 0, aCp = a, mn = 1;
		while(aCp > 0){ d++; aCp /= 10; mn *= 10; }
		mn /= 10;
		int res = 0;
		for(int i = a; i < b; ++i)
		{
			vector<int> v;
			int l = i;
			for(int j=1; j<d; ++j)
			{
				l = S(l, mn);
				if(a <= l && l <= b && i < l) v.push_back(l);
			}
			if(!v.empty())
			{
				sort(v.begin(), v.end());
				res++;
				for(int j=1; j<v.size(); ++j)
					if(v[j] != v[j-1]) res++;
			}
		}
		printf("Case #%d: %d\n", icases, res);
	}
	return 0;
}