#include <cstdio>

char change[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

int main()
{
	FILE* in = fopen("input.txt", "r");
	FILE* out = fopen("output.txt", "w");
	bool next = true; int n; fscanf(in, "%d\n", &n);int i = 1;
	while (!feof(in))
	{
		if (next) fprintf(out, "Case #%d: ", i);
		char c;
		fscanf(in, "%c", &c);
		if (c == '\n')
		{
			fprintf(out, "\n"); next = true; i++; continue;
		}
		if (c == ' ') fprintf(out, " ");
		else fprintf(out, "%c", change[c-'a']); next = false;
	}
}
