#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int qsize = 2000001;
int q[qsize];

void show(int k)
{
	if (!k) return;
	if (!q[k]) return;
	cout << q[k] << ' ';
	show(k-q[k]);
}

void solve()
{
	int n;
	vector<int> s;

	cin >> n;
	for (int i=0; i<n; ++i)
	{
		int t;
		cin >> t;
		s.push_back(t);
	}
	memset(q, 0, sizeof(q));
	q[0] = -1;

	for (int i=0; i<n; ++i)
		for (int j=qsize-1; j>=0; --j)
			if (j-s[i] >= 0 && q[j-s[i]])
			{
				if (q[j])
				{
					show(j);
					cout << endl;
					show(j-s[i]);
					cout << s[i] << endl;
					return;
				}
				q[j] = s[i];
			}
	cout << "Impossible" << endl;
}

int main()
{
	int t;
	cin >> t;
	for (int i=1; i<=t; ++i)
	{
		cout << "Case #" << i << ": " << endl;
		solve();
	}
	return 0;
}
