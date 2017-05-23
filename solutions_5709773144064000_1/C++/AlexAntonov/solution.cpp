#include <tchar.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <assert.h>
#include <iostream>

using namespace std;

struct Case{
	double c, f, x;

	double Solve() {
		double prev_time = x/2.0;
		double farms_time = 0.0;
		double divisor = 2.0;
		for (int farm_num = 1; ; ++farm_num) {
			farms_time = farms_time + c/divisor;
			divisor = 2.0 + f*farm_num;
			double cur_time = farms_time + x/divisor;
			if (cur_time >= prev_time)
				return prev_time;
			prev_time = cur_time;
		}
	}
};


struct Input{
	vector<Case> cases;

	Input(){
		ifstream ifs("i");
		assert(!ifs.bad());

		int case_num;
		ifs >> case_num;
		for (int i = 0; i < case_num; ++i)
		{
			Case cas;
			ifs >> cas.c >> cas.f >> cas.x;
			cases.push_back(cas);
		}
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Input inp;
	
	ofstream ofs("o.txt");	
	for (size_t i = 0; i < inp.cases.size(); ++i)
	{
		ofs << "Case #" << (i+1) << ": " << std::setprecision(std::numeric_limits<double>::digits10)
			<< inp.cases[i].Solve() << endl;
	}

//	cin.get();

	return 0;
}

