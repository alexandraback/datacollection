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
	freopen("C-small-attempt0.in" ,  "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

	int t;
	cin >> t;
	for(int test = 1; test <= t; test++)
	{
		int n;
		cin >> n;

		vector<int> v(n);
		for(int i = 0; i < n; i++)
			cin >> v[i];

		map<int, vector<int> > mp;
		for(int mask = 0; mask < (1<<n); mask++)
		{
			int sum = 0;
			for(int i = 0; i < n; i++)
				if(mask & (1<<i))
					sum += v[i];
			mp[sum].push_back(mask);
		}

		cout << "Case #" << test << ":" << endl;
		bool done = false;
		for(map<int, vector<int> >::iterator it = mp.begin(); it != mp.end(); it++)
		{
			if(it->second.size() > 1)
			{
				done = true;
				for(int j = 0; j < n; j++)
					if(it->second[0] & (1<<j))
						cout << v[j] << " ";
				cout << endl;
				for(int j = 0; j < n; j++)
					if(it->second[1] & (1<<j))
						cout << v[j] << " ";
				cout << endl;
				break;
			}
		}

		
		if(!done) cout << "Impossible" << endl;
	}



	return 0;
}