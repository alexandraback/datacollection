#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
 
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output11.txt", "w", stdout);

	int nTestCase = 0;
	cin >> nTestCase;
 
	for (int iTestCase = 0; iTestCase < nTestCase; iTestCase++)
	{

		int answer = 0;
		int R, C, W;
		cin >> R>> C >> W;
		
		answer += (R - 1) * (C / W);
		//cout << answer << endl;
		answer += ((C-W) / W);
		//cout << answer << endl;
		answer += W;
		//cout << answer << endl;
		if (C%W != 0){
			answer ++;
		}
	//	cout << answer << endl;

		cout << "Case #" << iTestCase + 1 << ": " << answer << endl;
	}
	return 0;
}