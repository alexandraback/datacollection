#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int MAX = 2000001;

set<int> cycle[MAX];

int main()
{
	int i;
	for (i=1; i<MAX; ++i)
	{
		cycle[i].clear();
		char num[32];
		memset(num, 0, sizeof(num));
		sprintf(num, "%d\0", i);
		int len = strlen(num);
		int j, m;
		for (j=1; j<len; ++j)
		{
			num[len+j-1] = num[j-1];
			if (num[j] == '0') continue;
			sscanf(&num[j], "%d", &m);
			if (m > MAX) continue;
			if (m > i) cycle[i].insert(m);
		}
	}
	printf("offline process done!");
	getchar();

	FILE *fin;
	fin = fopen("C-large.in", "r");
	freopen("C-large.out", "w", stdout);

	int T;
	fscanf(fin, "%d", &T);

	for (int k=1; k<=T; ++k)
	{
		int a, b;
		fscanf(fin, "%d%d", &a, &b);
		int res = 0;
		for (i=a; i<=b; ++i)
		{
			int j;
			set<int>::iterator it;
			for (it=cycle[i].begin(); it != cycle[i].end(); ++it)
			{
				if (*it <= b) ++res;
			}
		}
		printf("Case #%d: %d\n", k, res);
	}

	return 0;
}
