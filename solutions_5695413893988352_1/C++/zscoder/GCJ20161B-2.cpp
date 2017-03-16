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


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-large.in", "r", stdin);
	freopen("GCJ2016B-final.out", "w", stdout);
	int t; cin >> t;
	int T = 0;
	while(t--)
	{
		string c, x;
		cin >> c >> x;	
		int n = c.length();
		/*
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
		*/
		ll a, b;
		ll maxdiff = ll(6e18);
		//If a < b, iterate through first position to become smaller than the other
		int A[20];
		int B[20];
		for(int pos = 0; pos <= n; pos++)
		{
			//cout << pos << endl;
			memset(A, 0, sizeof(A));
			memset(B, 0, sizeof(B));
			bool possible = true;
			for(int i = 0; i < pos; i++)
			{
				if(c[i] == '?' && x[i] == '?')
				{
					A[i] = 0;
					B[i] = 0;
				}
				else if(c[i] == x[i])
				{
					A[i] = c[i] - '0';
					B[i] = x[i] - '0';
				}
				else if(c[i] == '?')
				{
					A[i] = x[i] - '0';
					B[i] = x[i] - '0';
				}
				else if(x[i] == '?')
				{
					A[i] = c[i] - '0';
					B[i] = A[i];
				}
				else
				{
					possible = false;
				}
			}
			if(!possible) continue;
			if(pos < n)
			{
				if(c[pos] == '?' && x[pos] == '?')
				{
					A[pos] = 0;
					B[pos] = 1;
				}
				else if(c[pos] - '0' < x[pos] - '0')
				{
					A[pos] = c[pos] - '0';
					B[pos] = x[pos] - '0';
				}
				else if(c[pos] == '?' && x[pos] - '0' > 0)
				{
					A[pos] = x[pos] - '0' - 1;
					B[pos] = x[pos] - '0';
				}
				else if(x[pos] == '?' && x[pos] - '0' < 9)
				{
					A[pos] = c[pos] - '0';
					B[pos] = c[pos] - '0' + 1;
				}
				else
				{
					possible = false;
				}
			}
			if(!possible) continue;
			for(int i = pos + 1; i < n; i++)
			{
				if(c[i] == '?') A[i] = 9;
				else A[i] = c[i] - '0';
				if(x[i] == '?') B[i] = 0;
				else B[i] = x[i] - '0';
			}
			if(possible)
			{
				ll tmpa = 0; ll tmpb = 0; ll cnt = 1;
				for(int i = n - 1; i >= 0; i--)
				{
					tmpa += cnt*A[i];
					tmpb += cnt*B[i];
					cnt *= 10;
				}
				ll diff = max(tmpa - tmpb, tmpb - tmpa);
				if(maxdiff > diff)
				{
					maxdiff = diff;
					a = tmpa;
					b = tmpb;
				}
				else if(maxdiff == diff)
				{
					if(tmpa < a)
					{
						a = tmpa;
						b = tmpb;
					}
					else if(tmpa == a)
					{
						if(tmpb < b)
						{
							b = tmpb;
						}
					}
				}
				//cout << tmpa << ' '<< tmpb << endl;
			}
		}
		for(int pos = 0; pos <= n; pos++)
		{
			memset(A, 0, sizeof(A));
			memset(B, 0, sizeof(B));
			bool possible = true;
			for(int i = 0; i < pos; i++)
			{
				if(c[i] == '?' && x[i] == '?')
				{
					A[i] = 0;
					B[i] = 0;
				}
				else if(c[i] == x[i])
				{
					A[i] = c[i] - '0';
					B[i]  = x[i] - '0';
				}
				else if(c[i] == '?')
				{
					A[i] = x[i] - '0';
					B[i] = x[i] - '0';
				}
				else if(x[i] == '?')
				{
					A[i] = c[i] - '0';
					B[i] = A[i];
				}
				else
				{
					possible = false;
				}
			}
			if(!possible) continue;
			if(pos < n)
			{
				if(c[pos] == '?' && x[pos] == '?')
				{
					A[pos] = 1;
					B[pos] = 0;
				}
				else if(c[pos] - '0' > x[pos] - '0')
				{
					A[pos] = c[pos] - '0';
					B[pos] = x[pos] - '0';
				}
				else if(c[pos] == '?' && x[pos] - '0' < 9)
				{
					A[pos] = x[pos] - '0' + 1;
					B[pos] = x[pos] - '0';
				}
				else if(x[pos] == '?' && c[pos] - '0' > 0)
				{
					A[pos] = c[pos] - '0';
					B[pos] = c[pos] - '0' - 1;
				}
				else
				{
					possible = false;
				}
			}
			if(!possible) continue;
			for(int i = pos + 1; i < n; i++)
			{
				if(c[i] == '?') A[i] = 0;
				else A[i] = c[i] - '0';
				if(x[i] == '?') B[i] = 9;
				else B[i] = x[i] - '0';
			}
			if(possible)
			{
				ll tmpa = 0; ll tmpb = 0; ll cnt = 1;
				for(int i = n - 1; i >= 0; i--)
				{
					tmpa += cnt*A[i];
					tmpb += cnt*B[i];
					cnt *= 10;
				}
				ll diff = max(tmpa - tmpb, tmpb - tmpa);
				if(maxdiff > diff)
				{
					maxdiff = diff;
					a = tmpa;
					b = tmpb;
				}
				else if(maxdiff == diff)
				{
					if(tmpa < a)
					{
						a = tmpa;
						b = tmpb;
					}
					else if(tmpa == a)
					{
						if(tmpb < b)
						{
							b = tmpb;
						}
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
			X[i] = a%10+'0';
			y[i] = b%10+'0';
			a /= 10;
			b /= 10;
		}
		cout << X << ' ' << y;
		cout << '\n';
	}
	return 0;
}
