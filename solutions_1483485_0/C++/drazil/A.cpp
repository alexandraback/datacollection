#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rev[300] ;
char str1[] = "ejpmysljylckdkxveddknmcrejsicpdrysi" ;
char cor1[] = "ourlanguageisimpossibletounderstand" ;
char str2[] = "rbcpcypcrtcsradkhwyfrepkymveddknkmkrkcd" ;
char cor2[] = "therearetwentysixfactorialpossibilities" ;
char str3[] = "dekrkdeoyakwaejtysrreujdrlkgcjv" ;
char cor3[] = "soitisokayifyouwanttojustgiveup" ;

char used[300] ;
char map[300] ;

int main(void)
{
	int i ;
	
	memset(used,0,sizeof(used)) ;
	memset(map,0,sizeof(map)) ;
	
	rev[(int)'y'] = 'a' ;
	rev[(int)'e'] = 'o' ;
	rev[(int)'q'] = 'z' ;

	used[(int)'y'] = used[(int)'e'] = used[(int)'q'] = 1 ;
	map[(int)'a'] = map[(int)'o'] = map[(int)'z'] = 1 ;

	for(i=0;str1[i]!='\0';i++)
	{
		rev[(int)str1[i]] = cor1[i] ;
		used[(int)str1[i]] = 1 ;
		map[(int)cor1[i]] = 1 ;
	}

	for(i=0;str2[i]!='\0';i++)
	{
		rev[(int)str2[i]] = cor2[i] ;
		used[(int)str2[i]] = 1 ;
		map[(int)cor2[i]] = 1 ;
	}

	for(i=0;str3[i]!='\0';i++)
	{
		rev[(int)str3[i]] = cor3[i] ;
		used[(int)str3[i]] = 1 ;
		map[(int)cor3[i]] = 1 ;
	}
	
	char a, b ;
	for(i='a';i<='z';i++)
	{
		if(used[i]==0) a = i ;
		if(map[i]==0) b = i ;
	}
	rev[(int)a] = b ;

	
	int t ;
	scanf("%d\n",&t) ;

	for(i=1;i<=t;i++)
	{
		int j ;
		char str[110] ;
		gets(str) ;
		printf("Case #%d: ",i) ;
		for(j=0;str[j]!='\0'&&str[j]!='\n';j++)
		{
			if(str[j]==' ') putchar(' ') ;
			else putchar(rev[(int)str[j]]) ;
		}
		putchar('\n') ;
	}
	
	return 0 ;
}
