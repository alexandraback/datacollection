#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

unsigned GetMaxGain(unsigned maxEnergy, unsigned regain, vector<unsigned> &V, unsigned event, unsigned startEnergy);

int main(int argc, char *argv[]) {

	fstream infile(argv[1]);
	if(!infile.is_open()) {
		cerr << "Could not open file " << argv[0] << endl;
		return -1;
	}

	string line;
	getline(infile, line);
	int testCase = atoi(line.c_str());
	for(int i = 1; i <= testCase; ++i) {
		cout << "Case #" << i << ": ";
		getline(infile, line);
		stringstream ss(line);
		unsigned E(0), R(0), N(0);
		ss >> E >> R >> N;
		vector<unsigned> V;
		getline(infile, line);
		stringstream sv(line);
		for(unsigned i = 0; i < N; ++i) {
			unsigned v(0);
			sv >> v;
			V.push_back(v);
		}
		cout << GetMaxGain(E, R, V, 0, E) << endl;
	}

	return 0;
}

unsigned GetMaxGain(unsigned maxEnergy, unsigned regain, vector<unsigned> &V, unsigned event, unsigned startEnergy) {
	if(event >= V.size())
		return 0;

	unsigned maxGain(0);
	unsigned remainE(startEnergy);

	//sort(V.begin(), V.end(), greater<unsigned>());

	//for(unsigned i = 0; i < V.size() && remainE > 0; ++i) {
	//	maxGain += remainE * V[i];
	//	remainE = min(R, E);
	//}

	for(unsigned i = 0; i <= startEnergy; ++i) {
		unsigned gain = V[event] * i + GetMaxGain(maxEnergy, regain, V, event + 1, min(startEnergy - i + regain, maxEnergy));
		if(gain > maxGain)
			maxGain = gain;
	}

	return maxGain;
}