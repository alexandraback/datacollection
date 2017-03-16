#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

/*int n;
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
}*/
//////////////////////////////////////////

int n;
vector<int> vals;
int r;
int max_e;

long long rec(int start_e, int end_e, int start, int end)
{
	if (start == end) return 0;
	vector<int>::iterator pos = max_element(vals.begin() + start, vals.begin() + end);
	int from_s = min(max_e, start_e + (pos - vals.begin() - start) * r);
	int from_e = max(0, end_e - (end - (pos - vals.begin()) - 1) * r);
	int can_use = max(0, from_s - from_e);
	return rec(start_e, max(from_s - r, 0), start, pos - vals.begin()) +
		   rec(min(max_e, from_s-can_use+r), end_e, pos - vals.begin() + 1, end) +
		   ((long long) *pos) * can_use;
}

int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);
	
	int z;
	cin >> z;
	for (int q=0;q<z;q++) {
		vals.clear();
		int e;
		cin >> e >> r >> n;
		max_e = e;
		int temp;
		vals.resize(n);
		for (int i=0;i<n;i++) {
			cin >> vals[i];
		}
		
		cout << "Case #" << (q+1) << ": ";
		cout << rec(e, 0, 0, n) << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}