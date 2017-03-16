#include <iostream>
#include <fstream>
using namespace std;

//#define cin fin
#define cout fout
int main() {
	ifstream fin("haha.in");
	ofstream fout("output.out");
	int T;
	cin >> T;
	for (int k = 0; k<100; k++) {
		int R, C, W, ans;
		ans = 0;
		cin >> R >> C >> W;
		ans += R * C / W;
		if (C%W !=0)
			ans++;
		ans += W - 1;
		cout << "Case #" << k + 1 << ": " << ans << endl;

	}
	fin.close();
	fout.close();
	system("pause");
	return 0;
}
