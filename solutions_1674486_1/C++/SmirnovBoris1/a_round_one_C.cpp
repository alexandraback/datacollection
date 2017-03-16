#pragma comment (linker, "/STACK:64000000")
#include <memory.h>
#include <cstdio> 
#include <sstream> 
#include <iostream> 
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstring>
#include <list>
#include <cmath>

using namespace std;

//485271451

typedef long long lint;
typedef pair<int,int> pii;
#define pb push_back
#define sz(a) (int)((a).size())


void prepare(string s){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

bool was[1041];

bool dfs(int x, vector< vector<int> > &a)
{
	if (was[x])
		return true;
	was[x] = true;
	bool ans = false;
	for (int i = 0; i < sz(a[x]); ++ i)
		ans |= dfs(a[x][i], a);
	return ans;
}

bool solve(){

	int T;
	cin >> T;
	for (int t = 0; t < T; ++ t)
	{
		int n;
		cin >> n;
		vector< vector<int> > a(n);
		for (int i = 0; i < n; ++ i)
		{
			int m;
			cin >> m;
			for (int j = 0; j < m; ++ j)
			{
				int k;
				cin >> k;
				a[i].push_back(k - 1);
			}
		}

		bool ans = false;
		for (int i = 0; i < n; ++ i)
		{
			memset(was, 0, sizeof(was));
			ans |= dfs(i, a);
		}

		cout << "Case #" << t + 1 << ": ";
		if (ans)
			cout << "Yes";
		else
			cout << "No";
		cout << endl;
		//cerr << t << endl;
	}


	return false;
}

int main(){

	prepare("");
	while (solve());



	return 0;
}