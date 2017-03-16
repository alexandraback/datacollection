#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

int n;
vector<int> vals;
int r;
int max_e;

long long dp[15][6];
long long rec(int pos, int e)
{
	if (pos == n)
		return 0;

	long long res = dp[pos][e];
	if (res != -1)
		return res;

	for (int i=0;i<=e;i++) {
		res = max(res, vals[pos] * i + rec(pos + 1, min(max_e, e - i + r)));
	}

	dp[pos][e] = res;
	return res;
}

int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);
	
	int z;
	cin >> z;
	for (int q=0;q<z;q++) {
		for (int i=0;i<15;i++) {
			for (int j=0;j<6;j++)
				dp[i][j] = -1;
		}
		vals.clear();
		int e;
		cin >> e >> r >> n;
		max_e = e;
		int temp;
		for (int i=0;i<n;i++) {
			cin >> temp;
			vals.push_back(temp);
		}
		
		cout << "Case #" << (q+1) << ": ";
		cout << rec(0, e) << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}