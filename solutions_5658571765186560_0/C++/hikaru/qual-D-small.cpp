#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <string>
#include <set>
using namespace std;

int main(int argc, char* argv[])
{
#ifdef _MSC_VER
	if (argc > 1) {
		FILE* fp;
		freopen_s(&fp, argv[1], "r", stdin);
	}
#endif

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int X, R, C;
		cin >> X >> R >> C;

		bool bOK;
		switch (X) {
		case 1:
			bOK = true;
			break;
		case 2:
			bOK = ((R * C) % 2) == 0;
			break;
		case 3:
			bOK = (R == 2 && C == 3) || (R == 3 && C == 2)
				|| (R == 3 && C == 3)
				|| (R == 3 && C == 4) || (R == 4 && C == 3);
			break;
		case 4:
			bOK = (R == 3 && C == 4) || (R == 4 && C == 3)
				|| (R == 4 && C == 4);
			break;
		}

		
		cout << "Case #" << t << ": " << (bOK ? "GABRIEL" : "RICHARD") << endl;
	}

	return 0;
}
