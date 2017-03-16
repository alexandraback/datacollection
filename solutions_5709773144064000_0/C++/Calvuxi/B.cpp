#include <fstream>

using namespace std;

double C, F, X;

double getCost(double afforded, double affordable, int level) {
	double direct = afforded + X/(2.0 + level * F);
	if (direct > affordable) return direct;
	else affordable = direct;
	double upgrading = getCost(afforded + C/(2.0 + level * F),
								affordable, level+1);
	if (direct < upgrading)	
		return direct;
	else
		return upgrading;			 
}

int main() {
	ifstream ifs("inputB.txt");
	if (ifs.is_open()) {
		ofstream ofs("outputB.txt");
		if (ofs.is_open()) {
			int T;
			ifs >> T;
			for (int i = 1; i <= T; i++) {
				ifs >> C;
				ifs >> F;
				ifs >> X;
				ofs.precision(7);
				ofs << "Case #" << i << ": " << fixed << getCost(0.0, X/2.0, 0) << endl;
			}
			ofs.close();
		}
		ifs.close();
	}
	return 0;
}
