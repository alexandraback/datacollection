#include<cstdio>
#include<cstring>
int h[200];
char s[200],s1[200];
bool u[200];
int main()
{
	int n,i,t=3;
	while(t--)
	{
		gets(s);
		gets(s1);
		n=strlen(s);
		for(i=0;i<n;i++)
		{
			if(s[i]!=' ')
			{
				h[s[i]]=s1[i];
				u[s1[i]]=true;
			}
		}
	}
	h['q']='z';
	u['z']=true;
	for(i=0;i<26;i++)if(!u['a'+i])h['z']='a'+i;
	/*for(i=0;i<26;i++)
	{
		printf("%c -> %c \n",'a'+i,h['a'+i]);
	}*/
	freopen("A-small-attempt1.in","r",stdin);
	freopen("out.out","w",stdout);
	int ca=1;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(s);
		n=strlen(s);
		printf("Case #%d: ",ca++);
		for(i=0;i<n;i++)
		{
			if(s[i]==' ')putchar(' ');
			else putchar(h[s[i]]);
		}
		puts("");
	}
	
	return 0;
}