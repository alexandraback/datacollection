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

vector<int> vals;
int n;

int rec(int pos, int mote)
{
	if (pos == n)
		return 0;
	int res = 0;
	while (pos < n && mote > vals[pos]) {
		mote += vals[pos];
		pos++;
	}

	if (pos == n) return 0;
	if (mote == 1) return 1 + rec(pos + 1, mote);
	int count = 0;
	int cur_mote = mote;
	while (cur_mote <= vals[pos]) {
		cur_mote += cur_mote - 1;
		count++;
	}

	return min(1 + rec(pos + 1, mote), count + rec(pos + 1, cur_mote + vals[pos]));
}

int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);

	int z;
	cin >> z;
	for (int q=0;q<z;q++) {
		int a;
		cin >> a >> n;

		vals.resize(n);
		for (int i=0;i<n;i++) {
			cin >> vals[i];
		}

		sort(vals.begin(), vals.end());
		int res = rec(0, a);

		cout << "Case #" << (q + 1) << ": " << res << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}