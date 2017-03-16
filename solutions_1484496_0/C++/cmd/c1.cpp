#if 1
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <ctime>
#include <cassert>
#include <sstream>
#include <iostream>
#include <bitset>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int , int> pii;
typedef vector <int> veci;
typedef vector <veci> graph;
const LD eps = 1e-9;
const LD pi = acos(-1.0);
const int inf = 1000 * 1000 * 1000;
const LL inf64 = LL(inf) * inf;

#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define iss istringstream
#define oss ostringstream
#define dbg(x) {cerr << #x << " = " << x << endl;}
#define dbgv(x) {cerr << #x << " ={"; for (int _i = 0; _i < x.size(); _i++) {if (_i) cerr << ", "; cerr << x[_i];} cerr << "}" << endl;}
#define NAME "problem"

const int maxn = 20;
int w[maxn];
int sum[1 << maxn];
void solve(int test)
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> w[i];


	for(int i = 1; i < 1 << n; ++i)
	{
		int bt = 0;
		while(!(i & (1 << bt))) ++bt;
		sum[i] = sum[i ^ (1 << bt)] + w[bt];
	}

	int left = -1, right = -1;
	for(int i = 0; i < 1 << n; ++i)
		for(int j = i; j; j = (j - 1) & i)
		{
			int k = i ^ j;
			if(!k) continue;
			if(sum[j] == sum[k])
			{
				left = j;
				right = k;
				goto out;
			}
			
		}
out:;
	cout << "Case #" << test << ":";
	if(left == -1)
		cout << " Impossible" << endl;
	else
	{
		cout << endl;
		bool first = true;
		for(int i = 0; i < n; ++i)
			if((left & (1 << i)))
			{
				if(!first) cout << " ";
				cout << w[i];
				first = false;

			}

		cout << endl;
		first = true;
		for(int i = 0; i < n; ++i)
			if((right & (1 << i)))
			{
				if(!first) cout << " ";
				cout << w[i];
				first = false;
			}
		cout << endl;
	}
}


int main()
{
	//freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
	//freopen(NAME ".in","r",stdin);freopen(NAME ".out","w",stdout);

	int tt; cin >> tt;
	for(int t = 1; t <= tt; ++t) solve(t);

	return 0;
}
/*************************
*************************/
#endif
