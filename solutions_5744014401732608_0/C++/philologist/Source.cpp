#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
#include<iterator>
#include<set>
#include<stack>
#include<queue>
#include<fstream>
#include<iomanip>
#include<list>
#include <sstream>
#include<cmath>
#include<math.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define repd(i,m,n) for(int i=(m); i > (n); i--)
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define endl '\n'
//#define x first
//#define y second
//#define b first
//#define e second
#define row first
#define col second
#define num first
#define lit second
using namespace std;
const ll MAX = (ll)1000*1000*1000;
void print(int c,vector<vector<int>>& a)
{
	cout << "Case #"+to_string(c)+": POSSIBLE" << endl;
	rep(i,0,a.size())
	{
		rep(j,0,a.size())
			cout << a[i][j];
		cout << endl;
	}
}
void printimp(int c)
{
	cout << "Case #"+to_string(c)+": IMPOSSIBLE" << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	freopen("input.in", "rt", stdin);
	freopen("output.out", "wt", stdout);
	int t,b;
	unsigned ll m;
	cin >> t;
	rep(i,0,t)
	{
		cin >> b >> m;
		vector<vector<int>> res(b,vector<int>(b,0));
		unsigned ll temp = 1;
		rep(j,1,b)
			rep(k,j+1,b)
				res[j][k] = 1;
		bool p = 1;
		rep(j,0,b-2)
		{
			p = 0;
			temp <<=1;
			if (temp >= m) 
			{
				if (j == b- 3)
					p = 1;
				break;
			}
		}
		if (temp == m && p)
		{
			rep(j,1,b)
				res[0][j] = 1;
			print(i+1,res);
			continue;
		}

		if (temp < m)
		{
			printimp(i+1);
			continue;
		}




		rep(j,1,b-1)
		{
			if ( m & (1 << (b - j - 2)) )
				res[0][j] = 1;
		}
		print(i+1,res);
	}
	return 0;
}

