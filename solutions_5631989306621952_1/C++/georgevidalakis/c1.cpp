#include <fstream>
using namespace std;

int main()
{
    char S[3000];
	unsigned int T, f, l;
	FILE * fin;
	fin = fopen("c1.in", "r");
	FILE * fout;
	fout = fopen("c1.out", "w");
	fscanf(fin, "%d", &T);
	fgetc(fin);
	for (unsigned int x = 1; x <= T; x++)
	{
        fprintf(fout, "Case #%d: ", x);
        char c = fgetc(fin);
        S[1500] = c;
        unsigned int f = 1500, l = 1500;
        c = fgetc(fin);
        while (c != '\n' && c != EOF)
        {
              if(c < S[f]) S[++l] = c;
              else S[--f] = c;
              c = fgetc(fin);
        }
        for (unsigned int i = f; i <= l; i++) fprintf(fout, "%c", S[i]);
        fprintf(fout, "\n");
    }
	fclose(fin);
	fclose(fout);
	return(0);
}
