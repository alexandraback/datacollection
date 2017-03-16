#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	//freopen("input.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; test++)
	{
		int n;
		scanf("%d", &n);
		vector<int> s(n);
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &s[i]);
		}
		
		int s1 = 0, s2 = 0;
		map<long long, int> m;
		for(int i = 1; i < (1 << n); i++)
		{
			long long sum = 0;
			for(int j = 0; j < n; j++)
			{
				if(i & (1 << j))
				{
					sum += s[j];
				}
			}
			if(m.find(sum) != m.end())
			{
				s1 = i;
				s2 = m[sum];
			}
			else
			{
				m[sum] = i;
			}
		}

		//cout << "Case #" << test << ":" << endl;
		printf("Case #%d:\n", test);
	
		int cnt = 0;
		for(int i = 0; i < s.size(); i++)
		{
			if(s1 & (1 << i))
			{
				if(cnt > 0)
					printf(" ");
				printf("%d", s[i]);
				cnt++;
			}
		}
		cout << endl;

		cnt = 0;
		for(int i = 0; i < s.size(); i++)
		{
			if(s2 & (1 << i))
			{
				if(cnt > 0)
					printf(" ");
				printf("%d", s[i]);
				cnt++;
			}
		}
		printf("\n");
	}
	return 0;
}