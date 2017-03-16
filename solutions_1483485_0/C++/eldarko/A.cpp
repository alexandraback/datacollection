#include <stdio.h>
#include <assert.h>
#include <string.h>

char map[26] = {
	'y', // a
	'h', // b
	'e', // c
	's', // d
	'o', // e
	'c', // f
	'v', // g
	'x', // h
	'd', // i
	'u', // j
	'i', // k
	'g', // l
	'l', // m
	'b', // n
	'k', // o
	'r', // p
	'z', // q
	't', // r
	'n', // s
	'w', // t
	'j', // u
	'p', // v
	'f', // w
	'm', // x
	'a', // y
	'q'  // z
};

char line[128];

int main()
{
	for(int i = 0; i < 26; i++)
	{
		for(int j = 0; j < 26; j++)
			if(i != j)
			{
				if(map[i] == map[j])
					printf("%c %c\n", map[i], map[j]);
				assert(map[i] != map[j]);
			}
	}

	int T;
	scanf("%d", &T);
	gets(line);
	
	for(int t = 0; t < T; t++)
	{
		gets(line);
		for(int i = 0, len = strlen(line); i < len; i++)
			if(line[i] != ' ')
				line[i] = map[ line[i] - 'a' ];
			
		printf("Case #%d: %s\n", t + 1, line);
	}
	
	return 0;
}
