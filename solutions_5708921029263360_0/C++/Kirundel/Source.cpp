#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cmath>
#include <ctime>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <sstream>
using namespace std;

int main()
{
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		int j, p, s;
		cin >> j >> p >> s >> k;
		vector<vector<int>>jp(j);
		vector<vector<int>>js(j);
		vector<vector<int>>ps(p);
		vector<vector<vector<int>>>jps(j);
		for (int i1 = 0; i1 < j; i1++)
		{
			jp[i1].resize(p);
			js[i1].resize(s);
			jps[i1].resize(p);
			for (int i2 = 0; i2 < p; i2++)
			{
				ps[i2].resize(s);
				jps[i1][i2].resize(s);
			}
		}
		int days = 0;
		string f = "";
		for (int i1 = 0; i1 < k; i1++)
		{
			for (int ij = 0; ij < j; ij++)
			{
				for (int ip = 0; ip < p; ip++)
				{
					for (int is = 0; is < s; is++)
					{
						if (jps[ij][ip][is] == 0 && jp[ij][ip] <= i1&&js[ij][is] <= i1&&ps[ip][is] <= i1)
						{
							jps[ij][ip][is]++;
							jp[ij][ip]++;
							js[ij][is]++;
							ps[ip][is]++;
							f += to_string(ij+1) + " " + to_string(ip+1) + " " + to_string(is+1) + "\n";
							days++;
						}
					}
				}
			}
		}
		cout << "Case #"<<(i+1)<<": "<<days<<endl ;
		cout << f;
	}
	return 0;
}