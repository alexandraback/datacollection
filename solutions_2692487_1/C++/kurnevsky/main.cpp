#include <iostream>
#include <algorithm>

using namespace std;

int a, n;
int motes[100];
int curMin;
int curAdd;

void solve()
{
	cin >> a >> n;
	for (int i = 0; i < n; i++)
		cin >> motes[i];
	if (a == 1)
	{
		cout << n << endl;
		return;
	}
	sort(motes, motes + n);
	curMin = 100000;
	curAdd = 0;
	for (int i = 0; i < n; i++)
	{
		if (motes[i] < a)
		{
			a += motes[i];
		}
		else
		{
			if (curAdd + n - i < curMin)
				curMin = curAdd + n - i;
			while (motes[i] >= a)
			{
				a = a * 2 - 1;
				curAdd++;
			}
			a += motes[i];
		}
	}
	if (curAdd < curMin)
		curMin = curAdd;
	cout << curMin << endl;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cout << "Case #" << i + 1 << ": ";
		solve();
	}
	return 0;
}
