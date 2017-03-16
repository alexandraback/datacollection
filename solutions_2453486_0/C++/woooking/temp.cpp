#include <cstdio>
#include <cstring>

int cases;
int map[4][4],num;

int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d\n",&cases);
	for(int i=1;i<=cases;++i)
	{
		char c[5];
		num=0;
		for(int j=0;j<4;++j)
		{
			scanf("%s",c);
			for(int k=0;k<4;++k)
			{
				if(c[k]=='.')
				{
					map[j][k]=0;
					++num;
				}
				else if(c[k]=='X')map[j][k]=1;
				else if(c[k]=='O')map[j][k]=2;
				else if(c[k]=='T')map[j][k]=3;
			}
		}
		bool o,x;
		for(int j=0;j<4;++j)
		{
			o=true,x=true;
			for(int k=0;k<4;++k)
			{
				if((map[j][k]&1)==0)x=false;
				if((map[j][k]&2)==0)o=false;
				if(!x&&!o)break;
			}
			if(o||x)break;			
		}
		if(!o&&!x)
		{
			for(int j=0;j<4;++j)
			{
				o=true,x=true;
				for(int k=0;k<4;++k)
				{
					if((map[k][j]&1)==0)x=false;
					if((map[k][j]&2)==0)o=false;
					if(!x&&!o)break;
				}
				if(o||x)break;			
			}
		}
		if(!o&&!x)
		{
			o=true,x=true;
			for(int k=0;k<4;++k)
			{
				if((map[k][k]&1)==0)x=false;
				if((map[k][k]&2)==0)o=false;
				if(!x&&!o)break;
			}
			if(!o&&!x)
			{
				o=true,x=true;
				for(int k=0;k<4;++k)
				{
					if((map[k][3-k]&1)==0)x=false;
					if((map[k][3-k]&2)==0)o=false;
					if(!x&&!o)break;
				}
			}
		}
		if(x)printf("Case #%d: X won\n",i);
		else if(o)printf("Case #%d: O won\n",i);
		else if(num==0)printf("Case #%d: Draw\n",i);
		else printf("Case #%d: Game has not completed\n",i);
	}
	return 0;
}