#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;

char p[3][256];
char q[3][256];
char s[256];
char a[256];
char str[256];
int main()
{
	int n;
	freopen("A-small-attempt1.in","r",stdin);
	freopen("out.out","w",stdout);
	scanf("%d",&n);
	gets(str);
	strcpy(p[0],"ejp mysljylc kd kxveddknmc re jsicpdrysi");
	strcpy(p[1],"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
	strcpy(p[2],"de kr kd eoya kw aej tysr re ujdr lkgc jv");
	strcpy(q[0],"our language is impossible to understand");
	strcpy(q[1],"there are twenty six factorial possibilities");
 	strcpy(q[2],"so it is okay if you want to just give up");
	s['z'] = 'q';
	s['q'] = 'z';

	for(int i=0;i<3;i++)
	{
		int siz = strlen(p[i]);
		for(int j=0;j<siz;j++)
			s[p[i][j]] = q[i][j];
	}
//	for(int i='a';i<='z';i++)
//		cout<<(char)i<<" "<<(char)s[i]<<endl;
	for(int icas = 1;icas<=n;icas++)
	{
		gets(str);
		printf("Case #%d: ",icas);
		int siz = strlen(str);
		for(int i=0;i<siz;i++)
			printf("%c",s[str[i]]);
		printf("\n");
	}
	
}
