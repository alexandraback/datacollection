#include <fstream>
using namespace std;

ifstream fin;
ofstream fout;

int T;
double C,F,X;
double t;
double s;

void solve()
{
	t = 0;
	s = 2;
	while(X > 1e-10)
	{
		double t1 = X/s;
		double t2 = C/s+X/(s+F);
		if(t1 > t2)
		{
			t += C/s;
			s += F;
		}
		else
		{
			t += t1;
			X = 0;
		}
	}
}
void main()
{
	fin.open("in.txt");
	fout.open("out.txt");
	fout.precision(10);
	fin >> T;
	for (int i = 0; i < T; i++)
	{
		fin >> C >> F >> X;
		solve();
		fout << "Case #" << i+1 << ": " << t << endl;
	}
	fin.close();
	fout.close();
}