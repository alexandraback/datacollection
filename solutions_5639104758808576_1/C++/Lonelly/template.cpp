#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
using namespace std;

void Solve()
{
	int S;
	cin >> S;
	string s;
	cin >> s;
	int result = 0;
	int current = 0;
	for (int i = 0; i <= S; ++i)
	{
		int count = s[i] - '0';
		while (current < i)
		{
			++result;
			++current;
		}
		current += count;
	}
	cout << result;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cout << "Case #" << i + 1 << ": ";
		Solve();
		cout << endl;
	}
	return 0;
}