#include<iostream>

using namespace std;

const int MAXN = 1005;
int a[MAXN];
int n;

bool check(int x)
{
	for(int i = 0; i < x; i++)
	{
		int y = i, time = x - i;
		for(int j = 0; j < n; j++)
			y -= a[j] / time - (a[j] % time == 0);
		if(y >= 0)
			return true;
	}
	return false;
}

int main()
{
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++)
	{
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		int lo = 0, hi = 1001;
		while(hi - lo > 1)
		{
			int mid = (lo + hi) / 2;
			if(check(mid))
				hi = mid;
			else
				lo = mid;
		}
		cout << "Case #" << tt << ": ";
		cout << hi << endl;
	}
	return 0;
}
