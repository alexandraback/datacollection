#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <sstream>
#include <set>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <cstdio>
//#include <cstdlib>
#include <cstring>
#include <numeric>
#include <bitset>
#include <deque>
#include <memory>

const long long LINF = (5e17);
const int INF = 1000000000;
#define EPS 1e-7
const int MOD = 1000000007;

using namespace std;

int main() {
	ifstream ifs("/Users/iseki/Downloads/input.txt");
	ofstream ofs("/Users/iseki/Downloads/output.txt");
	int T;
	ifs >> T;
	for (int i=1; i<=T; ++i) {
		int X,R,C;
		ifs >> X >> R >> C;
		int x = X + 1;
		bool gabriel = true;
		for (int w=1; w<x; ++w) {
			int h = x - w;
			gabriel &= min(w,h) <= min(R,C) && max(w,h) <= max(R,C);
		}
		gabriel &= (R*C)%X == 0;
		if (X == 4 && min(R,C) == 2 && max(R,C) == 4)
			gabriel = false;
		string ans = gabriel ? "GABRIEL" : "RICHARD";
		ofs << "Case #" << i << ": " << ans << endl;
	}
}