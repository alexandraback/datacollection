#include<iostream>
#include<vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <memory.h>
#include <set>
#include <algorithm>

using namespace std;

bool pr[10000];
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int t;
	scanf("%d", &t);
	for(int test = 0; test < t; test++)
	{
		
		bool res = false;
		memset(pr, true, 10000);
		int n;
		scanf("%d", &n);
		vector<vector<int>> ss(n);
		for(int i =0 ;i <n;i++)
		{
			int m, temp;
			scanf("%d", &m);
			for(int j =0 ; j <m ;j++)
			{
				scanf("%d", &temp);
				temp--;
				ss[i].push_back(temp);
				pr[temp] = false;
			}
		}
		for(int i =0 ;i < n && !res;i++)
		{
			if(pr[i])
			{
				set<int> clases;
				queue<int> q;
				q.push(i);
				clases.insert(i);
				while (!q.empty() && !res)
				{
					int temp = q.front();
					q.pop();
					for(int j =0; j < ss[temp].size() && !res; j++)
					{
						q.push(ss[temp][j]);
						if(clases.find(ss[temp][j]) != clases.end())
						{
							res = true;
						}
						else
						{
							clases.insert(ss[temp][j]);
						}
					}
				}
			}
		}
		if(res)
		{
			printf("Case #%d: Yes", test+1);
			if(test != t-1)
				printf("\n");
		}
		else
		{
			printf("Case #%d: No", test+1);
			if(test != t-1)
				printf("\n");
		}
	}

	return 0;
}