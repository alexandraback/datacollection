#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define sz(v) int(v.size())
typedef long long ll;
typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		double C, F, X;
		cin >> C >> F >> X;
		double elapsed = 0;
		double speed = 2;
		double best = 1e18;
		for(int i = 0; i < 10000000; i++) {
			best = min(best, X / speed + elapsed);
			elapsed += C / speed;
			speed += F;
		}
		cout << "Case #" << t << ": " << setprecision(10) << fixed << best << endl;
	}
	return 0;
}
