#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string.h>
#include <cassert>
#include <unordered_set>
#include <unordered_map>

#define mp make_pair
#define pb push_back
#define problem "test"
typedef __int128 ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;
const int z = 111111;
const double eps = 1e-9;
const int inf = int(1e9);
const ll llinf = ll(1e18);
using namespace std;

const string mark = "ZWUFXGHOS";
const string numbers[9] = {"ZERO", "TWO", "FOUR", "FIVE", "SIX", "EIGHT", "THREE", "ONE", "SEVEN"};
const string toans = "024568317";
int cnt[z];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen(problem".in", "r", stdin);
	freopen(problem".out", "w", stdout);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++)
	{
	    string s, ans;
	    cin >> s;
	    memset(cnt, 0, sizeof(cnt));
	    for (ui i = 0; i < s.size(); i++)
	    	cnt[int(s[i])]++;
		for (int i = 0; i < 9; i++)
		{
		    int k = cnt[int(mark[i])];
//		    cout << "k = " << k << "\tmark[i] = " << mark[i] << "\n";
//			return 0;
			for (int j = 0; j < k; j++)
			{
				for (ui p = 0; p < numbers[i].size(); p++)
					cnt[int(numbers[i][p])]--;
				ans += toans[i];
			}
		}
		for (int i = 0; i < cnt[int('E')]; i++)
			ans += '9';
		sort(ans.begin(), ans.end());
		cout << "Case #" << test << ": " << ans << "\n";
	}
	
	return 0;
}