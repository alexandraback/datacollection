#include <stdio.h>
#include <string.h>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
#define MAX_D 120

int testcase = 0;
bool run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int v[MAX_D][MAX_D];
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
        scanf("%d", &v[i][j]);

    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
        int val = v[i][j];

        bool line = true;
        for (int k = 0; k < m; ++k)
            if (v[i][k] > val)
                line = false;

        bool colm = true;
        for (int k = 0; k < n; ++k)
            if (v[k][j] > val)
                colm = false;

        if (!line && !colm)
            return false;
    }

    return true;
}

int main()
{
    #if 0
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w+", stdout);
    #endif // ONLINE_JUDGE

	int testcases;
	scanf("%d", &testcases);
	for (testcase = 1; testcase <= testcases; ++testcase)
	{
	    printf("Case #%d: ", testcase);
		if (run())
            puts("YES");
        else
            puts("NO");
	}
	return 0;
}
