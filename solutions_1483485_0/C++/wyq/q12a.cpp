#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
	map<char, char> char_map;
	FILE *infile, *outfile;
	int i, j, k, c;
	char ch;
	char google[3][200];
	char normal[3][200];
	char arr_in[200], arr_out[200];
	
	infile = fopen("problem.txt", "r");
	for (i = 0; i < 3; i++)
		fgets(google[i], 200, infile);
	for (i = 0; i < 3; i++)
		fgets(normal[i], 200, infile);


	fclose(infile);
	/*
	for (i = 0; i < 3; i++)
	{
		printf("%s", google[i]);
		printf("%s", normal[i]);
	}
	k= 0;
	while (google[0][k] != '\0')
	{
		//char_map.insert(pair<char, char>(google[i][k], normal[i][k]));
		printf("%c", google[0][k]);
		k++;
	}
	*/
	for (i = 0; i < 3; i++)
	{
		k= 0;
		while (google[i][k] != '\0')
		{
			char_map.insert(pair<char, char>(google[i][k], normal[i][k]));
			k++;
		}
	}
	char_map.insert(pair<char, char>('q', 'z'));
	char_map.insert(pair<char, char>('z', 'q'));
	printf("insert done\n");
	/*
	for (ch = 'a'; ch <= 'z'; ++ch)
	{
		if (char_map.find(ch) != char_map.end())
		{
			printf("%c %c\n", ch, char_map.at(ch));
		}
	}
	*/
	infile = fopen("A-small-attempt0.in", "r");
	outfile = fopen("result.txt", "w");
	fscanf(infile, "%d\n", &c);
	for (i = 0; i < c; ++i)
	{
		k = 0;
		j = 0;
		fgets(arr_in, 200, infile);
		printf("%s", arr_in);
		while (arr_in[k] != '\0')
		{
			if (char_map.find(arr_in[k]) != char_map.end())
			{
				arr_out[j] = char_map.at(arr_in[k]);
				j++;
			}
			arr_out[j] = 0;
			k++;
		}
		fprintf(outfile, "Case #%d: ", i + 1);
		fputs(arr_out, outfile);
	}
	fclose(infile);
	fclose(outfile);

	return 0;
}