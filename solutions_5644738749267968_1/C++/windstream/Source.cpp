#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std; 

double Ken[1000];
double Naomi[1000];
int N;

ifstream in ("D-large.in");
ofstream out ("OUT.txt");

void CleanArray()
{
	for (int i = 0; i < 1000; i++)
	{
		Ken[i] = 0;
		Naomi[i] = 0;
	}
}
int Deceit()
{
	int score = 0;
	int NaBegin = 0, NaEnd = N-1;
	int KBegin = 0, KEnd = N-1;
	for (int i = 0; i < N; i++)
	{
		if (Naomi[NaBegin] < Ken[KBegin])
		{
			NaBegin++;
			KEnd--;
		}
		else 
		{
			NaBegin++;
			KBegin++;
			score++;
		}
	}
	return score;
}

int War()
{
	int score = 0;
	int NaBegin = 0, NaEnd = N-1;
	int KBegin = 0, KEnd = N-1;
	for (int i = 0; i < N; i++)
	{
		if (Ken[KBegin] < Naomi[NaBegin])
		{
			KBegin++;
			NaEnd--;
		}
		else 
		{
			NaBegin++;
			KBegin++;
			score++;
		}
	}
	return N-score;
}

void PRINT()
{
	for (int i = 0; i < N;i++)
	{
		out << Naomi[i] << " " << Ken[i] << endl;
	}
}
int main()
{

	int cases; 
	in >> cases;
	for (int i = 1; i <= cases; i++)
	{
		CleanArray();
		out << "Case #" << i << ": ";
		in >> N;
		for (int j = 0; j < N; j++)
			in >> Naomi[j];
		for (int j = 0; j < N; j++)
			in >> Ken[j];
		sort(Ken, Ken+N);
		sort(Naomi, Naomi+N);
		int DW = Deceit();
		int W = War();
		out << DW << " " << W << endl;
	}
	out.close();
	return 0;
}