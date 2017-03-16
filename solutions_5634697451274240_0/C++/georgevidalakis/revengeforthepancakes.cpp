#include <stdio.h>
using namespace std;

bool S[102];
bool C[102];

void mr(unsigned int l)
{
	for (unsigned int i = 0; i < l; i++) C[i] = S[i];
	for (unsigned int i = 0; i < l; i++) S[l - i - 1] = !C[i];
}

int main()
{
	unsigned int T, l, m, nl, h;
	int cc;
	FILE * fin;
	fin = fopen("revengeofthepancakes.in", "r");
	fscanf(fin, "%d", &T);
	cc = getc(fin);
	FILE * fout;
	fout = fopen("revengeofthepancakes.out", "w");
	for (unsigned int x = 1; x <= T; x++)
	{
		fprintf(fout, "Case #%d: ", x);
		l = 0;
		cc = getc(fin);
		while (cc != '\n' && cc != EOF)
		{
			S[l++] = cc == '+';
			cc = getc(fin);
		}
		m = 0;
		nl = l;
		while (S[nl - 1]) nl--;
		while (nl)
		{
			h = 0;
			if (S[0]) m++;
			while (S[h]) S[h++] = false;
			mr(nl);
			m++;
		    while (S[nl - 1]) nl--;
		}
		fprintf(fout, "%d\n", m);
	}
	fclose(fout);
	fclose(fin);
	return(0);
}
