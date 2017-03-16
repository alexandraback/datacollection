#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;

const char inFileName[] = "B-small.in";
const char outFileName[] = "B-small.out";

const int MaxX = 100;

int T;
char s[510];

int main() {
	
	FILE* inFile = fopen(inFileName, "r");
	FILE* outFile = fopen(outFileName, "w");

	fscanf(inFile, "%d", &T);
	for (int t = 0; t < T; t++) 
	{
		int x, y;
		fscanf(inFile, "%d%d", &x, &y);
		int X = abs(x), Y = abs(y);
		
		for (int i = 0; i < 2 * X; i++)
		{
			if ((i % 2 == 0 && x < 0) || (i % 2 == 1 && x > 0)) s[i] = 'E';
			else s[i] = 'W';
		}
		for (int i = 2 * X; i < 2 * X + 2 * Y; i++)
		{
			if ((i % 2 == 0 && y < 0) || (i % 2 == 1 && y > 0)) s[i] = 'N';
			else s[i] = 'S';
		}
		s[2 * X + 2 * Y] = '\0';

		fprintf(outFile, "Case #%d: %s\n", t + 1, s);
	}	
	
	fclose(inFile);
	fclose(outFile);
	return 0;
}
