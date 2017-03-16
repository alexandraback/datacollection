#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <queue>

#define V first
#define I second

using namespace std;

const int MAXN = 100000;

int A[MAXN], B[MAXN];
pair <int, int> a[MAXN];
pair <int, int> b[MAXN];
int type[MAXN];
int n, m, k;
int level;
int ans;
priority_queue < pair <int, int> > h;

int main()
{
    freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);

    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
    	scanf("%d", &n);
    	memset(type, 0, sizeof(type));
    	for (int i = 0; i < n; i++)
    	{
    		scanf("%d %d", &A[i], &B[i]);
    		a[i] = make_pair(A[i], i);
    		b[i] = make_pair(B[i], i);
    	}
    	sort(a, a + n);
    	sort(b, b + n);
    	k = 0;
    	m = 0;
    	level = 0;
    	ans = 0;
    	while (h.size()) h.pop();

    	while (level < 2 * n)
    	{
    		while (m < n && b[m].V <= level)
    		{
    			level += 2 - type[b[m].I];
    			type[b[m].I] = 2;
    			m++;
    			ans++;
    		}

    		while (k < n && a[k].V <= level)
    		{
    			h.push(make_pair(B[a[k].I], a[k].I));
    			k++;
    		}

    		while (h.size() && type[h.top().I]) h.pop();
    		if (h.size() == 0) break;

    		level += 1;
    		type[h.top().I] = 1;
    		ans++;
    		h.pop();
    	}
    	printf("Case #%d: ", t);
    	if (level < 2 * n)
    		puts("Too Bad");
    	else
    		printf("%d\n", ans);
    }

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}
