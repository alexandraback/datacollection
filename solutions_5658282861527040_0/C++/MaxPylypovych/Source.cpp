#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

typedef unsigned int uint;

int main()
{
	ofstream output;
	ifstream input;
	input.open("input.txt");
	output.open("output.txt");


	uint T;
	input >> T;
	uint a, b, k,ans;

	for (unsigned long long t = 0; t < T; ++t)
	{
		input >> a>>b>>k;
		ans = 0;
		for (uint i = 0; i < a; ++i)
		{
			for (uint j = 0; j < b; ++j)
			{
				if ((i&j) < k)
					++ans;
			}
		}


		output << "Case #" << t + 1 << ": ";
//		if (b)
			output << ans;
//		else
//			output << "Fegla Won";


		output << "\n";


	}




	input.close();
	output.close();
	//	system("pause");
	return 0;
}
