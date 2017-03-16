#include <iostream>
#include <fstream>


int main()
{
	std::ifstream ifile("ifile");
	std::ofstream ofile("ofile");
	
	
	int T = 0;
	ifile >> T;
	
	for (int icase = 1; icase <= T; ++icase) {
		
		int sMax = 0;
		ifile >> sMax;
		
		std::string s;
		ifile >> s;
		
		int sum = 0;
		int ans = 0;
		for (int i = 0; i <= sMax; ++i) {
			int d = sum - i;
			if (d < ans) {
				ans = d;
			}
			sum += s[i] - int('0');
		}
		
		ofile << "Case #" << icase << ": " << -ans << std::endl;
	}
}
