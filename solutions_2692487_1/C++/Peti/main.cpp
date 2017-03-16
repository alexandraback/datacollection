#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <list>
#include <stack>
#include <cstdio>
#include <sstream>
#include <map>
#include <cmath>
#include <queue>
#include <ctime>

#define FOR(i,n) for(int i = 0; i < (n); ++i)
#define SZ(x) ((int)((x).size()))

using namespace std;

typedef long long int LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

int main() {
	ifstream fin("a2.in");
	ofstream fout("a2.out");
	int t;
	fin >> t;

	VI maxSizeInMove(10000000);

	for (int tt = 1; tt <= t; ++tt) {
		int a, n;
		fin >> a >> n;
		vector<int> mote(n);
		FOR(i,n) {
			fin >> mote[i];
		}
		sort(mote.begin(),mote.end());

		int min;
		if (a == 1) {
			min = n;
		} else {
			int eaten = 0;
			while(eaten < n && mote[eaten] < a) a += mote[eaten++];
			maxSizeInMove[0] = a;
			int move = 0;
			while (eaten < n) {
				a += (a-1);
				while(eaten < n && mote[eaten] < a) a += mote[eaten++];
				maxSizeInMove[++move] = a;
			}
			min = move;
			while (move > 0) {
				--move;
				while(eaten > 0 && mote[eaten-1] >= maxSizeInMove[move]) --eaten;
				int newMin = move + (n - eaten);
				if (newMin < min) min = newMin;
			}
		}

		fout << "Case #" << tt << ": " << min << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}
