#include <stdio.h>

int T,i,j,x,o,ts;
char a[5][5];

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		for(i=0;i<4;i++)
			scanf("%s",&a[i]);
		for(i=0;i<4;i++)
		{
			x=o=1;
			for(j=0;j<4;j++)
			{
				x&=a[i][j]=='X' || a[i][j]=='T';
				o&=a[i][j]=='O' || a[i][j]=='T';
			}
			if(x || o)
				break;
		}
		if(x)
		{
			printf("Case #%d: X won\n",++ts);
			continue;
		}
		if(o)
		{
			printf("Case #%d: O won\n",++ts);
			continue;
		}
		for(i=0;i<4;i++)
		{
			x=o=1;
			for(j=0;j<4;j++)
			{
				x&=a[j][i]=='X' || a[j][i]=='T';
				o&=a[j][i]=='O' || a[j][i]=='T';
			}
			if(x || o)
				break;
		}
		if(x)
		{
			printf("Case #%d: X won\n",++ts);
			continue;
		}
		if(o)
		{
			printf("Case #%d: O won\n",++ts);
			continue;
		}
		x=o=1;
		for(i=0;i<4;i++)
		{
			x&=a[i][i]=='X' || a[i][i]=='T';
			o&=a[i][i]=='O' || a[i][i]=='T';
		}
		if(x)
		{
			printf("Case #%d: X won\n",++ts);
			continue;
		}
		if(o)
		{
			printf("Case #%d: O won\n",++ts);
			continue;
		}
		x=o=1;
		for(i=0;i<4;i++)
		{
			x&=a[i][3-i]=='X' || a[i][3-i]=='T';
			o&=a[i][3-i]=='O' || a[i][3-i]=='T';
		}
		if(x)
		{
			printf("Case #%d: X won\n",++ts);
			continue;
		}
		if(o)
		{
			printf("Case #%d: O won\n",++ts);
			continue;
		}
		x=0;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				x|=a[i][j]=='.';
		printf("Case #%d: ",++ts);
		puts(x?"Game has not completed":"Draw");
	}
	return 0;
}