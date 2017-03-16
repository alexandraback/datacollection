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
	
	int t, n;
	string s;
	cin >> t;

	llg ans = 0, sum = 0;
	fori(z, t)
	{
		ans = sum = 0;
		cin >> n >> s;
		fori(i, s.length())
		{
			if (sum < i)
			{
				ans += i - sum;
				sum++;
			}
			sum += s[i] - '0';
		}
		cout << "Case #" << z + 1 << ": " << ans << endl;
	}

	//------------------------------------------------------------
	return 0;
}