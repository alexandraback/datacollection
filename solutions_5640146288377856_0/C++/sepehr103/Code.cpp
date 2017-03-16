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

//init
inline void init()
{
	cin >> t;
	int r, c, w;
	for (int ca = 1; ca <= t; ca++)
	{
		cout << "Case #" << ca << ": ";
		cin >> r >> c >> w;
		cout << (c / w) * r + w - 1 + (c % w == 0 ? 0 : 1);
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
	freopen("A.in", "r", stdin);
	freopen("A2.out", "w", stdout);
	init();
	solve();
	//system("pause");
	return 0;
}
