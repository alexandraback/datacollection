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
	cin >> t;
	for (int ca = 1; ca <= t; ca++)
	{
		vector <int> lst;
		cin >> c >> d >> v;
		for (int i = 0; i < d; i++)
			cin >> a[i], lst.push_back(a[i]);
		sort(a, a + d);
		int ans = 0;
		ll cur = 1;
		int pos = 0;
		while (cur <= v)
		{
			int sum = 0;
			for (int i = pos; a[i] <= cur && i < d; i++, pos++)
				sum += a[i];
			if(sum != 0) cur += sum*c;
			else
			{
				ans++;
				cur *= c + 1;
			}
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
	freopen("C4.out", "w", stdout);
	init();
	solve();
	//system("pause");
	return 0;
}
