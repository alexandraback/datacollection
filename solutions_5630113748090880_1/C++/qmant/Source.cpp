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
	itn qw;
	cin >> qw;
	for (int i = 0; i < qw; i++)
	{
		vector<int> ans;
		int n;
		cin >> n;
		int a[50000];
		for (int jw = 0; jw < 50000; jw++)
			a[jw] = 0;
		for (itn jw = 0; jw < 2 * n - 1; jw++)
			for (itn j = 0; j < n; j++)
			{
				int q;
				cin >> q;
				a[q]++;
			}
		
		for (int jw = 0; jw < 50000; jw++)
			if (a[jw] % 2 == 1)
				ans.push_back(jw);



		cout << "Case #" << i + 1 << ": ";
		for (int jw = 0; jw < ans.size(); jw++)
			cout << ans[jw] << ' ';
		cout << endl;
	}


	return 0;
}