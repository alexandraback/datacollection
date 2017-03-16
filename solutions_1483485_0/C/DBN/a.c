#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char map[26];
int main(int argc, char *argv[])
{
	int num, i, j;
	char c;
	char in[3][1000] = {
	"ejp mysljylc kd kxveddknmc re jsicpdrysi",
	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
	"de kr kd eoya kw aej tysr re ujdr lkgc jv"
	};

	char out[3][1000] = {
	"our language is impossible to understand",
	"there are twenty six factorial possibilities",
	"so it is okay if you want to just give up"
	};
	
	for(i = 0; i < 26; ++i)
	{
		map[i] = 'Q';
	}
	
	for(i = 0; i < 3; ++i)
	{
		for(j = 0; j < strlen(in[i]); ++j)
		{
			map[in[i][j]-97] = out[i][j];
		}
	}
	
	map['q'-97] = 'z';
	map['z'-97] = 'q';
	
	for(i = 0; i < 26; ++i)
	{
		//printf("%c ", map[i]);
	}
	
	scanf("%d", &num);
	getchar();
	for(i = 0; i < num; ++i)
	{
		printf("Case #%d: ", i+1);
		while(1){
			c = getchar();
			if(c == '\n')
			{
				printf("\n");
				break;
			}
			else if(c == ' '){
				printf(" ");
			}
			else{
				printf("%c", map[c-97]);
			}
		}
	}

	return 0;
}