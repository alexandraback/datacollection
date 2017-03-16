#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);
	
	int z;
	cin >> z;
	for (int q=0;q<z;q++) {
		int x, y;
		cin >> x >> y;
		int x1 = 0;
		int y1 = 0;
		int cur = 1;
		string res = "";
		while (x1 != x) {
			if (x1 > x) {
				if (x1 - cur >= x) {
					res += "W";
					x1 -= cur;
				}
				else {
					res += "E";
					x1 += cur;
				}
			}
			else {
				if (x1 + cur <= x) {
					res += "E";
					x1 += cur;
				}
				else {
					res += "W";
					x1 -= cur;
				}
			}
			cur++;
		}

		while (y1 != y) {
			if (y1 > y) {
				if (y1 - cur >= y) {
					res += "S";
					y1 -= cur;
				}
				else {
					res += "N";
					y1 += cur;
				}
			}
			else {
				if (y1 + cur <= y) {
					res += "N";
					y1 += cur;
				}
				else {
					res += "S";
					y1 -= cur;
				}
			}
			cur++;
		}

		cout << "Case #" << (q+1) << ": " << res << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}
