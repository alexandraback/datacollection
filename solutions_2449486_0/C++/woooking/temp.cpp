#include <cstdio>
#include <cstring>

int cases,n,m;
int map[100][100];

int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d\n",&cases);
	for(int i=1;i<=cases;++i)
	{
		scanf("%d%d",&n,&m);
		for(int j=0;j<n;++j)
		{
			for(int k=0;k<m;++k)
			{
				scanf("%d",&map[j][k]);
			}
		}
		bool ans=true;
		for(int j=0;j<n;++j)
		{
			for(int k=0;k<m;++k)
			{
				bool ok=true;
				for(int l=0;l<n;++l)
				{
					if(map[l][k]>map[j][k])
					{
						ok=false;
						break;
					}
				}
				if(!ok)
				{
					ok=true;
					for(int l=0;l<m;++l)
					{
						if(map[j][l]>map[j][k])
						{
							ok=false;
							break;
						}
					}
				}
				if(!ok)
				{
					ans=false;
					printf("Case #%d: NO\n",i);
					break;
				}
			}
			if(!ans)break;
		}
		if(ans)printf("Case #%d: YES\n",i);
	}
	return 0;
}