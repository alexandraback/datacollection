#include <cstdio>

const char *mappingfile = "mapping.in";

FILE *mapping;

char map[26];
char input[1024];

int char2int(char c)
{
	return (int)(c - 97);
}

void translate(char *text)
{
	for (int i = 0; *(text+i) != 0; i++)
	{
		int x = char2int(*(text+i));
		if (x >= 0 && x < 26)
			printf("%c", map[x]);
		else
			printf("%c", *(text+i));
	}
}

int main()
{
	// wczytaj funkcje mapping
	mapping = fopen(mappingfile, "r");
	for (int i = 0; i < 26; i++)
		fscanf(mapping, "%c", map + i);
	fclose(mapping);
	
	int z;
	scanf("%d", &z);
	getchar();
	for (int nr = 1; nr <= z; nr++)
	{
		gets(input);
		printf("Case #%d: ", nr);
		translate(input);
		printf("\n");
	}
	return 0;
}
