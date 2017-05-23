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

void pans(int a)
{
	cout << a << '\n';
}

void print(int b, int c, int d)
{
	cout << b << ' ' << c << ' ' << d << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("C-large.in", "r", stdin);
	freopen("GCJ20161C-3.out", "w", stdout);
	int t; cin >> t;
	int T = 0;
	while(t--)
	{
		T++;
		cout << "Case #" << T << ": ";
		int j, p, s, k;
		cin >> j >> p >> s >> k;
		//cout << j << ' ' << p << ' ' << s << ' ' << k << '\n';
		if(k >= s)
		{
			cout << j*p*s << '\n';
			for(int a = 1; a <= j; a++)
			{
				for(int b = 1; b <= p; b++)
				{
					for(int c = 1; c <= s; c++)
					{
						cout << a << ' ' << b << ' ' << c << '\n';
					}
				}
			}
		}
		else
		{
			pans(k*j*p);
			for(int a = 1; a <= j; a++)
			{
				for(int b = 1; b <= k; b++)
				{
					for(int c = 1; c <= p; c++)
					{
						print(a, c, (a+b+c-1)%s + 1);
					}
				}
			}
		}
		/*
		else if(k == 1)
		{
			cout << j*p << '\n';
			for(int a = 1; a <= j; a++)
			{
				for(int b = 1; b <= p; b++)
				{
					cout << a << ' ' << b << ' ' << ((b + a - 1)%p + 1) << '\n';
				}
			}
		}
		else
		{
			if(j == 1 && p == 1 && s == 1)
			{
				pans(1);
				print(1, 1, 1);
			}
			else if(j == 1 && p == 1 && s == 2)
			{
				pans(2);
				print(1, 1, 1);
				print(1, 1, 2);
			}
			else if(j == 1 && p == 1 && s == 3)
			{
				pans(2);
				print(1, 1, 1);
				print(1, 1, 2);
			}
			else if(j == 1 && p == 2 && s == 2)
			{
				pans(4);
				print(1, 1, 1);
				print(1, 1, 2);
				print(1, 2, 1);
				print(1, 2, 2);
			}
			else if(j == 1 && p == 2 && s == 3)
			{
				pans(4);
				print(1, 1, 1);
				print(1, 1, 2);
				print(1, 2, 1);
				print(1, 2, 2);
			}
			else if(j == 1 && p == 3 && s == 3)
			{
				pans(6);
				print(1, 1, 1);
				print(1, 1, 2);
				print(1, 2, 2);
				print(1, 2, 3);
				print(1, 3, 3);
				print(1, 3, 1);
			}
			else if(j == 2 && p == 2 && s == 2)
			{
				pans(8);
				print(1, 1, 1);
				print(1, 1, 2);
				print(1, 2, 1);
				print(1, 2, 2);
				print(2, 1, 1);
				print(2, 1, 2);
				print(2, 2, 1);
				print(2, 2, 2);
			}
			else if(j == 2 && p == 2 && s == 3)
			{
				pans(8);
				print(1, 1, 1);
				print(1, 1, 2);
				print(1, 2, 1);
				print(1, 2, 2);
				print(2, 1, 1);
				print(2, 1, 2);
				print(2, 2, 1);
				print(2, 2, 2);
			}
			else if(j == 2 && p == 3 && s == 3)
			{
				pans(12);
				print(1,1,1);
				print(1,2,2);
				print(1,3,3);
				print(1,1,2);
				print(1,2,3);
				print(1,3,1);
				print(2,1,3);
				print(2,2,1);
				print(2,3,2);
				print(2,1,1);
				print(2,2,2);
				print(2,3,3);
			}
			else
			{
				pans(18);
				print(1,1,1);
				print(1,2,2);
				print(1,3,3);
				print(1,1,2);
				print(1,2,3);
				print(1,3,1);
				
				print(2,1,3);
				print(2,2,1);
				print(2,3,2);
				print(2,1,1);
				print(2,2,2);
				print(2,3,3);
				
				print(3,1,2);
				print(3,2,3);
				print(3,3,1);
				print(3,1,3);
				print(3,2,1);
				print(3,3,2);
			}
		}
		*/
	}
	return 0;
}
