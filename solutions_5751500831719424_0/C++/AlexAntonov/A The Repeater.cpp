#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

struct Case{
	vector<string> strings;

	struct Elem{
		char ch;
		int count;
	};

	vector<vector<Elem>> elems;

	int Solve() {		
		elems.resize(strings.size());

		for (int i = 0; i < int(strings.size()); ++i)
		{
			int k = 0;
			while (k < int(strings[i].length())) {
				char ch = strings[i][k];
				int count = 1;
				if (i > 0) {
					if (elems[0].size() <= elems[i].size() || elems[0][elems[i].size()].ch != ch)
						return -1;
				}

				++k;
				while (k < int(strings[i].length()) && strings[i][k] == ch) { 
					++count;
					++k;
				}
				elems[i].push_back({ch, count});
			}

			if (elems[0].size() != elems[i].size())
				return -1;
		}
		return FindMin();
	}

	int FindMin() {
		int total = 0;
		for(int k = 0; k < int(elems[0].size()); ++k) {
			int avg = 0;
			for (int i = 0; i < int(elems.size()); ++i)
				avg += elems[i][k].count;													
			avg = int(round(avg * 1.0 / elems.size()));

			for (int i = 0; i < int(elems.size()); ++i)
				total += abs(avg - elems[i][k].count);
		}

		return total;
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
			int str_num;
			ifs >> str_num;
			cas.strings.resize(str_num);
			for (int i = 0; i < str_num; ++i) {
				string s;
				ifs >> s;
				cas.strings[i] = s;
			}
		}
	}
};


int main()
{
	Input inp;
	
	ofstream ofs("o.txt");	
	for (size_t i = 0; i < inp.cases.size(); ++i)
	{		
		ofs << "Case #" << (i+1) << ": ";
		int answer = inp.cases[i].Solve();
		if (answer == -1)
			ofs << "Fegla Won";
		else
			ofs << answer;
		ofs << endl;
	}

	return 0;
}

