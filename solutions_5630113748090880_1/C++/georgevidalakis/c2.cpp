#include <fstream>
using namespace std;

int main()
{
	unsigned int T, N, C[2501], l, c;
	FILE * fin;
	fin = fopen("c2.in", "r");
	FILE * fout;
	fout = fopen("c2.out", "w");
	fscanf(fin, "%d", &T);
	for (unsigned int x = 1; x <= T; x++)
	{
        fprintf(fout, "Case #%d:", x);
        for (unsigned int i = 1; i < 2501; i++) C[i] = 0;
        fscanf(fin, "%d", &N);
        l = 2 * N * N - N;
        for (unsigned int i = 0; i < l; i++)
        {
            fscanf(fin, "%d", &c);
            C[c]++;
        }
        for (unsigned int i = 1; i < 2501; i++) if(C[i] % 2 == 1) fprintf(fout, " %d", i);
        fprintf(fout, "\n");
    }
	fclose(fin);
	fclose(fout);
	return(0);
}
