#include <iostream>
#include <sstream>
#include <numeric>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>

#define isOn(S, j) (S & (1ll << j))

using namespace std;

int main(){
	int tests;
	cin >> tests;
	for (int t = 0; t < tests; t++){
		int x, r, c;
		cin >> x >> r >> c;
		if ((r * c) % x != 0){
			cout << "Case #" << (t + 1) << ": RICHARD" << endl;
			continue;
		}
		if ((x == 4) && (min(r, c) <= 2)){
			cout << "Case #" << (t + 1) << ": RICHARD" << endl;
			continue;
		}
		if ((x == 4) && (max(r, c) < 4)){
			cout << "Case #" << (t + 1) << ": RICHARD" << endl;
			continue;
		}
		if ((x == 5) && (min(r, c) <= 2)){
			cout << "Case #" << (t + 1) << ": RICHARD" << endl;
			continue;
		}
		if ((x == 5) && (max(r, c) < 5)){
			cout << "Case #" << (t + 1) << ": RICHARD" << endl;
			continue;
		}
		if ((x == 6) && (min(r, c) <= 3)){
			cout << "Case #" << (t + 1) << ": RICHARD" << endl;
			continue;
		}
		if ((x == 6) && (max(r, c) < 6)){
			cout << "Case #" << (t + 1) << ": RICHARD" << endl;
			continue;
		}

		if (x >= 7){
			cout << "Case #" << (t + 1) << ": RICHARD" << endl;
			continue;
		}

		if ((x == 3) && (min(r, c) < 2)){
			cout << "Case #" << (t + 1) << ": RICHARD" << endl;
			continue;
		}

		if ((x == 1) || (x == 2)){
			cout << "Case #" << (t + 1) << ": GABRIEL" << endl;
			continue;
		}
		cout << "Case #" << (t + 1) << ": GABRIEL" << endl;
		continue;
	}
}
