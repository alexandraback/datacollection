#include <iostream>
#include <algorithm>

using namespace std;


int main(int argc, char* argv[])
{
	int T, N, S, p;
	cin >> T;
	for (int t = 0; t != T; ++t) {
		cin >> N >> S >> p;
		int a = 0, b = 0, s;
		for (int n = 0; n != N; ++n) {
			cin >> s;
			if (s < p) continue;
			int r = ((s - p) / 2) - p;
			if (r >= -1) a++;
			else if (r >= -2) b++;
		}
		cout << "Case #" << (t + 1) << ": " << (a + min(b, S)) << endl;
	}
	return 0;
}

