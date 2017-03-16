#include<stdio.h>
#include<string.h>
int main()
{
	freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	int c, sc = 0;
	char fuck[26][3]={	"ay","bh","ce","ds",
		 				"eo","fc","gv","hx",
						"id","ju","ki","lg",
						"ml","nb","ok","pr",
						"qz","rt","sn","tw",
						"uj","vp","wf","xm",
						"ya","zq"
	};
	char str1[111], str2[111];
	for(scanf("%d\n",&c); c; --c)
	{
		
		gets(str1);
		int len = strlen(str1);
		for(int i = 0; i < len; ++i)
		{
			if(str1[i] != ' ')
				str2[i] = fuck[str1[i]-'a'][1];
			else
				str2[i] = str1[i];
		}
		str2[len] = '\0';
		printf("Case #%d: %s\n",++sc,str2);
	}
	return 0;
}
