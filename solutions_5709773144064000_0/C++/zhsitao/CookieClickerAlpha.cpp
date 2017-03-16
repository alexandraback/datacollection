#define IOSTREAM_TO_FSTREAM

#include<iostream>
#include<iomanip>
#ifdef IOSTREAM_TO_FSTREAM
#include<fstream>
#endif

using namespace std;

int main()
{
#ifdef IOSTREAM_TO_FSTREAM
	ifstream fin;
	fin.open("B-small-attempt0.in");
	cin.rdbuf(fin.rdbuf());
	ofstream fout;
	fout.open("B-small-attempt0.out");
	cout.rdbuf(fout.rdbuf());
#endif
	double c, f, x;
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		double s = 0.0, r = 2.0;
		cin >> c >> f >> x;
		while (x / (r + f) < (x - c) / r)
		{
			s += c / r;
			r += f;
		}
		s += x / r;
		cout << "Case #" << i << ": ";
		cout << fixed << setprecision(7) << s << endl;
	}
	return 0;
}
