#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

long long total = 0;
long long valid = 0;

void rec(int left, int right, int req, int rem, int all)
{
	if (rem == 0) {
		if (left >= req)
			valid++;
		total++;
		return;
	}

	if (left < all)
		rec(left + 1, right, req, rem - 1, all);
	if (right < all)
		rec(left, right + 1, req, rem - 1, all);
}
 
int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);
	
	int z;
	cin >> z;
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(12);
	for (int q=0;q<z;q++) {
		int n,x,y;
		cin >> n >> x >> y;

		long long complete=1;
		while ((complete * (complete + 1)) / 2 <= n) {
			complete += 2;
		}
		complete -= 2;

		if (abs(x) + y < complete) {
			cout << "Case #" << (q+1) << ": " << (double) 1.0 << endl;
			continue;
		}

		if (abs(x) + y >= complete + 2) {
			cout << "Case #" << (q+1) << ": " << (double) 0.0 << endl;
			continue;
		}

		int needed = y + 1;
		/*if (y == complete + 1)
			needed = 2 * complete + 3;*/
		int have = n - (complete * (complete + 1)) / 2;
		/*if (have < needed) {
			cout << "Case #" << (q+1) << ": " << (double) 0.0 << endl;
			continue;
		}
		if (have - (complete + 1) >= needed) {
			cout << "Case #" << (q+1) << ": " << (double) 1.0 << endl;
			continue;
		}*/

		valid = 0;
		total = 0;
		rec(0, 0, needed, have, complete + 1);
		
		cout << "Case #" << (q+1) << ": " << (double) valid / total << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}
