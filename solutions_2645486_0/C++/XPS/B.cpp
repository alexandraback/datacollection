#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
	FILE *fin, *fout;
	int T, E, R, N, v[10];
	int i, j, re;
	fin = fopen("in.txt","r");
	fout = fopen("out.txt","w");

	fscanf(fin, "%d", &T);
	for(i = 0 ; i < T ; i++)
	{
		fscanf(fin, "%d %d %d",&E, &R, &N);
		for(j = 0 ; j < N ; j++)
			fscanf(fin, "%d", &v[j]);

		sort(v, v+N);

		re = 0;
		re += v[N - 1] * E;
		for(j = N - 2 ; j >= 0 ; j--)
			re += v[j] * R;

		fprintf(fout, "Case #%d: %d\n", i+1, re);
	}
	fcloseall();
	return 0;
}