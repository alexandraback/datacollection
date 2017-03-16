#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	ifstream fin("cookiein.txt");
	ofstream fout("cookieout.txt");

	fin.setf(ios::fixed, ios::floatfield);
	fin.precision(10); 
	fout.setf(ios::fixed, ios::floatfield);
	fout.precision(10);

	int T = 0;

	fin >> T;
	fout << "";

	double C, F, X;

	for (int i = 0; i < T; i++)
	{
		fin >> C >> F >> X;
		cout << C << " " << F << " " << X << " ";
		int r = 0;
		double t = 0;

		while (C / (2 + F*r) + X / (2 + F*(r + 1)) < X / (2 + F*r)) { t += C / (2 + F*r); r++; }
		t += X / (2 + F*r);

		fout << setprecision(11) << "Case #" << i + 1 << ": " << t << '\n';
		cout << setprecision(11) << t << '\n';
	}
	fin.close();
	fout.close();
}