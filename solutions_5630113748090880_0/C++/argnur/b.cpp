#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;
int main() {
	int t, test, i, n, m;
	string s;
	cin >> t;
	for (test=1;test<=t;test++) {
		cin >> n;
		map<int, int> count;
		for (i=0;i<(2*n-1)*n;i++) {
			cin >> m;
			count[m]++;
		}
		map<int, int>::iterator it;
		vector<int> result;
		for (it=count.begin();it!=count.end();it++)
			if (it->second % 2 == 1)
				result.push_back(it->first);
		sort(result.begin(), result.end());
		cout << "Case #" << test << ": ";
		for (i=0;i<n;i++)
			cout << result[i] << " ";
		cout << endl;
	}
	return 0;
}