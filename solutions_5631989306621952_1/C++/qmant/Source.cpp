#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <iomanip>
#define ll long long
#define itn int
#define eps 1e-10
#define mp make_pair
#define pb push_back
#define inf 1e9 
#define vi vector<itn>
#define vvi vector<vi>
#define vii vector<pair<itn,itn> >
#define vvii vector<vii>
#define itn long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie();
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout);
#endif
	itn n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string q;
		cin >> q;
		string ans = "";
		ans += q[0];
		for (int j = 1; j < q.size(); j++)
		{
			if (q[j] >= ans[0])
			{
				ans = q[j] + ans;
			}
			else
				ans += q[j];
		}
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}


	return 0;
}