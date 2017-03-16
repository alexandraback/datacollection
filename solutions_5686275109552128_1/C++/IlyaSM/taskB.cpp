#include <iostream>
#include <stdio.h>
#include <fstream>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <string>
#include <string.h>
#include <stack>
#include <ctime>
#include <sstream>
#include <typeinfo>
#include <functional>
#include <unordered_map>
using namespace std;

struct file_opener
{
	FILE *in, *out;
	file_opener(string file_name)
	{
		in = freopen((file_name + ".in").c_str(), "r", stdin);
		out = freopen((file_name + ".out").c_str(), "w", stdout);
	}
	file_opener(string input_file, string output_file)
	{
		in = freopen((input_file + ".txt").c_str(), "r", stdin);
		out = freopen((output_file + ".txt").c_str(), "w", stdout);
	}
	~file_opener()
	{
		fflush(out);
		fclose(in);
		fclose(out);
	}
};
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forin(n) for (int i = 0; i < (int)n; i++)
#define foro(i, x, n) for(int i = (int)x; i <= (int)n; i++)
#define forit(i, n) for (auto i = (n).begin(); i != (n).end(); i++)
#define fori(i, n) for (int i = 0; i < (int)n; i++)
#define for_col(i, n) for (auto i : n)
#define m_p(x, y) make_pair(x, y)
typedef long double ldb;
typedef long long llg;

vector<int> v;

int main()
{
#ifdef LOCAL
	file_opener File_closer("input", "output");
#else
	file_opener File_closer("input", "output");
#endif
	cout.setf(cout.fixed);
	cout.precision(10);
	//ios_base::sync_with_stdio(false);
	//------------------------------------------------------------
	
	int t, n, p, f, ans = 0, tans;
	
	cin >> t;
	fori(z, t)
	{
		v.clear();
		cin >> n;
		fori(i, n)
		{
			cin >> f;
			v.push_back(f);
		}
		sort(v.begin(), v.end());
		f = v.back();
		ans = INT_MAX;
		for (int i = 1; i <= f; i++)
		{
			tans = 0;
			fori(j, n)
			{
				if (v[j] > i)
				{
					tans += (v[j] - i) / i + ((v[j] - i) % i == 0 ? 0 : 1);
				}
			}
			ans = min(ans, tans + i);
		}
		cout << "Case #" << z + 1 << ": " << ans << endl;
	}

	//------------------------------------------------------------
	return 0;
}