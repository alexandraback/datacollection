#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

void solve(int index)
{
	int N;
	cin >> N;
	vector<double> Ken(N), Naomi(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> Naomi[i];
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> Ken[i];
	}
	sort(Naomi.begin(), Naomi.end());
	sort(Ken.begin(), Ken.end());
	int result1 = N;
	int result2 = 0;
	vector<double> Ken2(Ken);
	for (int i = 0; i < N; ++i)
	{
		vector<double>::iterator it = upper_bound(Ken2.begin(), Ken2.end(), Naomi[i]);
		if (it == Ken2.end())
		{
			result2 = N - i;
			break;
		}
		Ken2.erase(it);
	}
	for (int i = 0; i < N; ++i)
	{
		vector<double>::iterator it = upper_bound(Naomi.begin(), Naomi.end(), Ken[i]);
		if (it == Naomi.end())
		{
			result1 = i;
			break;
		}
		Naomi.erase(it);
	}
	cout << "Case #" << index + 1 << ": " << result1 << " " << result2;
	cout << endl;
}

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		solve(i);
	}
	return 0;
}