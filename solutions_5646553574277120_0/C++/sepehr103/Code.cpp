//c++11
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cassert>
#include<stack>
#include<cstring>
#include<vector>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<complex>
#include<unordered_map>
#include<unordered_set>

#define mp make_pair
#define X first
#define Y second

using namespace std;

//def
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const ll MOD = 1e9 + 7;
const double eps = 1e-5;
const int maxN = 5e2 + 10;
const int inf = 1e9;
int t;
int c, v, d;

//init
inline void init()
{
	int	a[100];
	bool have[1000];
	bool pos[1000];
	cin >> t;
	for (int ca = 1; ca <= t; ca++)
	{
		memset(have, 0, sizeof have);
		memset(pos, 0, sizeof pos);
		pos[0] = 1;
		vector <int> lst;
		cin >> c >> d >> v;
		for (int i = 0; i < d; i++)
			cin >> a[i], lst.push_back(a[i]);
		//for (int i = 0; i < 5; i++)
		//	lst.push_back(1 << i);
		for (int i = 0; i < lst.size(); i++)
		{
			int add = a[i];
			for (int k = v; k - add >= 0; k--)
				if (pos[k - add]) pos[k] = 1;
		}
		int ans = 0;
		while (true)
		{
			int add = -1;
			for (int i = 1; i <= v; i++)
			{
				if (!pos[i])
				{
					add = i;
					ans++;
					break;
				}
			}
			if (add == -1) break;
			for (int k = v; k - add >= 0; k--)
				if (pos[k - add]) pos[k] = 1;
		}
		cout << "Case #" << ca << ": ";
		cout << ans;
		cout << endl;
	}
}


//Solve
inline void solve()
{

}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
	freopen("C.in", "r", stdin);
	freopen("C2.out", "w", stdout);
	init();
	solve();
	//system("pause");
	return 0;
}
