#include <cstdio>
#include <cstring>

char buf[1024];
char f[1024],b[1024];
int ft,bt;

int main()
{
	freopen("i.txt","r",stdin);
	freopen("o.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=0; i<t; ++i)
	{
		scanf("%s",buf);
		ft=1;bt=0;
		f[0]=buf[0];
		int len=strlen(buf);
		for(int j=1;j<len;++j)
		{
			if(buf[j]>=f[ft-1])
				f[ft++]=buf[j];
			else
				b[bt++]=buf[j];
		}
		printf("Case #%d: ",i+1);
		for(int j=ft-1;j>=0;--j)
			printf("%c",f[j]);
		for(int j=0;j<bt;++j)
			printf("%c",b[j]);
		printf("\n");
	}
	return 0;
}

