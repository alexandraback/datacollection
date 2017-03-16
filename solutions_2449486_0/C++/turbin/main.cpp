#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ldouble;

int n, m, a[110][110], mxr[110], mxc[110];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int ts; scanf("%d\n", &ts);
	for (int tst = 0; tst < ts; tst++)
	{
		printf("Case #%d: ", tst + 1);
		scanf("%d%d", &n, &m);
		fill(mxr, mxr + n, 0);
		fill(mxc, mxc + m, 0);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &a[i][j]), mxr[i] = max(a[i][j], mxr[i]), mxc[j] = max(mxc[j], a[i][j]);
		bool ans = true;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (a[i][j] < mxr[i] && a[i][j] < mxc[j]) ans = false;
		if (ans) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}