#include<stdio.h>
#include<string.h>
#define maxn 1010
char str[maxn];
char trans[maxn]="yhesocvxduiglbkrztnwjpfmaq";
void print_str(char* s)
{
	int i=0;
	while(s[i])
	{
		if (s[i]>='a' && s[i]<='z')
		printf("%c",trans[(int)(s[i]-'a')]);
		else	printf("%c",s[i]);
		i++;
	}
}
int main()
{
	int cases,i;
	freopen("test.txt","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d\n",&cases);
	for(i=1;i<=cases;i++)
	{
		printf("Case #%d: ",i);
		gets(str);
		print_str(str);
		printf("\n");
	}
	return 0;
}
