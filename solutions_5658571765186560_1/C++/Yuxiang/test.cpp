#include <fstream>
#include <iostream>
using namespace std;

int main(){
	ifstream in("D-large.in");
	ofstream out("out");
	int t;
	in >> t;
	for (int z = 1 ; z <= t ; z++)
	{
		int x, r, c;
		in >> x >> r >> c;
		int test = true;
		if (r > c)
			swap(r, c);
		int sur = r * c;
		if (sur % x != 0)
			test = false;
		if ((x + 1) / 2 > r)
			test = false;
		if (x >= 7)
			test = false;
		if (x == 6 && r <= 3)
			test = false;
		if (x == 5 && r <= 3)
			test = false;
		if (x == 4 && r <= 2)
			test = false;
		if (test)
			out << "Case #" << z << ": GABRIEL" << endl;
		else
			out << "Case #" << z << ": RICHARD" << endl;
	}
	in.close();
	out.close();
	return 0;
}
