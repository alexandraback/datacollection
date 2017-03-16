#include <cstdio>
#include <algorithm>
#include <vector>

bool checkTime(const std::vector<int> & x, int cuts, int time)
{
	if(time <= 0)
		return false;

	for(int i = 0; i < (int)x.size(); i++)
		if(x[i] > time)
		{
			int t = x[i] / time;
			if(x[i] % time != 0)
				t++;

			cuts -= t - 1;
		}

	return cuts >= 0;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int tn;
	scanf("%i\n", &tn);

	for(int test = 1; test <= tn; test++)
	{
		int n;
		scanf("%i\n", &n);

		int top = 0;
		std::vector<int> x;
		for(int i = 0; i < n; i++)
		{
			int tmp;
			scanf("%i", &tmp);
			x.push_back(tmp);
			top = std::max(top, tmp);
		}


		int res = top;

		for(int cuts = 0; cuts <= top; cuts++)
		{
			int l = 0, r = top;
			while(r - l > 1)
			{
				int m = (l + r) / 2;
				if(checkTime(x, cuts, m))
					r = m;
				else
					l = m;
			}

			res = std::min(res, cuts + r);
		}

		printf("Case #%i: %i\n", test, res);
	}

	return 0;
}

