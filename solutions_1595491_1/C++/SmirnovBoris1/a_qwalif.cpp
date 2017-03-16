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

typedef long long lint;
#define pb push_back
#define sz(a) (int)((a).size())


void prepare(string s){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen((s + ".in").c_str(), "r", stdin); 
	freopen((s + ".out").c_str(), "w", stdout);
#endif
}

map<char, char> m;
set<char> all;

struct triple{
	int a,b,c;
	triple(int A, int B, int C): a(A), b(B), c(C){}
	int more(int k){
		if (c >= k)
			return 1;
		return 0;
	}
};
vector< vector<triple> >a(40);

bool solve(){
	
	for (int i = 0; i <= 10; ++ i)
	{
		for (int j = i; j <= min(i + 2, 10); ++ j)
		{
			for (int k = j; k <= min(i + 2, 10); ++ k)
				a[i + j + k].push_back(triple(i,j,k));
		}
	}

	int T;
	cin >> T;
	for (int cur_test = 0; cur_test < T; ++ cur_test)
	{
		int n;
		cin >> n;
		int s,p;
		cin >> s >> p;
		int sum = 0;
		int ans = 0;
		for (int i = 0; i < n; ++ i)
		{
			int sum;
			cin >> sum;
		
			if (a[sum].size() == 1)
			{
				ans += a[sum][0].more(p);
			}
			else
			{
				if (a[sum][1].more(p))
				{
					ans ++;
				} 
				else if (s && a[sum][0].more(p))
				{
					++ ans;
					-- s;
				}
			}
		}
		cout << "Case #" << cur_test + 1 << ": " << ans << endl; 
	}

	return false;
}

int main(){

	prepare("problema");
	while (solve());



	return 0;
}