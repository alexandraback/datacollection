#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <cstdint>

using namespace std;

struct Case{
	int a, b, k;

	int64_t Solve() {
		if (a <= k || b <= k)
			return int64_t(a)*b;

		int64_t count = 0;		

		for (int i = k; i < a; ++i)
		for (int j = k; j < b; ++j)
			if ((i&j) < k)
				++count;
		return count + int64_t(k)*b + int64_t(k)*(int64_t(a) - k);
	}
};


struct Input{
	vector<Case> cases;

	Input(){
		ifstream ifs("i");
		assert(!ifs.bad());

		int case_num;
		ifs >> case_num;
		cases.resize(case_num);
		for (int case_ind = 0; case_ind < case_num; ++case_ind)
		{
			Case&
				cas = cases[case_ind];
			ifs >> cas.a >> cas.b >> cas.k;
		}
	}
};


int main()
{
	Input inp;
	
	ofstream ofs("o.txt");	
	for (size_t i = 0; i < inp.cases.size(); ++i)
	{
		int64_t answer = inp.cases[i].Solve();
		ofs << "Case #" << (i+1) << ": " << answer << endl;
	}

	return 0;
}

