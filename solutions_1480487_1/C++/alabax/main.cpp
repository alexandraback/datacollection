#include <fstream>
#include <string>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int N, X;
int s[200];

double findd(double b, double e, int i)
{
	double m = (b + e) / 2;
	double v = s[i] + X*m;
	double t = m;
	for (int j=0; j<N; ++j)
	{
		if (i==j) continue;
		if (s[j] >= v) continue;
		double a = (v - s[j]) / X;
		t += a;
	}
	if (m < 1e-7) return 0.0;
	else if (t > 1.0 + 1e-7)
		return findd (b, m, i);
	else if (t < 1.0 - 1e-7)
		return findd (m, e, i);
	return m;
}

void solve()
{
	for (int i=0; i<N; ++i)
	{
		double y = findd(0.0, 1.0, i);
		fout << y * 100.0;
		if (i<N-1) fout << ' ';
	}
}

int main()
{
	int T;
	fin >> T;
	fout.precision(8);
	fout.setf(ios::fixed, ios::floatfield);
	for (int i=0;i<T;++i)
	{
		fin >> N;
		X = 0;
		for (int j=0;j<N;++j)
		{
			fin >> s[j];
			X += s[j];
		}
		fout << "Case #" << i+1 << ": ";
		solve();
		fout << endl;
	}
	return 0;
}