#include <iostream>
#include <fstream>
#include <iomanip> 

using namespace std;

int main() {
	ifstream input("B-large.in");
	ofstream output("ans.out");
	int t;
	double c, f, x;
	double ans, max;
	input >> t;
	for (int tt=0; tt<t; tt++) {
		input >> c >> f >> x;
		int num = 0;
		ans = -1;
		while (true) {
			max = 0;
			for (int i=0; i<num; i++)
				max += c/(2+i*f);
			max += x/(2+num*f);
			//cout << tt << "\t" << num << "\t" << max << endl;
			if (max<=ans || ans<0) ans = max;
			else if (max>ans) break;
			//if (x/(2+num*f)<c) break;
			num++;
		}
		output << "Case #" << tt+1 << ": "; 
		output << setprecision(7) <<std::fixed << ans << endl;
	}
}