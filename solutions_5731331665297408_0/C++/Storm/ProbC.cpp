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

int n,m;
bool flights[16][16];
vector<string> codes;
string best;

bool possible(vector<int> &order)
{
	stack<int> prev;
	prev.push(order[0]);
	for (int i=1;i<order.size();i++) {
		while (!prev.empty()) {
			if (flights[prev.top()][order[i]]) {
				prev.push(order[i]);
				break;
			}
			else {
				prev.pop();
			}
		}

		if (prev.empty())
			return false;
	}

	return true;
}

int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);

	int z;
	cin >> z;
	for (int q=0;q<z;q++) {
		for (int i=0;i<10;i++) {
			for (int j=0;j<10;j++)
				flights[i][j] = false;
		}
		codes.clear();
		best = "";

		cin >> n >> m;

		string str;
		for (int i=0;i<n;i++) {
			cin >> str;
			codes.push_back(str);
		}

		int src, dest;
		for (int i=0;i<m;i++) {
			cin >> src >> dest;
			flights[src-1][dest-1] = true;
			flights[dest-1][src-1] = true;
		}

		vector<int> order;
		for (int i=0;i<n;i++) {
			order.push_back(i);
		}

		do {
			if (possible(order)) {
				string cur = "";
				for (int i=0;i<order.size();i++) {
					cur += codes[order[i]];
				}

				if (best == "" || cur.size() < best.size() || cur < best)
					best = cur;
			}
		} while(next_permutation(order.begin(), order.end()));

		cout << "Case #" << (q + 1) << ": " << best << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}