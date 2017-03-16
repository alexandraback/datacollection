

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

struct sm1state {
	int a1;
	int a2;
	int a3;

	double p;
};

int main(int argc, char const *argv[])
{
	ifstream ifs(argv[1]);
	int ncases;
	ifs >> ncases;

	for (int casenum = 1; casenum < ncases+1; ++casenum) {
		int r, n, m, k;
		ifs >> r >> n >> m >> k;

		cout << "Case #" << casenum << ":" << endl;

		for(int i=0; i<r; ++i) {

			vector<int> products;
			for (int i = 0; i < k; ++i)
			{
				int prod;
				ifs >> prod;
				products.push_back(prod);
			}

			vector<sm1state> state_space;
			for(int i=2; i<=5; ++i) {
				for(int j=2; j<=5; ++j) {
					for(int k=2; k<=5; ++k) {
						sm1state state {i, j, k, 1.0/64};
						state_space.push_back(state);
					}
				}
			}

			// compute posterior using bayes rule
			for(auto product : products) {
				for(sm1state& state : state_space) {
					//cout << state.a1 << state.a2 << state.a3 <<  " (p: " << state.p << ")" << endl;

					double post = 0;
					if(product == 1) {
						post += 1.0;
					}
					if(product == state.a1) {
						post += 1.0;
					}
					if(product == state.a2) {
						post += 1.0;
					}
					if(product == state.a3) {
						post += 1.0;
					}
					if(product == state.a1 * state.a2) {
						post += 1.0;
					}
					if(product == state.a1 * state.a3) {
						post += 1.0;
					}
					if(product == state.a3 * state.a2) {
						post += 1.0;
					}
					if(product == state.a1 * state.a2 * state.a3) {
						post += 1.0;
					}


					state.p *= (post/8.0);
				}
			}

			sm1state pmax = state_space.at(0);

			for(auto state : state_space) {
				//cout << state.a1 << state.a2 << state.a3 <<  " (p: " << state.p << ")" << endl;
				if(state.p > pmax.p) {
					pmax = state;
				}
			}

			cout << pmax.a1 << pmax.a2 << pmax.a3 <<  endl;
		}
	}

	return 0;
}

