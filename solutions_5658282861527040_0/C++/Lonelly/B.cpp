#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;

void solve(int index)
{
	int a, b, k;
	cout << "Case #" << index + 1 << ": ";
	cin >> a >> b >> k;
	int result = 0;
	for (int i = 0; i < a; ++i)
	for (int j = 0; j < b; ++j)
	if ((i & j) < k)
	{
		++result;
	}
	cout << result;
	cout << endl;
}

int main(int argc, char **argv)
{
	if (argc == 2 && string(argv[1]) == "-d")
	{
		cout << "Sleep for 15 seconds" << endl;
		Sleep(15 * 1000);
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		solve(i);
	}
	return 0;
}