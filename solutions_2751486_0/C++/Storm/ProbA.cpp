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
		string str;
		cin >> str;
		int n;
		cin >> n;
		vector<int> vals;
		for (int i=0;i<str.size()-n+1;i++) {
			bool flag = true;
			for (int j=0;j<n;j++) {
				char ch = str[i+j];
				if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
					flag = false;
					break;
				}
			}
			if (flag) {
				vals.push_back(i);
			}
		}

		long long res = 0;
		for (int i=0;i<vals.size();i++) {
			long long left = vals[i] + 1;
			if (i > 0) left = vals[i] - vals[i-1];

			long long right = str.size() - n - vals[i] + 1;
			//long long right = str.size() - n - vals[i] + 1;
			//if (i < vals.size() - 1)
			//	right = vals[i+1] - vals[i];

			res += left * right;
		}

		cout << "Case #" << (q + 1) << ": " << res << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}