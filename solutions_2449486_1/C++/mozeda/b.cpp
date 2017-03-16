#include <cstdio>
#include <cstring>
int n,m;
int a[110][110];
int b[110], c[110];
int T;
int main()
{
	scanf("%d", &T);
	for (int I=1;I<=T;++I)
	{
		scanf("%d%d", &n, &m);
		for (int i=0;i<n;++i)
			for (int j=0;j<m;++j)
				scanf("%d", &a[i][j]);
		memset(b, 0, sizeof b);
		memset(c, 0, sizeof c);
		for (int i=0;i<n;++i)
			for (int j=0;j<m;++j)
			{
				if (a[i][j]>b[i]) b[i]=a[i][j];
				if (a[i][j]>c[j]) c[j]=a[i][j];
			}
		bool pan = true;
		for (int i=0;i<n;++i)
			for (int j=0;j<m;++j)
			{
				if (b[i]<a[i][j] || c[j]<a[i][j]) 
					pan=false;
				if (b[i]!=a[i][j] && c[j]!=a[i][j])
					pan=false;
			}
		printf("Case #%d: ", I);
		if (pan)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
