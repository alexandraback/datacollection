using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>

typedef long long L;
typedef unsigned long long U;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

main()
{
	int tc;
	cin>>tc;
	for(int t = 1;t<=tc;t++)
	{
		int n;
		cin>>n;
		string str[n];
		vector<int>v;
		for(int i = 0;i<n;i++)
		{
			v.push_back(i);
			cin>>str[i];
		}
		int c = 0;
		do{
			char ch = '$';
			bool visit[26];
			bool valid = 1;
			for(int i = 0;i<26;i++)
				visit[i] = 0;
			for(int i = 0;i<n && valid;i++)
			{
				for(int j = 0;j<str[v[i]].length() && valid;j++)
				{
					if(ch != str[v[i]][j])
					{
						ch = str[v[i]][j];
						if(visit[ch-'a'])
							valid = 0;
						visit[ch-'a'] = 1;
					}
				}
			}
			if(valid)
				c++;
		}while(next_permutation(v.begin(),v.end()));
		printf("Case #%d: %d\n",t,c);
	}
}
