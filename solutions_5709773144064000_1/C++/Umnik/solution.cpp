#include <iostream>       
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	ifstream in("t.in");
	ofstream out("t.out");

	int q;
	in >> q;
	for (int i = 1; i <= q; i++)
	{
		double c, f, x;
		in >> c >> f >> x;
		double res = 1e100;
		double a = 0;
		double b = 2;
		for (int j = 0;; j++)
		{
			if (a > res)
				break;
			res = min(res, a + x / b);
			a += c / b;
			b += f;
		}                   
		out << fixed << setprecision(7) << "Case #" << i << ": " << res << endl;
	}

	return 0;
}