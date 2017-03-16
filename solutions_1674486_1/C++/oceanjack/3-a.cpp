#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int fuck[1005][1005];
int size[1005];
bool in[1005], vis[1005];
int n;
inline bool haha(int x)
{
	if(vis[x])
		return true;
	vis[x] = true;
	for(int i = 0; i < size[x]; ++i)
	{
		int y = fuck[x][i];
		if(haha(y))
			return true;
	}
	return false;
}
inline bool play()
{
	for(int i = 1; i <= n; ++i)
		if(in[i])
		{
			memset(vis, false, sizeof(vis));
			if(haha(i))
				return true;
		}
	return false;
}
int main()
{
	freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	int c, cs = 1;
	for(scanf("%d",&c); c; --c, ++cs)
	{
		scanf("%d",&n);
		memset(in, true, sizeof(in));
		int x, y;
		for(int j = 1; j <= n; ++j)
		{
			scanf("%d",&x);
			size[j] = x;
			for(int i = 0; i < x; ++i)
			{
				scanf("%d",&y);
				fuck[j][i] = y;
				in[y] = false;
			}
		}
		printf("Case #%d: ", cs);
		puts(play() ? "Yes" : "No");
	}
	return 0;
}
