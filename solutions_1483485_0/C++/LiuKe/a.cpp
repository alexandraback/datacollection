#include<iostream>
#include<cstdio>
using namespace std;
const char table[27]="yhesocvxduiglbkrztnwjpfmaq";
int T;
char c;

int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d\n",&T);
	for (int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		do
		{
			c=getchar();
			if (c>='a' && c<='z') putchar(table[c-'a']);
			else putchar(c);
		}
		while (c!='\n');
	}
	fclose(stdin);	fclose(stdout);
	return 0;
}
	
