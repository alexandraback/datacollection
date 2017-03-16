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
	int k, l, s;
	int cnt[30];
	string s1, s2;
	for (int ca = 1; ca <= t; ca++)
	{
		cout << "Case #" << ca << ": ";
		cin >> k >> l >> s;
		cin >> s1 >> s2;
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < k; i++)
		{
			cnt[s1[i] - 'A']++;
		}
		int sz = l - 1;
		while (sz > 0)
		{
			bool pos = true;
			for (int i = 0; i < sz; i++)
			{
				if (s2[i] != s2[s2.size() - sz + i])
				{
					pos = false;
					break;
				}
			}
			if (pos) break;
			else sz--;
		}
		//cout << sz<<" ";// SIZE IS HERE
		int MN;
		if (s < l) MN = 0;
		else MN = 1;
		MN += (s - l) / (l - sz);
		//cout << MN;
		long double omid = s - l + 1;
		bool pos = true;
		for (int i = 0; i < s2.size(); i++)
		{
			int tmp = (s2[i] - 'A');
			omid *= (ld)cnt[tmp] / (ld)k;
			if (cnt[tmp] == 0) pos = false;
		}
		omid *= -1;
		omid += (ld)MN;
		if(pos) cout << fixed << setprecision(10) << omid;
		else cout << "0.0";
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
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	init();
	solve();
	//system("pause");
	return 0;
}
