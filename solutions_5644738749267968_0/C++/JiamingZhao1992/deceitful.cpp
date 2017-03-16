#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
double naomi[1000];
double ken[1000];
bool used_n[1000];
bool used_k[1000];

int cmp(const void *a, const void *b)
{
	if(*(double*)a > *(double*)b)
		return 1;
	else
		return -1;
}

int main(int argc, char *argv[]) {
	ifstream fin("D-small-attempt1.in");
	ofstream fout("deceit.out");
	
	int cases;
	fin >> cases;
	for(int cnt = 1; cnt <= cases; ++cnt)
	{
		fout << "Case #" << cnt << ": ";
		int N;
		fin >> N;
		for(int i = 0; i < N; ++i)
		{
			fin >> naomi[i];
		}
		for(int i = 0; i < N; ++i)
		{
			fin >> ken[i];
		}
		qsort(naomi, N, sizeof(double), cmp);
		qsort(ken, N, sizeof(double), cmp);
/*
		for(int i = 0; i < N; ++i)
			cout << naomi[i] << " ";
		cout << endl;

		for(int i = 0; i < N; ++i)
			cout << ken[i] << " ";
		cout << endl;
*/
		int biggest = N - 1, smallest = 0;
		int score2 = 0;
		for(int i = N - 1; i >= 0; --i)
		{
			if(naomi[i] > ken[biggest])
			{
				//cout << naomi[i] << " " << ken[biggest] << endl;
				smallest ++;
				score2 ++;
			}
			else
				biggest --;
		}
		//cout << score << endl;
		int score1 = 0;
		int i;
		biggest = N - 1, smallest = 0;;
		for(i = 0; i < N; ++i)
		{
			//cout << naomi[i] << " " << ken[smallest] << endl;
			if(naomi[i] > ken[smallest])
			{
				score1 ++;
				smallest ++;
			}
			else
				biggest--;
		}

		//cout << score1 << endl;
		fout << score1 << " " << score2 << endl;
	}
}