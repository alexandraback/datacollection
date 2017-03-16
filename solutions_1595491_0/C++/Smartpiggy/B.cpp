#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
typedef __int64 LONG; 

enum TYPE
{
	OK,
	SURPRISING, 
	NONE,
};

int Calc(int total, int p)
{
	if (total<p)
		return NONE;

	int r =total -p;

	if (r>= (p-1)*2)
		return OK;

	if (r>= (p-2)*2)
		return SURPRISING;

	return NONE;
}

int C[3];

void RunCase (ifstream& fin, ofstream& fout)
{
	C[0] =0;
	C[1] =0;
	C[2] =0;

	int N, S, p;
	fin >>N>>S>>p;

	for (int i=0; i<N; i++)
	{
		int total;
		fin>>total;

		int t = Calc(total, p);
		C[t] ++;
	}

	int r = C[0] +min(C[1], S);

	fout<<r;
}

void RunAll(const char* fnameIn, const char* fnameOut)
{
	ifstream fin(fnameIn);
	ofstream fout(fnameOut);

	int caseCount;
	fin >> caseCount;

	for (int i=0; i<caseCount; i++)
	{
		fout<<"Case #"<<i+1<<": ";
		RunCase (fin, fout);
		fout<<"\n";
	}
}

void main()
{
	RunAll("B-small-attempt0.in", "B-small-attempt0.out");

	return;
}