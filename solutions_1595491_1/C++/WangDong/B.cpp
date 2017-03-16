#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<map>
#include<iostream>

using namespace std;

int n, s, p, T;
int a[110];
int b[40];
int c[40];

int calc()
{
	memset(b, 0xff, sizeof(b));
	memset(c, 0xff, sizeof(c));
	for (int i=0; i<=10; i++)
		for (int j=0; j<=10; j++)
			for (int t=0; t<=10; t++)
				if (abs(i-t)<=2&&abs(i-j)<=2&&abs(t-j)<=2)
				{
					if (abs(i-t)<=1&&abs(i-j)<=1&&abs(t-j)<=1)
						b[i+j+t] = max(b[i+j+t], max(i, max(j,t)));
					else
						c[i+j+t] = max(c[i+j+t], max(i, max(j,t)));
				}
	int ret = 0;
	for (int i=0; i<n; i++)
	{
		if (b[a[i]]>=p)
			ret++;
		else if (c[a[i]]>=p && s>0)
		{
			s--;
			ret++;
		}
	}
	return ret;
}

int main()
{
	freopen("C:/Users/yaoyao/Downloads/B-large.in", "r", stdin);
	freopen("C:/Users/yaoyao/Downloads/out.txt", "w", stdout);
	scanf("%d", &T);
	for (int i=1; i<=T; i++)
	{
		memset(a,0,sizeof(a));
		scanf("%d%d%d", &n, &s, &p);
		for (int j=0; j<n; j++) scanf("%d", &a[j]);
		printf("Case #%d: %d\n", i, calc());
	}
}