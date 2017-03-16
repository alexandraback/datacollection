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
		int n;
		cin >> n;

		vector<vector<int> > mat;
		for (int i=0;i<n;i++) {
			int m;
			cin >> m;
			vector<int> temp(m);
			for (int j=0;j<m;j++) {
				cin >> temp[j];
				temp[j]--;
			}
			mat.push_back(temp);
		}

		bool flag = false;
		for (int i=0;i<n;i++) {
			vector<bool> visited(n, false);
			stack<int> q;
			q.push(i);
			visited[i] = true;
			while (!q.empty()) {
				int top = q.top();
				q.pop();
				for (int j=0;j<mat[top].size();j++) {
					if (visited[mat[top][j]]) {
						flag = true;
						break;
					}
					visited[mat[top][j]] = true;
					q.push(mat[top][j]);
				}

				if (flag) {
					break;
				}
			}

			if (flag) {
				break;
			}
		}

		cout << "Case #" << (q+1) << ": ";
		if (flag) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}