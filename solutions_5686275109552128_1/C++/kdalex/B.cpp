#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <sys/resource.h>
#include <cassert>

using namespace std;

int rlimit = 100000;

int cost(int maxs, vector<int> &Pi) {
	int splits = 0;
	int msize = 0;
	for(auto pi: Pi) {
		int cs = (pi+maxs-1)/maxs;
		splits += cs-1;
		int ms = (pi+cs-1)/cs;
		msize = max(msize, min(maxs, ms));
	}

	return msize + splits;
}

int rec(vector<int> &Pi, vector<int> &Pk, int k) {
	int minc = 1999999;
	if(k == Pi.size()) {
		int maxs = 0;
		for(int i = 0; i < Pk.size(); ++i)
			maxs = max(maxs, Pk[i]);
		return maxs;
	}
	for(int sz = 1; sz <= Pi[k]; ++sz) {
		int splits = (Pi[k]+sz-1)/sz;
		Pk[k] = (Pi[k]+splits-1)/splits;
		int cc = splits - 1 + rec(Pi, Pk, k+1);
		if(cc < minc)
			minc = cc;
	}
	return minc;
}
int rec2(vector<int> &Pi) {
	int minc = Pi[0];
	for(int i = sqrt(Pi[0]); i <= Pi[0]; ++i)
		minc = min(cost(i, Pi),minc);
	return minc;
}

void run(int t) {
	int D;
	cin >> D;
	vector<int> Pi(D);
	for(int i = 0; i < D; ++i)
		cin >> Pi[i];
	sort(Pi.begin(), Pi.end(), [](const int&a, const int &b){return a>b;});

	vector<int> Pk(D);
	
//	int minc = rec(Pi, Pk, 0);
//	cout << "Case #" << t+1<< ": " << minc << endl;
	int	minc2 = rec2(Pi);
	cout << "Case #" << t+1<< ": " << minc2 << endl;
//	if(minc < minc2)
//	cout << "Case #" << t+1 << ": " << minc <<" " << minc2<< endl;
//	assert(minc2 == minc);
}


int main() {
	const rlim_t kStackSize = 4 * 1024 * 1024;   // min stack size = 16 MB
	struct rlimit rl;
	int result;

	result = getrlimit(RLIMIT_STACK, &rl);
	if (result == 0)
	{
		if (rl.rlim_cur < kStackSize)
		{
			rl.rlim_cur = kStackSize;
			result = setrlimit(RLIMIT_STACK, &rl);
			if (result != 0)
			{
				fprintf(stderr, "setrlimit returned result = %d\n", result);
			}
		}
	}
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for(int i = 0; i < T; ++i)
		run(i);
	return 0;
}
