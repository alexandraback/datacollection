#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int t, x, a, b, k;
	ifstream f("input.txt");
	ofstream g("output.txt");
	f >> t;
	for(int x = 1; x <= t; x++) {
		f >> a >> b >> k;
		int ans = 0;
		for(int i = 0; i < a; i++) {
			for(int j = 0; j < b; j++) {
				if(((i & j) < k)) {
					ans++;
				}
			}
		}
		g << "Case #" << x << ": " << ans << endl;
	}
	f.close();
	g.close();
	return 0;
}
