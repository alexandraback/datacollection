///////////////////////////////////////////////////////////////////////////////
// TESTING PARAMETERS
const char* FILENAME="D%d.in";
int FILE_FROM = 0;
int FILE_TO = 0;

#include <vector>
#include <algorithm>
const bool OUT_FILE = true;
FILE *FILE_OUT;

///////////////////////////////////////////////////////////////////////////////

void ProcessFile(FILE* fin)
{
	int T;
	fscanf(fin, "%d", &T);
	for (int test_case=0; test_case<T; ++test_case)
	{
		std::vector<double> Naomi, Ken;
		int N;
		fscanf(fin, "%d", &N);
		Naomi.resize(N);
		Ken.resize(N);
		for (int n=0; n<N; ++n)
			fscanf(fin, "%lf", &Naomi[n]);
		for (int n=0; n<N; ++n)
			fscanf(fin, "%lf", &Ken[n]);
		std::sort(Naomi.begin(), Naomi.end());
		std::sort(Ken.begin(), Ken.end());

		int naomi_score_in_war = 0;
		for (int naomi_index=N-1, ken_index = N-1; naomi_index>=0; --naomi_index)
			if (Naomi[naomi_index]>Ken[ken_index])
				++naomi_score_in_war;
			else
				--ken_index;
		int naomi_score_in_deceitful_war = 0;
		for (int naomi_index=0, ken_index = 0; naomi_index<N; ++naomi_index)
			if (Naomi[naomi_index]>Ken[ken_index])
			{
				++naomi_score_in_deceitful_war;
				++ken_index;
			}
		fprintf(FILE_OUT, "Case #%d: %d %d\n", test_case+1, naomi_score_in_deceitful_war, naomi_score_in_war);
	}
}

///////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	char fileName[256];
	printf ("Which file: ");
	fgets ( fileName, 256, stdin );
	if (fileName[0]>13)
	{
		int i = atoi (fileName);
		FILE_FROM = FILE_TO = i;
	}
	for (int file_from=FILE_FROM; file_from<=FILE_TO; ++file_from)
	{
		sprintf(fileName, FILENAME, file_from);
		FILE *fin = fopen(fileName, "r");
		if (!fin)
		{
			printf("!!! CANNOT INF FILE %s", fileName);
			continue;
		} else {
			printf("Processing file: %s ...\n", fileName);
		}
		if (OUT_FILE)
		{
			char fileNameOut[256];
			sprintf(fileNameOut, "%s.out", fileName);
			FILE_OUT = fopen(fileNameOut, "w");
		} else
		{
			FILE_OUT = stdout;
		}
		ProcessFile(fin);
		fclose(fin);
		if (OUT_FILE)
			fclose(FILE_OUT);
	}
	printf("\nREADY!!!\n");
	getc(stdin);
	return 0;
}
