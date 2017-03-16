#include <cstdio>
#include <cstring>

struct car
{
	char val[128];
	int len;
};

char fullstring[16384];
int ordered[128];
bool done[128];
long long ans;
car c[128];
int n;
int t;

void check()
{
	int ptr = 0;
	for (int i = 0;i < n;i++)
	{
		int u = ordered[i];
		for (int j = 0;j < c[u].len;j++)
			fullstring[ptr++] = c[u].val[j];
	}
	for (char x = 'a';x <= 'z';x++)
	{
		bool flag = (fullstring[0] == x);
		for (int i = 1;i < ptr;i++) if (fullstring[i] == x && fullstring[i-1] != x)
		{
			if (flag)
				return;
			flag = true;
		}
	}
	ans++;
}

void bf(int at)
{
	if (at == n)
	{
		check();
		return;
	}
	char begin = c[ordered[at-1]].val[c[ordered[at-1]].len-1];
	bool has = false;
	for (int i = 0;i < n;i++) if (c[i].val[0] == begin && !done[i])
	{
		has = true;
		break;
	}
	if (has) for (int i = 0;i < n;i++)
	{
		if (!done[i] && c[i].val[0] == begin)
		{
			done[i] = true;
			ordered[at] = i;
			bf(at+1);
			done[i] = false;
		}
	} else for (int i = 0;i < n;i++) if (!done[i])
	{
		done[i] = true;
		ordered[at] = i;
		bf(at+1);
		done[i] = false;
	}
}

int main()
{
	scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		ans = 0ll;
		scanf("%d", &n);
		for (int i = 0;i < n;i++)
		{
			scanf(" ");
			char tmp;
			c[i].len = 0;
			while (1)
			{
				scanf("%c", &tmp);
				if (tmp == ' ' || tmp == '\n')
					break;
				if (c[i].len == 0 || c[i].val[c[i].len-1] != tmp)
					c[i].val[c[i].len++] = tmp;
			}
		}
		for (int i = 0;i < n;i++)
		{
			ordered[0] = i;
			done[i] = true;
			bf(1);
			done[i] = false;
		}
		printf("Case #%d: %lld\n", _, ans);
		fprintf(stderr, "Done case #%d\n", _);
		fflush(stderr);
	}
	return 0;
}
