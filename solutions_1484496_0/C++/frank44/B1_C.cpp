#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
using namespace std;

typedef long long Long;
typedef unsigned long long uLong;

const double PI = acos(-1.0);
const double EPS = 1e-10;

#define FOR(i,a,b) for (int i=(int)(a); i<(int)(b); ++i)
#define two(X) (1<<(X))
#define twoL(X) (((Long)(1))<<(X))
#define bit(S,X) (((S)&two(X))!=0)
#define bitL(S,X) (((S)&twoL(X))!=0)

int arr[32];
vector<int> sum[2000005];

string printSubset(int a, int n)
{
	vector<int> set;
	FOR(i,0,n)
		if (bit(a,i))
			set.push_back(arr[i]);

	stringstream ss;
	ss << set[0];
	FOR(i,1,set.size())
		ss << " " << set[i];

	return ss.str();
}

string solve()
{
	int n;
	cin >> n;

	FOR(i,0,n) cin >> arr[i];

	FOR(i,1,two(n))
	{
		int s = 0;
		FOR(j,0,n)
			if (bit(i,j))
				s += arr[j];
		
		FOR(j,0,sum[s].size())
			if ((i & sum[s][j]) == 0)
				return printSubset(i, n) + '\n' + printSubset(sum[s][j], n);

		sum[s].push_back(i);
	}

	return "Impossible\n";
}

int main()
{
	freopen("data.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int T;
	cin >> T;
	for (int x=1; x<=T; x++) 
	{
		FOR(i,0,2000005) sum[i].clear();
		printf("Case #%d:\n%s\n", x, solve().c_str());
	}

	return 0;
}
