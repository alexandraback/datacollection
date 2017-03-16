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
		string str;
		cin >> str;

		string result = "";
		for (int i=0;i<str.size();i++) {
			if (result + str[i] < str[i] + result) {
				result = str[i] + result;
			}
			else {
				result = result + str[i];
			}
		}

		cout << "Case #" << (q1+1) << ": " << result << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}