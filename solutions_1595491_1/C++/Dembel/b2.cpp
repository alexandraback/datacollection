#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

#include <cstdarg>

using namespace std;

#define DBG2 1

#define clr(a) memset(a, 0, sizeof(a))
#define fill(a, b) memset(a, b, sizeof(a))

void dbg(char * fmt, ...)
{
#ifdef DBG1
#if	DBG2
	FILE * file = stdout;

	va_list args;
	va_start(args, fmt);
	vfprintf(file, fmt, args);
	va_end(args);

	fflush(file);
#endif
#endif
}

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;



int main()
{
#ifdef DBG1
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif

	int tt;
	scanf("%d", &tt);
	for (int ii = 0; ii < tt; ++ii)
	{
		int n, s, p;
        scanf("%d %d %d", &n, &s, &p);
        vector <int> a;
        int cand = 0;
        for (int i = 0; i < n; ++i)
        {
        	int v;
        	scanf("%d", &v);
        	if (2 <= v && v <= 28)
        	{
        		++cand;
        		a.push_back(v);
        	}
        	else
        		a.insert(a.begin(), v);
        }

        int sum1 = p + 2 * max(0, p - 1);
        int sum2 = p + 2 * max(0, p - 2);
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
        	if (2 <= a[i] && a[i] <= 28)
        	{
        		if (cand == s)
        		{
        			--s;
        			if (a[i] >= sum2)
        				++res;
        			--cand;
        			continue;
        		}
        		--cand;
        	}
        	if (a[i] >= sum1)
        		++res;
        	else
        		if (a[i] >= sum2 && s != 0)
        		{
        			--s;
        			++res;
        		}
        }
        printf("Case #%d: %d\n", ii + 1, res);
	}

	return 0;
}
