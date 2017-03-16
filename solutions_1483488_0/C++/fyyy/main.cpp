#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>

#define lowbit(w) ((w) & (-w))

using namespace std;

const int N = 2000010;

set<int> a[N];

void preProcess()
{
	char tmp[8], rev[8];
	int num;
	for (int i = 1; i < 3000; i++)
	{
		sprintf(tmp, "%d", i);
		int l = strlen(tmp);
		for (int j = 1; j < l; j++)
		{
			strcpy(rev, tmp);
			reverse(rev, rev + j);
			reverse(rev + j, rev + l);
			reverse(rev, rev + l);
			sscanf(rev, "%d", &num);
			a[i].insert(num);
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t, u, v;
	preProcess();
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++)
	{
		scanf("%d %d", &u, &v);
		int ans = 0;
		for (int i = u; i < v; i++)
			for (set<int>::iterator it = a[i].begin(); it != a[i].end(); it++)
				if (*it > i && *it <= v)
					ans++;
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}

