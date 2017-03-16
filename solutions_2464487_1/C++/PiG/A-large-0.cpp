#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned long long ULL;

int main()
{
	ifstream Input("file.in");
	ofstream Output("file.out");
	int T;
	Input >> T;
	int kase = 0;
	ULL r, t;
	while ((++kase) <= T)
	{
		Input >> r >> t;
		ULL L = 0;
		ULL R = min(1000000000ULL, t / (2 * r - 1));
		ULL M;
		while (L < R)
		{
			M = (L + (R - L) / 2) + 1;
			if (2 * M * M + M * (2 * r - 1) <= t)
				L = M;
			else
				R = M - 1;
		}
		Output << "Case #" << kase << ": " << L << endl;
	}
	return 0;
}

