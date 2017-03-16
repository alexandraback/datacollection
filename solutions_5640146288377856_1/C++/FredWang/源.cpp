#include <iostream>
#include <fstream>
using namespace std;
int a[100];
int ans(int r, int c, int w)
{
	if (c%w == 0)return r*(c / w) + w - 1;
	return r*(c / w) + w;
}
int main() {
	ifstream fin("C:\\Users\\ty\\Desktop\\codejam2015\\AL.in");
	ofstream fout("C:\\Users\\ty\\Desktop\\codejam2015\\B.txt");
	int t;
	fin >> t;
	for (int i = 0; i < t; ++i)
	{
		int c, r, w;
		fin >> r >> c >> w;
		a[i] = ans(r, c, w);
	}
	for (int i = 0; i < t; ++i)
	{
		fout << "Case #" << i + 1 << ": " << a[i] << endl;
	}
	fin.close();
	fout.close();
	return 0;
}
