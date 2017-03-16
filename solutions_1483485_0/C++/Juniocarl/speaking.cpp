#include <stdio.h>
#include <string.h>

char letters[] = {
	'y',
	'n',
	'f',
	'i',
	'c',
	'w',
	'l',
	'b',
	'k',
	'u',
	'o',
	'm',
	'x',
	's',
	'e',
	'v',
	'z',
	'p',
	'd',
	'r',
	'j',
	'g',
	't',
	'h',
	'a',
	'q'
};

char letra(char c){
	int pos = 0;
	while( letters[pos] != c )
		pos++;
	return pos + 'a';
}

int main()
{
	char line[100000];
	char trans[100000];
	int n;
	scanf("%d\n",&n);
	for(int k=1;k<=n;k++)
	{
	
		gets(line);
		for(int i=0;i< strlen(line) ;i++ )
		{
			if ( line[i] != ' ' )
				line[i] = letra(line[i]);
		}
		printf("Case #%d: %s\n",k,line);
	}	
	return 0;
}