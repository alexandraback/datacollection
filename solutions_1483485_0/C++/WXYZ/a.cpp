#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char* s1="ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jvyeqz";
char* s2="our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give upaozq";

char s[1000];
int main()
{
	int t,tt,i,j;
	scanf("%d",&t);
	gets(s);
	for (tt=1;tt<=t;tt++)
	{
		gets(s);
		printf("Case #%d: ",tt);
		for (i=0;s[i]!='\0';i++)
		{
			for (j=0;;j++)
			{
				if (s1[j]==s[i])
				{
					printf("%c",s2[j]);
					break;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
