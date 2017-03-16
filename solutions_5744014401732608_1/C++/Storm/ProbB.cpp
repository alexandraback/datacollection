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

int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);

	int z;
	cin >> z;
	
	for (int q=0;q<z;q++) {
		long long b, m;
		cin >> b >> m;

		if ((1LL << (b-2)) < m) {
			cout << "Case #" << (q + 1) << ": IMPOSSIBLE" << endl;
			continue;
		}

		string str = "";
		for (int i=0;i<b;i++) {
			str = str + "0";
		}
		vector<string> vals(b, str);
		for (int i=1;i<b-1;i++) {
			for (int j=i+1;j<b;j++) {
				vals[i][j] = '1';
			}
		}
		m--;
		for (int i=1;i<b-1;i++) {
			if ((m & (1LL << (i-1))) != 0) {
				vals[0][b-i-1] = '1';
			}
		}
		vals[0][b-1] = '1';
		cout << "Case #" << (q + 1) << ": POSSIBLE" << endl;
		for (int i=0;i<b;i++) {
			cout << vals[i] << endl;
		}
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}