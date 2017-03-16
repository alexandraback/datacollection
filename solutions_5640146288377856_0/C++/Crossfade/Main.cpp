#include "Precomp.h"
using namespace std;


int main()
{
	ifstream  src("Output.txt");
	string currentDate = currentDateTime();
	replace(currentDate.begin(), currentDate.end(), ':', '.');
	ofstream dst((string("Output") + currentDate + string(".txt")).c_str());
	dst << src.rdbuf();
	src.close();
	dst.close();

	ifstream in("Input.txt");
	ofstream out("Output.txt");

	int T;
	in >> T;

	for (int t = 0; t < T; ++t)
	{
		int R, C, W;
		in >> R >> C >> W;

		int result = 0;
		result += C / W * (R - 1);
		while (C >= W * 2)
		{
			result++;
			C -= W;
		}
		if (C == W)
		{
			result += W;
		}
		else
		{
			result += W + 1;
		}

		out << "Case #" << (t + 1) << ": " << result << endl;
	}

	return 0;
}