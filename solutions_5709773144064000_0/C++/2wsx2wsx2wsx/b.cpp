#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int T;
double c, f, x;
double s, ans, tmp;
int main()
{
	ifstream fin("B-small-attempt0.in");
	ofstream fout("b.out");
	fin >> T;
	for(int t=1; t<=T; ++t)
	{
		s = 2;
		fin >> c >> f >> x;
		ans = x / s;
		tmp = c / s;
		while (tmp < ans)
		{
			s+= f;
			ans = min(ans, tmp+(x/s));
			tmp += c/s;
		}
		fout << "Case #" << t << ": "<< fixed << setprecision(10) << ans << endl;
	}
	fin.close();
	fout.close();
}
