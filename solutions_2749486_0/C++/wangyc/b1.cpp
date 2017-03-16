#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream inf("b.in");
	ofstream ouf("b.out");
	
	int test, x, y;
	inf >> test;
	for (int ite = 1; ite <= test; ++ite) {
		inf >> x >> y;
		ouf << "Case #" << ite << ": ";
		if (x > 0) {
			for (int i = 0; i < x; ++i)
				ouf << "WE";;
		}
		else {
			for (int i = 0; i > x; --i)
				ouf << "EW";
		}
		if (y > 0) {
			for (int i = 0; i < y; ++i)
				ouf << "SN";
		}
		else {
			for (int i = 0; i > y; --i)
				ouf << "NS";
		}
		ouf << endl;
	}
	return 0;
}
