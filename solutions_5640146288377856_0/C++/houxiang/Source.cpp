#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <assert.h>
#include <algorithm>
#include <math.h>
#include <ctime>
#include <functional>

#include <Windows.h>

using namespace std;

int main(int argc, char* argv[]) {
	ifstream inf(argv[1]); 

	int TC = 0; 
	inf >> TC; 

	for (int tc = 1; tc <= TC; tc++) {
		int r, c, w; 

		inf >> r >> c >> w;

		if (c == w) {
			cout << "Case #" << tc << ": " << w << endl;
		}
		else {
			int ans = 0; 
			int pos = 0; 

			while (pos < c) {
				ans++; 
				pos += w; 
			}

			if (pos == c) {
				ans += w; 
				ans--; 
			}
			else {
				ans--; 
				ans += w; 
			}
			


			cout << "Case #" << tc << ": " << ans << endl;
		}
		
	}

	return 0; 
}