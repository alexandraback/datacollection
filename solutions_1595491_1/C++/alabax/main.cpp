#include <fstream>
#include <string>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int N, S, p;
int t[100];

void solve()
{
	int k=0;
	for (int i=0;i<N;++i)
	{
		int d = (t[i]+2)/3, r = t[i]%3;
		if (d>=p) ++k;
		else if (d+1==p && r!=1 && t[i]!=0 && S>0)
		{
			--S; ++k;
		}
	}
	fout << k;
}

int main()
{
	int T;
	fin >> T;
	for (int i=0;i<T;++i)
	{
		fin >> N >> S >> p;
		for (int j=0;j<N;++j)
			fin >> t[j];
		
		fout << "Case #" << i+1 << ": ";
		solve();
		fout << endl;
	}
	return 0;
}