#include<cstdio>
int T;
char s[11][11];
bool ok;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	for (int t=1; t<=T; t++)
	{
		printf("Case #%d: ",t);
		for (int i=0; i<4; i++)
			scanf("%s",&s[i]);
		for (int i=0; i<4; i++)
		{
			ok=true;
			for (int j=0; j<4; j++)
				if (s[i][j]!='X' && s[i][j]!='T')
					ok=false;
			if (ok)
				break;
			ok=true;
			for (int j=0; j<4; j++)
				if (s[j][i]!='X' && s[j][i]!='T')
					ok=false;
			if (ok)
				break;
		}
		if (!ok)
		{
			ok=true;
			for (int i=0; i<4; i++)
				if (s[i][i]!='X' && s[i][i]!='T')
					ok=false;
		}
		if (!ok)
		{
			ok=true;
			for (int i=0; i<4; i++)
				if (s[i][3-i]!='X' && s[i][3-i]!='T')
					ok=false;
		}
		if (ok)
		{
			printf("X won\n");
			continue;
		}
		for (int i=0; i<4; i++)
		{
			ok=true;
			for (int j=0; j<4; j++)
				if (s[i][j]!='O' && s[i][j]!='T')
					ok=false;
			if (ok)
				break;
			ok=true;
			for (int j=0; j<4; j++)
				if (s[j][i]!='O' && s[j][i]!='T')
					ok=false;
			if (ok)
				break;
		}
		if (!ok)
		{
			ok=true;
			for (int i=0; i<4; i++)
				if (s[i][i]!='O' && s[i][i]!='T')
					ok=false;
		}
		if (!ok)
		{
			ok=true;
			for (int i=0; i<4; i++)
				if (s[i][3-i]!='O' && s[i][3-i]!='T')
					ok=false;
		}
		if (ok)
		{
			printf("O won\n");
			continue;
		}
		ok=true;
		for (int i=0; i<4; i++)
			for (int j=0; j<4; j++)
				if (s[i][j]=='.')
					ok=false;
		if (ok)
			printf("Draw\n");
		else
			printf("Game has not completed\n");
	}
	return 0;
}