#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <cstring>

#define all(x) (x).begin(),(x).end()

using namespace std;

const int nmax = 1e3;
int n;

vector <vector <long long> > version_history;

struct location
{
	int version;
	int l,r;
	location(int version = 0, int l = 0, int r = 0): version(version), l(l), r(r)
	{
	}
};

bool operator == (const location& a, const location& b)
{
	vector <long long> va;
	for (int i = a.l; i <= a.r; i ++)
		va.push_back(version_history[a.version][i]);
	sort(va.begin(), va.end());
	vector <long long> vb;
	for (int i = b.l; i <= b.r; i ++)
		vb.push_back(version_history[b.version][i]);
	sort(vb.begin(), vb.end());
	return va == vb;
}

set<long long> print(location a)
{
	long long sum = 0;
	set <long long> va;
	for (int i = a.l; i <= a.r; i ++)
		va.insert(version_history[a.version][i]);
	return va;
}

void solve(int cn)
{
	map <long long, location> m;
	printf("Case #%d:\n", cn);
	cin >> n;
	vector <long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	while (1)
	{
		random_shuffle(a.begin(), a.end());
		version_history.push_back(a);
		int vn = version_history.size() - 1;
		for (int i = 0; i < n; i ++)
		{
			long long s = 0;
			for (int j = i; j < n; j ++)
			{
				s += a[j];
				if (m.find(s) == m.end())
					m[s] = location(vn, i, j);
				else
				{
					if (!(location(vn, i, j) == m[s]))
					{
						long long S1 = 0, S2 = 0;
						set<long long> s1 = print(location(vn, i, j));
						set<long long> s2 = print(m[s]);
						for (long long i: s1)
							if (s2.find(i) == s2.end())
							{
								cout << i << " ";
								S1 += i;
							}
						cout << endl;
						for (long long i: s2)
							if (s1.find(i) == s1.end())
							{
								cout << i << " ";
								S2 += i;
							}
						cout << endl;
						cerr << "Test " << cn << " " << "passed" << endl << S1 << endl << S2 << endl;
						return;
					}
				}
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i ++)
		solve(i + 1);
	return 0;
};
