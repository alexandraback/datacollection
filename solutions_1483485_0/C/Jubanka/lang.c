#include <stdio.h>
#include <string.h>

// a zoo
// y qee

// our language is impossible to understand
// ejp mysljylc kd kxveddknmc re jsicpdrysi
//
// there are twenty six factorial possibilities
// rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
//
// so it is okay if you want to just give up
// de kr kd eoya kw aej tysr re ujdr lkgc jv

//                abcdefghijklmnopqrstuvwxyz
const char *lut = "ynficwlbkuomxsevzpdrjgthaq";


int main(int argc, char **argv)
{
	FILE *f;
	char inp[128];
	int i;
	int cs;

	f = fopen(argv[1], "r");
	if (!f) {
		fprintf(stderr, "Cannot open %s\n", argv[1]);
		return 1;
	}
	fscanf(f, "%d\n", &i);
	fprintf(stderr, "%d cases\n", i);
	cs = 1;
	while (fgets(inp, 128, f)) {
		for (i = 0; i < strlen(inp); i++) {
			if (isspace(inp[i]))	continue;
			inp[i] = (strchr(lut, inp[i]) - lut) + 'a';
		}
		printf("Case #%d: %s", cs, inp);
		cs++;
	}

	fclose(f);
	return 0;
}
