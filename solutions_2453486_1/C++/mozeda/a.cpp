#include <cstdio>

char a[4][4];
int T;
bool p;
int main()
{
	scanf("%d\n", &T);
	for (int I=1;I<=T;++I)
	{
		for (int i=0;i<4;++i)
			scanf(" %s", &a[i]);
		int ans = -1;
		for (int i=0;i<4;++i)
		{
			bool p = true;
			for (int j=0;j<4;++j)
				if (a[i][j]=='.' || a[i][j] == 'O')
					p = false;
			if (p)
			{
				ans = 0;
				break;
			}
		}
		for (int i=0;i<4;++i)
		{
			bool p = true;
			for (int j=0;j<4;++j)
				if (a[j][i]=='.' || a[j][i] == 'O')
					p = false;
			if (p)
			{
				ans = 0;
				break;
			}
		}
		p = true; 
		for (int i=0;i<4;++i)
			if (a[i][i]=='.' || a[i][i]=='O')
				p=false;
		if (p)
		{
			ans=0;
		}
		p = true; 
		for (int i=0;i<4;++i)
			if (a[i][3-i]=='.' || a[i][3-i]=='O')
				p=false;
		if (p)
		{
			ans=0;
		}
		
		
		for (int i=0;i<4;++i)
		{
			bool p = true;
			for (int j=0;j<4;++j)
				if (a[i][j]=='.' || a[i][j] == 'X')
					p = false;
			if (p)
			{
				ans = 1;
				break;
			}
		}
		for (int i=0;i<4;++i)
		{
			bool p = true;
			for (int j=0;j<4;++j)
				if (a[j][i]=='.' || a[j][i] == 'X')
					p = false;
			if (p)
			{
				ans = 1;
				break;
			}
		}
		p = true; 
		for (int i=0;i<4;++i)
			if (a[i][i]=='.' || a[i][i]=='X')
				p=false;
		if (p)
		{
			ans=1;
		}
		p = true; 
		for (int i=0;i<4;++i)
			if (a[i][3-i]=='.' || a[i][3-i]=='X')
				p=false;
		if (p)
		{
			ans=1;
		}			
		if (ans==-1)
		{
			bool t = true;
			for (int i=0;i<4;++i)
				for (int j=0;j<4;++j)
				{
					if (a[i][j]=='.') ans = 3;
					t=false;
				}
			if (t) ans=4;
		}
		printf("Case #%d: ", I);
		if (ans==0) printf("X won\n");
		else if (ans==1) printf("O won\n");
		else if (ans==3) printf("Game has not completed\n");
		else printf("Draw\n");
	}
}