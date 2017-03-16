#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);

	int z;
	cin >> z;
	for (int q=0;q<z;q++) {

		int n,s,p;
		cin >> n >> s >> p;
		vector<int> vals(n);
		for (int i=0;i<n;i++) {
			cin >> vals[i];
		}

		sort(vals.begin(), vals.end());
		int val1 = p + 2 * max(0, p-1);
		int val2 = p + max(0, p-2) + max(0, p-2);
		int res = 0;
		int count = 0;
		for (int i=0;i<n;i++) {
			if (vals[i] >= val1)
				res++;
			else if (vals[i] >= val2)
				count++;
		}

		res += min(count, s);

		cout << "Case #" << (q+1) << ": " << res << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}