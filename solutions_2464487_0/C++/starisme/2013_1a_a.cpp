#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;


int main()
{
	//ifstream infile("test.in");
	ifstream infile("A-small-attempt0.in");
	//ifstream infile("A-small-attempt1.in");
	//ifstream infile("A-large.in");
	ofstream outfile("A.out", ios::out);
	int T;
	infile >> T;
	int testcase;
	for (testcase = 1;testcase <= T;testcase++)
	{
		int r,t ;
		infile >> r >> t;
		int cnt = 0;
		int R = r + 1;
		while (true)
		{
			t -= R*R - r*r;
			if (t < 0)
				break;
			cnt ++;
			R += 2;
			r += 2;
		}
		outfile << "Case #" << testcase << ": ";
		outfile << cnt;
		outfile << endl;
	}
	return 0;
}