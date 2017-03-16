#include<stdio.h>
#include<string.h>
int main()
{
	int t,i,j;
	char g[300];
	scanf("%d",&t);
	j=0;
	while(j<=t)
	{
		gets(g);
		for(i=0;i<strlen(g);i++)
		{
			if(g[i]=='a')g[i]='y';
			else if(g[i]=='b')g[i]='h';
			else if(g[i]=='c')g[i]='e';
			else if(g[i]=='d')g[i]='s';
			else if(g[i]=='e')g[i]='o';
			else if(g[i]=='f')g[i]='c';
			else if(g[i]=='g')g[i]='v';
			else if(g[i]=='h')g[i]='x';
			else if(g[i]=='i')g[i]='d';
			else if(g[i]=='j')g[i]='u';
			else if(g[i]=='k')g[i]='i';
			else if(g[i]=='l')g[i]='g';
			else if(g[i]=='m')g[i]='l';
			else if(g[i]=='n')g[i]='b';
			else if(g[i]=='o')g[i]='k';
			else if(g[i]=='p')g[i]='r';
			else if(g[i]=='q')g[i]='z';
			else if(g[i]=='r')g[i]='t';
			else if(g[i]=='s')g[i]='n';
			else if(g[i]=='t')g[i]='w';
			else if(g[i]=='u')g[i]='j';
			else if(g[i]=='v')g[i]='p';
			else if(g[i]=='w')g[i]='f';
			else if(g[i]=='x')g[i]='m';
			else if(g[i]=='y')g[i]='a';
			else if(g[i]=='z')g[i]='q';
		}
		if(j>0)
			printf("Case #%d: %s\n",j,g);
		j++;	
	}
	return 0;
}
