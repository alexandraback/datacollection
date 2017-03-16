//Created By Mayur Agarwal :)

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <map>
#include <iterator>
#include <functional>
#include <stack>
#include <queue>

#define ll long long
#define in(a) scanf("%lld",&a)
#define inc(a) scanf("%c",&a)
#define ins(a) scanf("%s", &a)
#define pr(a) prllf("%lld\n",a)
#define prc(a) prllf("%c",a)
#define prs(a) prllf("%s\n",a)
#define fori(I,N) for(ll I=0;I<N;I++)
#define forin(i,n) for(ll I=1;I<=N;I++)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define ALL(X) (X).begin(), (X).end()
#define pi   acos(-1.0)
#define mod 1000000007
#define SIZE 200010

using namespace std;
typedef pair<ll, ll>pll;
string s1, s2;

void go(vector<ll> &v, string str, ll i, ll num)
{
	if (i == s1.size())
	{
		v.push_back(num);
		return ;
	}
	if (str[i] == '?')
	{
		for (ll j = 0; j <= 9; j++)
		{
			go(v, str, i + 1, num * 10 + j);
		}
	}
	else
		go(v, str, i + 1, num * 10 + (str[i] - '0'));
}

int main()
{
	//freopen ("input.txt", "r", stdin);
	//freopen ("output1.txt", "w", stdout);
	ll t;
	cin >> t;
	for (ll xx = 1; xx <= t; xx++)
	{
		cout << "Case #" << xx << ": ";
		cin >> s1 >> s2;
		//ll n = s.size();
		std::vector<ll> v, v1;
		go(v, s1, 0, 0);
		go(v1, s2, 0, 0);
		ll val1 = 0, val2 = 0, ans = 1000000000000000009;
		// for (ll i = 0; i < v1.size(); i++)
		// {
		// 	cout << v1[i] << endl;
		// }
		for (ll i = 0; i < v.size(); i++)
		{
			for (ll j = 0; j < v1.size(); j++)
			{
				if (abs(v[i] - v1[j]) < ans)
				{
					val1 = v[i];
					val2 = v1[j];
					ans = abs(v[i] - v1[j]);
				}
				else if (abs(v[i] - v1[j]) == ans)
				{
					if (val1 > v[i])
					{
						val1 = v[i];
					}
					else if (val2 > v1[j])
					{
						val2 = v1[j];
					}
				}
				// cout << val1 << " " << val2 << endl;
			}
		}
		std::vector<ll> ans1, ans2;
		while (val1 > 0)
		{
			ans1.push_back(val1 % 10);
			val1 /= 10;
		}
		while (ans1.size() < s1.size())
		{
			ans1.push_back(0);
		}
		while (val2 > 0)
		{
			ans2.push_back(val2 % 10);
			val2 /= 10;
		}
		while (ans2.size() < s1.size())
		{
			ans2.push_back(0);
		}
		reverse(ans1.begin(), ans1.end());
		reverse(ans2.begin(), ans2.end());
		for (ll i = 0; i < ans1.size(); i++)
			cout << ans1[i];
		cout << " " ;
		for (ll i = 0; i < ans2.size(); i++)
			cout << ans2[i];
		cout << endl;
	}
	return 0;

}