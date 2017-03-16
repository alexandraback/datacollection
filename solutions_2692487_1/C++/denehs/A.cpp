#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>

using namespace std;

#define uint64 unsigned long long

int main () {
	int testcases;

	cin >> testcases;

	for (int testcase=1; testcase<=testcases; testcase++) {
		cout << "Case #" << testcase << ": ";
	
		uint64 A;
		uint64 data[110];
		int n;

		cin >> A >> n;
		for (int i=0; i<n; i++)
			cin >> data[i];
		sort (data, data+n);

		int count = 0;
		int ans = -1;

		for (int i=0; i<n; i++) {
			if (ans!=-1 && count > ans)
				break;
			if (A > data[i]) {
				A += data[i];
			}
			else {
				// remove all
				int tmp = count + n - i;
				if (ans<0 || ans > tmp)
					ans = tmp;
				if (A==1)
					break;
				while (A<=data[i]) {
					A += A-1;
					count++;
				}
				A += data[i];
			}
			if (i==n-1 && (ans==-1 || count<ans))
				ans = count;
		}
		cout << ans;
		cout << endl;
	}

	return 0;
}
