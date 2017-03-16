#include <stdio.h>
#include <string.h>
char s1[200][50];
char s2[200][50];
long long a[200];
long long b[200];
bool flag[200];
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.txt","w",stdout);
	int t;
	scanf("%d",&t);
	int n,l;
	for (int k=1;k<=t;k++)
	{
		scanf("%d%d",&n,&l);
		for (int i=1;i<=n;i++) scanf("%s",&s1[i]);
		for (int i=1;i<=n;i++) scanf("%s",&s2[i]);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<l;j++) 
			{
				if (s1[i][j]=='1') a[i] = a[i] * 2 + 1;
				else a[i] = a[i] * 2;
				if (s2[i][j]=='1') b[i] = b[i] * 2 + 1;
				else b[i] = b[i] * 2;
			}
		}
		bool find = true;
		long long ans;
		int res = 0x7ccccccc, tmp = 0;
		for (int i=1;i<=n;i++)
		{
			memset(flag,0,sizeof(flag));
			flag[i] = true;
			ans = a[1] ^ b[i];
			for (int j=2;j<=n;j++)
			{
				find = false;
				for (int k=1;k<=n;k++)
				{
					if (!flag[k]&&(a[j]^b[k])==ans) {find = true; flag[k]==true; break;}
					if (find) break;
				}
				if (!find) break;
			}
			if (find)
			{
				tmp = 0;
				while (ans)
				{
					tmp = (ans & 1) + tmp;
					ans = ans >> 1;
				}
				if (tmp<res) res = tmp;
			}
		}
		if (res==0x7ccccccc) printf("Case #%d: NOT POSSIBLE\n",k);
		else printf("Case #%d: %d\n",k,res);
	}
	return 0;
}
