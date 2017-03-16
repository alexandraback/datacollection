#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;
//ofstream fout("a.out");

int main()
{
	int R,C,T,W;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> R >> C >> W;
		if (W == 1)
			cout << "Case #" << t << ": " << R * C << endl;
		else
		{
			int res = (C - 1) / W + W;
			cout << "Case #" << t << ": " << (C / W) * (R - 1) + res << endl;
		}
	}
}
