#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define LL unsigned long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))

using namespace std;

string s;
LL p, q;

LL gcd(LL a, LL b)
{
	if (! b) return a;
	return gcd(b, a % b);
}
	
int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);	
#endif

	int T;
	cin >> T;
	getline(cin, s);
	
	for (int t = 1; t <= T; t ++)
	{
		cout << "Case #" << t << ": ";
		getline(cin, s);
		
		int pos = s.find("/");
		p = q = 0;
		
		for (int i = 0; i < pos; i ++)
			p = (p * 10LL) + (LL) (s[i] - 48);
		for (int i = pos + 1; i < s.size(); i ++)
			q = (q * 10LL) + (LL) (s[i] - 48);
		
		for ( ; ; )
		{
			LL v = gcd(p, q);
			if (v == 1LL) break;
			p /= v, q /= v;
		}
		
		//check
		LL x = q;
		while (x % 2LL == 0LL)
			x /= 2LL;
		if (x != 1)
		{
			cout << "impossible" << endl;
			continue;
		}
		
		int ans = 1;
		while (p * 2LL < q)
			q /= 2, ans ++;
		cout << ans << endl;
	}
	return 0;
}
