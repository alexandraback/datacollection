#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef pair<int,int> ii;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int N;
int a[3];
int b[3];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("GCJ20161B-2.out", "w", stdout);
	int t; cin >> t;
	int T = 0;
	while(t--)
	{
		string c, x;
		cin >> c >> x;	
		int n = c.length();
		N = 1;
		for(int i = 0; i < 2*n; i++)
		{
			N *= 10;
		}
		int maxdiff = 1000;
		int mina = 1000;
		int minb = 1000;
		for(int i = 0; i < N; i++)
		{
			int tmp = i;
			for(int j = 0; j < n; j++)
			{
				a[j] = tmp % 10;
				tmp /= 10;
			}
			for(int j = 0; j < n; j++)
			{
				b[j] = tmp % 10;
				tmp /= 10;
			}
			int tmpa, tmpb;
			tmpa = 0; tmpb = 0;
			bool possible = true;
			int cnt;
			if(n == 1) cnt = 1;
			else if(n == 2) cnt = 10;
			else cnt = 100;
			for(int j = 0; j < n; j++)
			{
				if(c[j] == '?' || c[j] - '0' == a[j])
				{
					tmpa += a[j]*cnt;
				}
				else
				{
					possible = false;
					break;
				}
				cnt /= 10;
			}
			if(!possible) continue;
			if(n == 1) cnt = 1;
			else if(n == 2) cnt = 10;
			else cnt = 100;
			for(int j = 0; j < n; j++)
			{
				if(x[j] == '?' || x[j] - '0' == b[j])
				{
					tmpb += b[j]*cnt;
				}
				else
				{
					possible = false;
					break;
				}
				cnt /= 10;
			}
			if(!possible) continue;
			/*
			if(a[0] == 0)
			{
				for(int i = 0; i < n; i++) cout << a[i];
				cout << ' ';
				for(int i = 0; i < n; i++) cout << b[i];
				cout << '\n';
				cout << tmpa << ' ' << tmpb << endl;
			}
			*/
			int diff = abs(tmpa - tmpb);
			if(maxdiff > diff)
			{
				maxdiff = diff;
				mina = tmpa;
				minb = tmpb;
			}
			else if(maxdiff == diff)
			{
				if(tmpa < mina)
				{
					mina = tmpa;
					minb = tmpb;
				}
				else if(tmpa == mina)
				{
					if(tmpb < minb)
					{
						minb = tmpb;
					}
				}
			}
		}
		T++;
		cout << "Case #" << T << ": ";
		//cout << mina << ' ' << minb << endl;
		string X, y;
		for(int i = 0; i < n; i++)
		{
			X.append(" ");
			y.append(" ");
		}
		for(int i = n - 1; i >= 0; i--)
		{
			X[i] = mina%10+'0';
			y[i] = minb%10+'0';
			mina /= 10;
			minb /= 10;
		}
		cout << X << ' ' << y;
		cout << '\n';
	}
	return 0;
}
