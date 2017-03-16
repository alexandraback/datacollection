#include <stdio.h>
#include <string.h>

#define LEN 100
#define MAP "yhesocvxduiglbkrztnwjpfmaq"

int main(void)
{
	char str[LEN + 1];
	int t, T, k, len;
	FILE *in, *out;
	
	in = fopen("input.txt", "rt");
	out = fopen("output.txt", "wt");
	
	fscanf(in, "%d", &T);
	fscanf(in, "%*[ \n\r]");
	for (t = 1; t <= T; t++)
	{
		fscanf(in, "%[^\n\r]", str);
		fscanf(in, "%*[\n\r]");
		
		len = strlen(str);
		for (k = 0; k < len; k++)
			if (str[k] != ' ') str[k] = MAP[str[k] - 'a'];
		
		fprintf(out, "Case #%d: %s\n", t, str);
	}
	
	fclose(in);
	fclose(out);
	return 0;
}