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
		int a,b,k;

		cin >> a >> b >> k;

		long long count = 0;
		for (int i=0;i<a;i++) {
			for (int j=0;j<b;j++) {
				if ((i & j) < k)
					count++;
			}
		}
		cout << "Case #" << (q + 1) << ": " << count << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}