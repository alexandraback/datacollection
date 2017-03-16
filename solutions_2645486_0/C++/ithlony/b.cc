#include<cstring>
#include<cstdio>
#include<string>
using namespace std;

const int MAXN = 10000 + 10;

long long e, r;
int n;
int le[MAXN], st[MAXN];
long long v[MAXN];

long long calc()
{
	long long ne = e, ret = 0;
	for (int i = 0; i < n; ++i)
	{
		if(le[i] == -1 || le[i] * r >= e)
		{
			ret += ne * v[i];
			ne = 0;
		}
		else if(ne + r * le[i] >= e)
		{
			ret += (ne + r * le[i] - e) * v[i];
			ne = e - r * le[i];
		}
		ne += r;
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int tt = 1; tt <= T; ++tt)
	{
		scanf("%I64d%I64d%d", &e, &r, &n);
		if (r > e)
			r = e;
		memset(le, -1, sizeof(le));
		int top = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &v[i]);
			while(top > 0)
			{
				if(v[st[top - 1]] <= v[i])
				{
					le[st[top - 1]] = i - st[top - 1];
					top--;
				}
				else {
					break;
				}
			}
			st[top++] = i;
		}
		printf("Case #%d: %I64d\n", tt, calc());
	}
	return 0;
}
