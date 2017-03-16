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

#define MAX 10000

vector<set<int> >  PAIR;

void Fill (int n, set<int>& mSet)
{
	int k =10;
	while (n>=k)
	{
		k *= 10;
	}

	for (int q=10; q<k; q*=10)
	{
		int m1= (n%q) * (k/q);
		int m2= n/q;
		int m =m1+m2;

		if (m>n)
			mSet.insert(m);
	}

}

void CalcAll ()
{
	PAIR.push_back(set<int>());

	for (int i=1; i< MAX; i++)
	{
		PAIR.push_back(set<int>());
		Fill (i, PAIR[i]);
	}
}


void RunCase (ifstream& fin, ofstream& fout)
{
	int A, B;
	fin>>A>>B;

	int r =0;
	for (int i=A; i<B; i++)
	{
		set<int>& mSet =PAIR[i];

		for (set<int>::iterator it =mSet.begin(); it!=mSet.end(); it++)
		{
			if ((*it)<=B)
				r++;
		}
	}

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
	CalcAll ();

	RunAll("C-small-attempt0.in", "C-small-attempt0.out");

	return;
}