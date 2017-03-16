#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int LL;

const int N = 101;

LL mod = 1000000007;

LL fat (LL x)
{
	LL res = 1;
	for (int i = 1; i <= x; ++i) res = (res * i)%mod;
	return res;
}

bool ok (vector<string> v)
{
	bool used[27] = {0};
	char cchar = -1;
	for (int i = 0; i < v.size(); ++i)
	{
		for (int k = 0; k < v[i].size()-1; ++k)
		{
			int now = v[i][k]-'a';
			if (cchar != now) {
				if (used[now]) return false;
				cchar = now;
				used[now] = 1;
			}
		}
	}
	return true;
}

int main (void)
{
	int T, caso = 1;
	cin >> T;
	while (T--)
	{
		int n; 
		cin >> n;
		vector <string> v(n);

		char ph = 140;
		for (int i = 0; i < n; ++i) cin >> v[i], v[i]+=ph, ph++;

		LL ways = 0;
		sort (v.begin(), v.end());		
		do
		{
			if (ok(v)) ways++;
		} while (next_permutation(v.begin(), v.end()));

		printf("Case #%d: ", caso++);
		printf("%lld\n", ways);
	}
}