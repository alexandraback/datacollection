#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

long long k,c,s;
inline long long zou(long long now, long long x)
{
	if(x > k) x = k;
	return now * k + x - k;
}
std::vector<long long> v;
int main()
{
	int _T;
	std::cin >> _T;
	for(int CAS = 1; CAS <= _T; CAS++)
	{
		std::cin >> k >> c >> s;
		//c++;
		v.clear();
		long long now = 0;
		while(now < k)
		{
			long long tmp = 1;
			//now++;
			for(int i = 0; i < c; i++)
			{
				now++;
				//printf("GAO %lld\n", now);
				tmp = zou(tmp, now);
			}
			v.push_back(tmp);
			//printf("ADD %lld\n", tmp);
		}
		printf("Case #%d:", CAS);
		if(v.size() > s)
			puts(" IMPOSSIBLE");
		else
		{
			/*long long now = 1;
			while(v.size() < s)
			{
				int flag = 1;
				int l = v.size();
				for(int i = 0; i < l; i++)
					if(v[i] == now)
						flag = 0;
				if(flag)
					v.push_back(now);
				now++;
			}
			std::sort(v.begin(),v.end());*/
			for(int i = 0; i < v.size(); i++)
				printf(" %lld", v[i]);
			puts("");
		}
	}
}