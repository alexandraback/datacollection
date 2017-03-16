#include <stdio.h>

char map[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
char str[1024];
char res[1024];
char used[26];

int main() {
	FILE *fi = fopen("a.in", "r");
	FILE *fo = fopen("a.out", "w");
	//FILE *fm = fopen("a.map", "w");

	int tests;
	fscanf(fi, "%d\n", &tests);
	for (int i=0; i<tests; i++) {
		int tmp;
		fgets(str, 1024, fi);
		int j;
		for (j=0; str[j]!=10&&str[j]!=0; j++)
			if (str[j]!=32)
				res[j] = map[str[j]-'a'];
			else
				res[j]=str[j];
		res[j]=0;
		fprintf(fo, "Case #%d: %s\n", i+1, res);
	}

	/*int tests;
	fscanf(fi, "%d\n", &tests);
	for (int i=0; i<tests; i++) {
		int tmp;
		fgets(str, 1024, fi);
		fscanf(fo, "Case #%d: ", &tmp);
		fgets(res, 1024, fo);
		for (int j=0; str[j]!=10&&str[j]!=0; j++)
			if (str[j]!=32)
				map[str[j]-'a'] = res[j];
	}

	for (int i=0; i<26; i++) {
		used[str[i]-'a']=1;
	}

	for (int i=0; i<26; i++)
		if (!used[i]) {
			map[16]=i+'a';
			break;
		}

	for (int i=0; i<26; i++)
		fprintf(fm, "'%c', ", map[i]?map[i]:'&');
	*/

	fclose(fi);
	fclose(fo);
	//fclose(fm);

	return 0;
}
