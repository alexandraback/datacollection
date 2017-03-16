#include <stdio.h>
#include <algorithm>

using namespace std;

const char a[3][50]={"ejp mysljylc kd kxveddknmc re jsicpdrysi", 
				"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
				"de kr kd eoya kw aej tysr re ujdr lkgc jv"};
				
const char b[3][50]={"our language is impossible to understand",
				"there are twenty six factorial possibilities", 
				"so it is okay if you want to just give up"};				

char mymap[128];
char str[120];

int main()
{
	freopen("ain.txt", "r", stdin);
	freopen("aout.txt", "w", stdout);
	int T, i, j, cas=0;
	for (i=0; i<3; i++)
	{
		for (j=0; a[i][j]!='\0'; j++)
		  mymap[a[i][j]]=b[i][j];
	}
	mymap['q']='z'; 
	mymap['z']='q'; 
/*	
	sort(mymap+'a', mymap+'z'+1);
	for (i='a'; i<='z'; i++)
	  printf("%c:%c\n", i, mymap[i]);
*/  
	scanf("%d\n", &T);
	while (T--)
	{
		gets(str);
		for (i=0; str[i]!='\0'; i++)
		  if ('a'<=str[i] && str[i]<='z') str[i]=mymap[str[i]];
		printf("Case #%d: %s\n", ++cas, str);  
	}
	return 0;
}