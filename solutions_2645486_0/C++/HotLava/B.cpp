

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

int next_maximum(int idx, const vector<int>& rewards) {
	if(idx >= rewards.size()) return -1;

	int max = rewards.at(idx);
	int maxidx = idx;
	for (int i = idx+1; i < rewards.size(); ++i)
	{
			if(rewards.at(i) > max) {
				max = rewards.at(i);
				maxidx = i;
			}
	}

	return maxidx;
}

int main(int argc, char const *argv[])
{
	ifstream ifs(argv[1]);
	int ncases;
	ifs >> ncases;

	for (int casenum = 1; casenum < ncases+1; ++casenum) {
		int e, r, n, vi;
		vector<int> rewards;
		ifs >> e >> r >> n;
		for (int i = 0; i < n; ++i)
			{
				ifs >> vi;
				rewards.push_back(vi);
			}

		int nmax = next_maximum(0, rewards);
		//cout << "Maximum at " << nmax << endl;
		int t = 0;
		int gain = 0;
		int current_energy = e;
		while(t < rewards.size()) {
			if(t<nmax && current_energy > e-r) {
				int new_energy = e-r;
				int diff = current_energy - new_energy;
				current_energy = new_energy;
				gain += rewards.at(t)*diff;
			} else if(t==nmax) {
				int new_energy = 0;
				int diff = current_energy - new_energy;
				current_energy = new_energy;
				gain += rewards.at(t)*diff;
				nmax = next_maximum(t+1, rewards);
				//cout << "Maximum at " << nmax << endl;
			} else {
				
			}

			current_energy += r;
			if(current_energy > e) current_energy = e;
			t += 1;
		}

		cout << "Case #" << casenum << ": " << gain << endl;
	}

	return 0;
}

