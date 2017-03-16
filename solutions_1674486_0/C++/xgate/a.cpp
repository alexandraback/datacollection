#include <iostream>
#include <vector>

using namespace std;

vector<int> v[1001];
bool check[1001];

bool solve(int idx)
{
	int size = v[idx].size();

	for(int i=0; i<size; i++)
	{
		if (check[v[idx][i]]) 
			return true;

		check[v[idx][i]] = true;

		if (solve(v[idx][i])) return true;
	}

	return false;
}

int main()
{
	int t;

	scanf("%d", &t);

	for(int a=1;a<=t;a++)
	{
		int n;

		scanf("%d", &n);
		for(int i=1; i<=n; i++)
		{
			int num, in;

			scanf("%d", &num);

			for(int j=0; j<num; j++)
			{
				scanf("%d", &in);
				v[i].push_back(in);
			}
		}

		bool ans = false;

		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++)
				check[j] = false;

			ans = solve(i);
			if (ans) break;
		}

		if (ans)
			printf("Case #%d: Yes\n", a);
		else
			printf("Case #%d: No\n", a);

		for(int i=1; i<=n; i++)
			v[i].clear();
	}
	
	return 0;
}