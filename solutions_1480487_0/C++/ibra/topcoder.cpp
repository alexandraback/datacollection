#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<sstream>
#include<ctime>
#include<cmath>
#include<set>
#include<queue>
#include<map>
#include<cstdio>
#include<map>
using namespace std;
typedef unsigned long long u64;
typedef long long i64;
typedef unsigned long long u32;
typedef long long i32;
#pragma comment(linker, "/STACK:16777216");
const double EPS = 1e-9;
const double PI = 3.1415926535897932384626433832795;
i64 i64INF = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;
i32 i32INF = 1000 * 1000 * 1000;

int main()
{
	freopen("A-small-attempt3.in",  "r", stdin);
	freopen("A-small-attempt3.out", "w", stdout);

	int t;
	cin >> t;
	for(int test = 1; test <= t; test++)
	{
		int n;
		cin >> n;

		vector<double> v(n);
		for(int i = 0; i < n; i++)
			cin >> v[i];

		double x = 0.0;
		for(int i = 0; i < n; i++)
			x += v[i];

		vector<double> res;
		for(int i = 0; i < n; i++)
		{
			double low = 0.0;
			double high = 1.0;
			int ITER = 50;
			while(ITER--)
			{
				double c = (low+high) / 2.0;

				double na = v[i] + x*c;

				double s = 0.0;
				for(int j = 0; j < n; j++)
					if(i != j)
						s += max(0.0, na - v[j]);

				s /= x;

				if(s > (1.0-c))
					high = c;
				else
					low = c;
			}
			res.push_back(low);
		}

		cout << "Case #" << test << ":";
		for(int i = 0; i < res.size(); i++)
			printf(" %0.12lf", 100.0*res[i]);
		cout << endl;
	}



	return 0;
}