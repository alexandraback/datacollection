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

int k1,l1,s;
string k,l;
long long best = -1;
long long total = 0;
long long give = 0;

void rec(string str)
{
	if (str.size() == s) {
		long long c = 0;
		for (int i=0;i<str.size()-l1+1;i++) {
			bool flag = true;
			for (int j=0;j<l1;j++) {
				if (str[i+j] != l[j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				c++;
			}
		}

		best = max(best, c);
		give += c;
		total++;
		return;
	}

	for (int i=0;i<k1;i++) {
		rec(str + k[i]);
	}
}

int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);

	int z;
	cin >> z;
	for (int q=0;q<z;q++) {
		best = -1;
		total=0;
		give=0;
		cin >> k1 >> l1 >>s;
		cin >> k >> l;
		rec("");

		double res = best * total - give;
		res /= total;
		cout << "Case #" << (q + 1) << ": ";
		cout << std::setprecision(12) << res << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}