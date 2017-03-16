#include <stdio.h>
#include <stdlib.h>

void Translate(char *str, char *dictionary);

int main(int argc, char *argv[])
{
	if(argc != 3)
		return 0;
	FILE *fp = fopen(argv[1], "r");
	FILE *ofp = fopen(argv[2], "w");

	int n;
	fscanf(fp, "%d\n", &n);

	char str[101];
	char dict[] = "yhesocvxduiglbkrztnwjpfmaq";
	for(int i = 1; i <= n; i++)
	{
		fscanf(fp, "%[^\n]\n", str);
		Translate(str, dict);
		fprintf(ofp, "Case #%d: %s\n", i, str);	
		str[0] = '\0';
	}

	fclose(fp);
	fclose(ofp);
	return 0;
}

void Translate(char *str, char *dictionary)
{
	while(*str != '\0')
	{
		if(*str != ' ')
			*str = dictionary[*str - 'a'];
		str++;
	}
}
