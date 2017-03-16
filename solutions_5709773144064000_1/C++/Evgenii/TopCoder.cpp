#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

//#define GEN_LOCAL_TEST
#define USE_LOCAL_TEST

#ifdef GEN_LOCAL_TEST
void genTest() {
	ofstream ofs("test.txt", ifstream::out);
	int n = 100000;
	ofs << n << endl;
	for (int i = 0; i < n; ++i)
		ofs << 0 << " ";
	ofs << endl;
	ofs.close();
}
#endif

int main(int argc, char* argv[])
{

	ifstream ifs("test.txt", ifstream::in);
	ofstream ofs("ans.txt", ifstream::out);

	int t;
	ifs >> t;

	double c, f, x;
	for (int idx = 0; idx < t; ++idx) {
		ifs >> c >> f >> x;
		double bestTime = x / 2.;
		int n = 1;
		while (true) {
			double rate = 2.;
			double curTime = 0.;
			for (int i = 0; i < n; ++i) {
				curTime += c / rate;
				rate += f;
			}
			curTime += x / rate;
			if (curTime > bestTime) break;
			bestTime = curTime;
			++n;
		}
		ofs.precision(7);
		ofs << "Case #" << idx + 1 << ": " << fixed << bestTime << endl;;
	}

	return 0;
}

