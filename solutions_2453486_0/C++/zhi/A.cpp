#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int x=-1,y=-1,fill=0;
		char b[4][5],s[2]={'O','X'},ans='-';
		
		for(int j=0;j<4;j++)
			scanf("%s",b[j]);
		
		for(int j=0;j<4;j++)
			for(int k=0;k<4;k++)
			{
				if(b[j][k]=='T')
				{
					x=j;
					y=k;
				}
				if(b[j][k]!='.')
					fill++;
			}
		for(int j=0;j<2;j++)
		{
			if(x!=-1)
				b[x][y]=s[j];
			
			for(int k=0;k<4;k++)
				if(b[k][0]==s[j])
				{
					bool flag=true;
					for(int l=1;l<4;l++)
						if(b[k][l-1]!=b[k][l])
							flag=false;
					if(flag==true)
						ans=s[j];
				}
			
			for(int k=0;k<4;k++)
				if(b[0][k]==s[j])
				{
					bool flag=true;
					for(int l=1;l<4;l++)
						if(b[l-1][k]!=b[l][k])
							flag=false;
					if(flag==true)
						ans=s[j];
				}
			
			if(b[0][0]==s[j])
			{
				bool flag=true;
				for(int k=1;k<4;k++)
					if(b[k-1][k-1]!=b[k][k])
						flag=false;
				if(flag==true)
					ans=s[j];
			}

			if(b[0][3]==s[j])
			{
				bool flag=true;
				for(int k=1;k<4;k++)
					if(b[k-1][3-k+1]!=b[k][3-k])
						flag=false;
				if(flag==true)
					ans=s[j];
			}
		}
		
		if(ans=='-')
		{
			if(fill<16)
				printf("Case #%d: Game has not completed\n",i+1);
			else
				printf("Case #%d: Draw\n",i+1);
		}
		else
			printf("Case #%d: %c won\n",i+1,ans);
	}
	return 0;
}
