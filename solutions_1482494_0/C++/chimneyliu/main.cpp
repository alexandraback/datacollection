#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
typedef long long int64;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (b) - 1; i >= a; --i)
#define SIZE(a) ((a).size())

template<typename T> T gcd(T a, T b) { if (!b) return a; else return gcd(b, a%b);}
template<typename T> void ext_euclid(T a, T b, T& x, T& y) { if (!b) {x=1; y=0;} else {int xx, yy; ext_euclid(b, a%b, xx, yy); x=yy; y=-yy*(a/b)+xx;}}


vector<pair<int,int> > p;
string target = "";
string status = "";
int res = 2147483647;

void solve(int stars, int t)
{
	int n = target.size();

	if (status == target)
	{
		if (t < res)
			res = t;
		return;
	}

	for (int i=0; i<n; i++)
	{
		if (status[i] == '0')
		{
			if (stars >= p[i].second)
			{
				status[i] = '2';
				solve(stars+2, t+1);
				status[i] = '0';

				break;
			}
		}
	}

	int ind = -1;
	int biggest = -1;
	for (int i=0; i<n; i++)
	{
		if (status[i] == '0')
		{
			if (stars < p[i].second && stars >= p[i].first)
			{
				if (p[i].second > biggest)
				{
					biggest = p[i].second;
					ind = i;
				}
			}
		}
	}
	if (ind != -1)
	{
		status[ind] = '1';
		solve(stars+1, t+1);
		status[ind] = '0';
	}

	for (int i=0; i<n; i++)
	{
		if (status[i] == '1')
		{
			if (stars >= p[i].second)
			{
				status[i] = '2';
				solve(stars+1, t+1);
				status[i] = '1';
				break;
			}

		}
	}
}

int main()
{
	const char* inFile = "in.txt";
	const char* outFile = "out.txt";
	freopen(inFile, "r", stdin);
	freopen(outFile, "w", stdout);

	int T;
	cin >> T;

	for (int t=1; t<=T; t++)
	{
		int N;
		cin >> N;
		p.clear();
		for (int i=0; i<N; i++)
		{
			int a, b;
			cin >> a >> b;
			p.push_back(make_pair(a, b));
		}

		sort(p.begin(), p.end());
		target = "";
		status = "";
		res = 2147483647;
		for (int i=0; i<N; i++)
		{
			target += '2';
			status += '0';
		}

		solve(0, 0);

		if (res != 2147483647)
			printf("Case #%d: %d\n", t, res);
		else
			printf("Case #%d: Too Bad\n", t);
		
	}
	
	return 0;
}