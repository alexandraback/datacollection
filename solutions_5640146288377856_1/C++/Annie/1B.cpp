#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream fin("A.in");
ofstream fout("A.out");

int main()
{
	int testcases;
	fin >> testcases;
	for (int test = 0; test < testcases; ++test){
		int r, c, w, ans = 0;
		fin >> r >> c >> w;

		ans = c / w * r;
		if (c%w) ++ans;
		ans += w - 1;
		fout << "Case #" << test + 1 << ": " << ans << endl;
	}
	return 0;
}