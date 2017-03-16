#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

const double PI = 3.1415926;

int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);

	int z;
	cin >> z;
	for (int q=0;q<z;q++) {
		long long r, t; 
		cin >> r >> t;

		long long low = 0;
		long long high = t;
		//long long mid = (low + high) / 2;
		while (low <= high) {
			long long mid = (low + high) / 2;
			double v = mid;
			v = v * ((2 * r + 1) + 2 * (v - 1));
			if (v > t)
				high = mid - 1;
			else
				low = mid + 1;
		}

		cout << "Case #" << (q + 1) << ": " << (low + high) / 2 << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}