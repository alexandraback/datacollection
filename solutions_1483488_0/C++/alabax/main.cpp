#include <fstream>
#include <string>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int A, B;

void solve()
{
	int k=0;
	int m=10;
	for (;A/m!=0;m*=10);
	m/=10;
	int ex[10] = {0};
	
	for (int i=A;i<=B;++i)
	{
		int exp = 0;
		for (int x=10;x<=m;x*=10)
		{
			int h = i%x;
			int l = i/x;
			int n = l + h*(m*10/x);
			if (n>i && n<=B)
			{
				int j=0;
				for (;j<exp;++j)
					if (ex[j]==n)
						break;
				
				if (j==exp)
				{
					++k;
					ex[exp++]=n;
				}
			}
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
		fin >> A >> B;
		
		fout << "Case #" << i+1 << ": ";
		solve();
		fout << endl;
	}
	return 0;
}