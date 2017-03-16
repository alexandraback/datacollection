#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <string.h>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vvi; 
typedef vector<string> vs;

#define PB push_back
const long double PI = 3.1415926535897932384626433832795;

vector<pair<long long, long long> > boxes, toys;
long long solve()
{
	long long bm = 0, tm = 0, nm = 0, res = 0;
	int bs = boxes.size(), ts = toys.size();
	//cout << "called with bs=" << bs << "ts=" <<ts << "\n";
	if (bs == 0 || ts == 0) return 0;
	vector<pair<long long, long long> > temp = toys, ttemp = boxes;
	if (boxes[bs-1].second == toys[ts-1].second) {
		if (boxes[bs-1].first < toys[ts-1].first) {
			res = boxes[bs-1].first;
			toys[ts-1].first -= boxes[bs-1].first;
			boxes.pop_back();
		} else {
			res = toys[ts-1].first;
			boxes[bs-1].first -= toys[ts-1].first;
			toys.pop_back();
		}
		//cout << "res = " << res << "\n";
		long long tempRes = res + solve();
		boxes = ttemp;
		toys = temp;
		return tempRes;
	} else {
		int x = false;
		while (toys.size() && toys[toys.size() - 1].second != boxes[bs - 1].second) toys.pop_back();
		if (toys.size()) {
			bm = solve();
			x = true;
		}
		toys = temp;
		temp = boxes;
		while (boxes.size() && toys[toys.size() - 1].second != boxes[boxes.size() - 1].second) boxes.pop_back();
		if (boxes.size()) {
			tm = solve();
			x = true;
		}
		boxes = temp;
		if (x == false) {
			temp = boxes;
			ttemp = toys;
			boxes.pop_back();
			toys.pop_back();
			nm = solve();
			boxes = temp;
			toys = ttemp;
		}
		//cout << "bm = " << bm << "tm = " << tm << "\n";
		//if (bm > tm) return bm;
		if (bm > tm) tm = bm;
		if (tm > nm) nm = tm;
		return nm;
	}
}

int main(int argc, char *argv[])
{
	int num_tc;
	ifstream myfile;
	myfile.open(argv[1]);
	myfile >> num_tc;
	
	for (int i=0; i<num_tc; ++i) {
		boxes.clear();
		toys.clear();
		long long N, M, num, type;
		myfile >> N >> M;
		for (int l=0; l<N; ++l) {
			myfile >> num >> type;
			boxes.PB(make_pair(num, type));
		}
		for (int l=0; l<M; ++l) {
			myfile >> num >> type;
			toys.PB(make_pair(num, type));
		}
		long long res = solve();
		cout << "Case #" << i + 1 << ": " << res << "\n";
	}
	myfile.close();
	return 0;
}
