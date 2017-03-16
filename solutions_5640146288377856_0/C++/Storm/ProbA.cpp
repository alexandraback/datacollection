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
	for (int q1=0;q1<z;q1++) {
	    int r,c,w;
		cin >> r >> c >> w;
		int score = 0;
		int temp = c;
		bool flag = true;
		while (temp >= w) {
			temp -= w;
			if (temp < w && temp != 0)
				flag = false;
			score++;
		}
		score *= r;
		score += w - 1;
		if (!flag) score++;

		cout << "Case #" << (q1+1) << ": " << score << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}