//NTheo 2015

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int, char**)
{
	for (;;)
	{
		std::string inname;
		std::string outname;
		std::cout << "input file?" << std::endl;
		std::cin >> inname;
		std::cout << "output file?" << std::endl;
		std::cin >> outname;
		std::ifstream input(inname);
		std::ofstream output(outname);
		int T;
		input >> T;
		for (int t = 0; t < T; t++)
		{
			int K, L, S;
			input >> K >> L >> S;
			string keyboard, target;
			input >> keyboard >> target;
			int maxi = pow(double(K), S) + DBL_EPSILON * 1000000;
			vector<long long> resulti;
			for (int i = 0; i < maxi; i++)
			{
				int j = i;
				string typed(S, '.');
				for (int k = 0; k < S; k++)
				{
					//if (i>maxi - 7 || j )
					//cout << typed << endl;
					//cin.ignore();
					typed[k] = keyboard[j%K];
					j /= K;
				}
				int nbi = 0;
				size_t pos = typed.find(target, 0);
				while (pos != string::npos)
				{
					nbi++;
					pos = typed.find(target, pos + 1);
				}
				resulti.push_back(nbi);
			}
			cout << "aiygiygiyg" << endl;
			long long maxBananas = *max_element(resulti.begin(), resulti.end());
			long long sumBananas = 0;
			for (long long x : resulti)
				sumBananas += x;
			cout << maxBananas << " " << sumBananas;
			double w = maxBananas - (sumBananas / double(maxi));
			output << setprecision(8);
			output << "Case #" << (t + 1) << ": " << w << std::endl;
		}
		std::cout << "done" << std::endl;
	}
	return 0;
}