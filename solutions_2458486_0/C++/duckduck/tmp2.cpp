#include <stdio.h>
#include <string.h>

const int maxn=201;

int now[maxn],num[maxn],key[maxn][maxn],s[maxn],need[maxn],f[1<<20];
int i,j,k,m,n,t,tt,l;

void search(int nows)
{
	int i,ne;

	if (nows==(1<<n)-1)
		f[nows]=1;
	if (f[nows]!=-1)
		return;


	f[nows]=0;

	for (i=1;i<=n;i++)
	{
		ne=nows|(1<<(i-1));
		if (ne!=nows)
			if (now[need[i]]>0)
			{
				now[need[i]]--;
				for (j=1;j<=num[i];j++)
					now[key[i][j]]++;
				search(ne);
				if (f[ne]==1)
					f[nows]=1;
				for (j=1;j<=num[i];j++)
					now[key[i][j]]--;
				now[need[i]]++;
				if (f[ne]==1)
					return;
			}
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++)
	{
		for (i=1;i<maxn;i++)
			now[i]=0;
		scanf("%d%d",&m,&n);
		for (i=1;i<=m;i++)
		{
			scanf("%d",&j);
			now[j]++;
		}
		for (i=1;i<=n;i++)
		{
			scanf("%d%d",&need[i],&num[i]);
			for (j=1;j<=num[i];j++)
				scanf("%d",&key[i][j]);
		}
		for (i=0;i<(1<<n);i++)
			f[i]=-1;
		search(0);
		printf("Case #%d:",tt);
		k=0;
		for (i=1;i<=n;i++)
		{
			s[i]=0;
			for (j=1;j<=n;j++)
			{
				l=k|(1<<(j-1));
				if ((k!=l)&&(f[l]==1))
				{
					s[i]=j;
					k=l;
					break;
				}
			}
		}
		if (s[n]!=0)
		{
			for (i=1;i<=n;i++)
				printf(" %d",s[i]);
			printf("\n");
		}
		else
			printf(" IMPOSSIBLE\n");
	}
	return 0;
}


