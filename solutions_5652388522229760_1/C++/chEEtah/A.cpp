#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt;

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		int n;
		scanf("%d", &n);
		if (!n) { puts("INSOMNIA"); continue; }

		vector<bool> seen(10, false);
		
		int todo = 100000;
		int cur = n;
		while(todo--)
		{
			int k = cur;
			while(k)
			{
				seen[k % 10] = true;
				k /= 10;
			}
			bool ok = true;
			for(int i = 0; i < 10; i++) if (!seen[i]) { ok = false; break; }
			if (ok)
			{
				printf("%d\n", cur);
				break;
			}
			cur += n;
		}
		if (todo <= 0) puts("INSOMNIA");
	}
	return 0;
}