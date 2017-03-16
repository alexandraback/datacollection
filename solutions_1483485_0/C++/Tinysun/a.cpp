
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  max(x, y)  ((x)>(y)?(x):(y))
#define  abs(x)   ((x)<0?-(x):(x))

char buf[1024];

typedef  long long  int64;

char trans[26] = { 
'y', 'h', 'e', 's', 'o',
'c', 'v', 'x', 'd', 'u',
'i', 'g', 'l', 'b', 'k',
'r', 'z', 't', 'n', 'w',
'j', 'p', 'f', 'm', 'a', 
'q' };

// int _tmain(int argc, _TCHAR* argv[])

char conv(char c)
{
	if ( c == ' ')
		return c;
	return  trans[c - 'a'];
}

int main()
{
	gets(buf);
	int ncase = atoi(buf);
//	printf("%d\n", ncase);
  
	for(int i=1; i<=ncase; i++)
	{
		gets(buf);		
		int len = strlen(buf);

		printf("Case #%d: ", i);

		for(int j=0; j<len; j++)
			printf("%c", conv(buf[j]));
		printf("\n");
	}
  
	return  0;  
}
