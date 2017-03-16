#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(void)
{
	freopen("B-small-attempt0.in", "rb", stdin);
	freopen("q2s.txt", "wb", stdout);
	int t, k = 0;
	scanf("%d", &t);
	while(k++ < t)
	{
		int n;
		scanf("%d", &n);
		char car[200];
		bool ok = true;
		vector<string> cars;
		for(int i = 0; i < n; ++i)
		{
			scanf(" %s", car);
			string s = "";
			char c = car[0];
			s.append(1, c);
			int index = 0;
			for(int l = 1; car[l] != 0; ++l)
			{
				if(car[l] != c)
				{
					++index;
					s.append(1, car[l]);
					if(index > 1)
						ok = false;
				}
			}
			cars.push_back(s);
		}
		if(ok == false)
		{
			printf("Case #%d: 0\n", k);
			continue;
		}

		int nums[200];
		for(int i = 0; i < n; ++i)
			nums[i] = i;

		int ret = 0;
		do
		{
			string s = "";
			for(int i = 0; i < n; ++i)
				s += cars[nums[i]];

			map<char, bool> chars;
			char c = s[0];
			chars[c] = true;
			bool ok = true;
			for(int i = 1; i < s.size(); ++i)
			{
				if(s[i] != c)
				{
					if(chars.find(s[i]) == chars.end())
					{
						c = s[i];
						chars[c] = true;
					}
					else
						ok = false;
				}
			}
			if(ok)
				++ret;
		}while(next_permutation(nums, nums + n));

		printf("Case #%d: %d\n", k, ret);
	}
	return 0;
}