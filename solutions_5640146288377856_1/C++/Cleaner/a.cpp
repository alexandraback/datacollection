#include <iostream>
using namespace std;

int main() {
	int cs;
	cin >> cs;
	for (int cc = 1; cc <= cs; cc++) {
		int r, c, w;
		cin >> r >> c >> w;
		cout << "Case #" << cc << ": "
			<< c / w * r + w + (c % w == 0 ? -1 : 0) << "\n";
	}
}
