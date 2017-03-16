#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <memory.h>
#include <fstream>
#include <map>
#include <sstream>
#include <stack>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;
#define ll long long
#define MOD 1000000007
#define mp(a, b) make_pair(a, b)
#define PI 3.1415926535
#define EPS 0.00000001
#define pii pair<int, int>
#define INF 2000000000

//#define DEBUG 41

#ifndef DEBUG

ifstream in("in.txt");
ofstream out("out.txt");

#define cin in
#define cout out

#endif
template<typename T>
void print(int i, T a)
{
	cout << "Case #" << i << ": " << a << "\n";
}


ll a[1234567];

ll rev(ll a)
{
	stringstream s;
	s << a;
	ll ans = 0;
	for(int i = 0; i < s.str().size(); ++i)
	{
		ans *= 10;
		ans += s.str()[s.str().size() - i - 1] - '0';
	}
	return ans;
}

ll compute(ll aa)
{
	ll ans = 0;
	while(aa > 1000)
	{
		stringstream ss;
		ss << aa;
		string s = ss.str();
		int n;

		if(s.size() & 1)
			n = s.size() / 2 + 1;
		else
			n = s.size() / 2;
		ll ost = 0;
		ll nach = 0;
		for(int i = s.size() - n - 1; i >= 0; --i)
		{
			nach *= 10;
			nach += s[i] - '0';
		}
		for(int i = n-1; i >= 0; --i)
		{
			ost *= 10;
			ost += s[s.size() - i - 1] - '0';
		}
		if(ost == 0)
		{
			++ans;
			--aa;
			continue;
		}
		if(nach == 1)
		{
			ans += ost + 1;
			aa -= (ost + 1);
		}
		else
		{
			ans += ost;
			aa -= ost - 1;
			aa = rev(aa);
		}
	}

	return ans + a[aa];
}


int main()
{
	int n;
	cin >> n;
	a[1] = 1;
	queue<int> q;
	q.push(1);
	while(q.size())
	{
		int tp = q.front();
		q.pop();
		if(a[tp+1] == 0 && tp + 1 <= 1000)
		{
			a[tp+1] = a[tp]+1;
			q.push(tp+1);
		}
		int rv = rev(tp);
		if(a[rv] == 0 && rv <= 1000)
		{
			a[rv] = a[tp]+1;
			q.push(rv);
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		ll t;
		cin >> t;
		
		print(i, compute(t));
	}
	

}