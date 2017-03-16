#include <cstdio>
using namespace std;

int n, s, t, p, res;
int dance[105];

void clean ()
{
	s = 0;
	p = 0;
	res = 0;
	t = 0;
	for (int i = 0; i < 105; i++) {
		dance[i] = 0;
	}
}

FILE* inputFile;
FILE* outputFile;

int main()
{
	inputFile = fopen("bl.in", "r");
	outputFile = fopen("bl.out", "w");
	fscanf(inputFile, "%d", &n);
	for (int i = 0; i < n; i++) {
		clean();
		fscanf(inputFile, "%d %d %d", &t, &s, &p);
		for (int j = 0; j < t; j++) {
			fscanf(inputFile, "%d", &dance[j]);
			if ((p*3) - dance[j] < 3) {
				res++;
				printf("[FOO] S: %d Res: %d\n", s, res);
			}
			else if ((p*3) - dance[j] < 5 && s > 0 && dance[j] >= p) {
				s--;
				res++;
				printf("[BAR] S: %d Res: %d\n", s, res);
			}
		}
		fprintf(outputFile, "Case #%d: %d\n", i+1, res);
	}
}  
