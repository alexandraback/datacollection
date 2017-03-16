#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;

const char inFileName[] = "A-small.in";
const char outFileName[] = "A-small.out";

const int MaxN = 100100;

int T;
char s[MaxN];
int n;
long long sol;

bool isC(char x)
{
	return (x != 'a' && x != 'e' && x != 'i' && x != 'o' && x != 'u'); 
}

int main() {
	
	FILE* inFile = fopen(inFileName, "r");
	FILE* outFile = fopen(outFileName, "w");

	fscanf(inFile, "%d", &T);
	for (int t = 0; t < T; t++) 
	{
		fscanf(inFile, "%s %d\n", s, &n);
			
		int right = 0, count = 0;;
		sol = 0LL;
		int d = strlen(s);
		bool ok = false;
		int first = 0;

		for (int left = 0; left < d; left++)
		{
			while (right < d && count < n)
			{
				if (isC(s[right]))
				{
					if (ok) count++;
					else
					{
						ok = true;
						count = 1;
						first = right;
					}
				}
				else
					ok = false;

				right++;
			}

			if (count >= n)
			{
				sol = sol + (d - right + 1);
				if (left == first)
				{
					first++;
					count--;
				}
			}
		}

		fprintf(outFile, "Case #%d: %lld\n", t + 1, sol);
	}	
	
	fclose(inFile);
	fclose(outFile);
	return 0;
}
