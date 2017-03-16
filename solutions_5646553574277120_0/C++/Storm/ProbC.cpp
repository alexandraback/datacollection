#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);

	int z;
	cin >> z;
	for (int q1=0;q1<z;q1++) {
		int c,d,v;
		cin >> c >> d >> v;
		vector<int> vals(d);
		for (int i=0;i<d;i++)
			cin >> vals[i];

		int result = 0;
		do {
			vector<bool> poss(v+1, false);
			for (int i=0;i<vals.size();i++) {
				for (int j = poss.size()-1;j>0;j--) {
					if (j - vals[i] > 0 && poss[j-vals[i]]) {
						poss[j] = true;
					}
				}
				poss[vals[i]] = true;
			}

			bool flag = true;
			for (int i=1;i<poss.size();i++) {
				if (!poss[i]) {
					vals.push_back(i);
					result++;
					flag = false;
					break;
				}
			}

			if (flag)
				break;
		} while (1);

		cout << "Case #" << (q1+1) << ": " << result << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}