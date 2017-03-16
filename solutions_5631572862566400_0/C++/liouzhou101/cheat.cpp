#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <algorithm>
#include <bitset>

using namespace std;

#define X first
#define Y second

const int MAXN=1010;

int a[MAXN], u[MAXN];
int len2[MAXN];
vector<int> lists[MAXN];

int main()
{
	freopen("try.in", "r", stdin);
	freopen("try.out", "w", stdout);
	int Test;
	scanf("%d", &Test);
	for (int TT=1; TT<=Test; ++TT)
	{
		printf("Case #%d: ", TT);
		int n;
		scanf("%d", &n);
		for (int i=1; i<=n; ++i)
		{
			scanf("%d", &a[i]);
			lists[i].clear();
			len2[i] = 0;
		}
		int ans = 0;
		for (int k=1; k<=n; ++k)
		{
			for (int i=1; i<=n; ++i)
				u[i] = 0;
			vector<int> v;
			int x = k;
			for (; !u[x]; x=a[x])
			{
				v.push_back(x);
				u[x] = 1;
			}
			int pos = 0;
			for (int i=0; i<v.size(); ++i)
				if (v[i]==x)
				{
					pos = i;
					break;
				}
			int len = v.size()-pos;
			if (len>2)
			{
				ans = max(ans, len);
				continue;
			}
			int val = v[pos];
			int val2 = v[pos+1];
			len2[val] = len2[val2] = 1;
			lists[val].push_back(pos);
		}
		for (int i=1; i<=n; ++i)
			if (len2[i]==1)
			{
				sort(lists[i].begin(), lists[i].end());
				reverse(lists[i].begin(), lists[i].end());
			}
		int sum = 0;
		for (int i=1; i<=n; ++i)
			if (len2[i]==1)
			{
				if (lists[i].size()==0)
					sum += 1;
				else if (lists[i].size()>=1)
					sum += 1+lists[i][0];
			}
		ans = max(ans, sum);
		printf("%d\n", ans);
	}
	return 0;
}
