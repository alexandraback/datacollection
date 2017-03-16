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

int n;
int data[2500][2500];
int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);

	int z;
	cin >> z;
	
	for (int q=0;q<z;q++) {
		vector<int> count(2501, 0);
		cin >> n;
		for (int i=0;i<2*n-1;i++) {
			for (int j=0;j<n;j++) {
				cin >> data[i][j];
				count[data[i][j]-1]++;
			}
		}

		vector<int> result;
		for (int i=0;i<count.size();i++) {
			if (count[i] % 2 != 0) {
				result.push_back(i+1);
			}
		}

		sort(result.begin(), result.end());
		cout << "Case #" << (q + 1) << ": ";
		for (int i=0;i<result.size();i++) {
			cout << result[i] << " ";
		}
		cout << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}