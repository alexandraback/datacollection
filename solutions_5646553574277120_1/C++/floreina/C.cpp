#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream inf("C-large.in");
ofstream ouf("output.txt");

typedef long long ll;
vector <int> d;
int C, D, V;


int main() {
	int T; inf >> T;
	for (int t = 1; t <= T; ++t) {
		cerr << t << endl;
		inf >> C >> D >> V;
		d.clear();
		for (int i = 0; i < D; ++i) {
			int den;
			inf >> den;
			d.push_back(den);
		}
		int more = 0;
		if (find(d.begin(), d.end(), 1) == d.end()) {
			d.push_back(1);
			more += 1;
		}
		sort(d.begin(), d.end());
		ll sum = C;
		int pointer = 1;
		while (sum < V) {
			if (pointer == d.size()) {
				more += 1;
				sum += (sum + 1) * C;
			}
			else {
				if (sum < d[pointer] - 1) {
					more += 1;
					sum += (sum + 1) * C;
				}
				else {
					sum += ((ll)d[pointer]) * C;
					pointer++;
				}
			}
		}
		ouf << "Case #" << t << ": " << more << endl;
	}
}