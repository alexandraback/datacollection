#include <tchar.h>
#include <vector>
#include <set>
#include <fstream>
#include <algorithm>
#include <assert.h>
#include <iostream>

using namespace std;

struct Case{
	set<double> naomis_blocks;
	set<double> kens_blocks;

	int SolveWar() {
		set<double> kens_blocks2 = kens_blocks;

		for (auto it = naomis_blocks.begin(); it != naomis_blocks.end(); ++it)
		{
			auto
				it_ken = kens_blocks2.upper_bound(*it);
			if (it_ken != kens_blocks2.end())
				kens_blocks2.erase(it_ken);
			else
				return distance(it, naomis_blocks.end());
		}

		return 0;
	}

	int SolveDeceitfulWar() {
		int points = 0;		

		while (!naomis_blocks.empty()) {
			while (!naomis_blocks.empty() && *naomis_blocks.begin() < *kens_blocks.begin())		
			{
				naomis_blocks.erase(naomis_blocks.begin());
				kens_blocks.erase(--kens_blocks.end());
			}
			if (!naomis_blocks.empty()) {
				naomis_blocks.erase(naomis_blocks.begin());
				kens_blocks.erase(kens_blocks.begin());
				++points;
			}
		}

		return points;
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
			int block_num;
			ifs >> block_num;
			for (int i = 0; i < block_num; ++i) {
				double block;
				ifs >> block;
				cas.naomis_blocks.insert(block);
			}
			for (int i = 0; i < block_num; ++i) {
				double block;
				ifs >> block;
				cas.kens_blocks.insert(block);
			}

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
		int points = inp.cases[i].SolveWar();
		int deceitful_points = inp.cases[i].SolveDeceitfulWar();		
		ofs << "Case #" << (i+1) << ": " << deceitful_points << " " << points << endl;
	}

//	cin.get();

	return 0;
}

