#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring> 
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cmath>
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef vector <int> VI;
typedef vector <string> VS;
typedef vector <LL> VL;

const int MAXN = 100010 * 2;

LL gcd (LL a, LL b)
{
	return b ? gcd (b, a % b) : a;	
}

int main()
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	
	int T;	cin >> T;
	for (int cas = 1; cas <= T; ++ cas)
	{
		LL x, y;
		scanf ("%lld / %lld", &x, &y);
		LL g = gcd (x, y);	
		x /= g;
		y /= g;
		
		cout << "Case #" << cas << ": ";
		if ((y & -y) != y)
		{
			cout << "impossible" << endl;	
		}
		else
		{
			int a = 0, b = 0;
			for (int i = 0; i < 50; ++ i)	
			{
				if (x >> i)	a = i;
				if (y >> i)	b = i;
			}	
			cout << b - a << endl;
		}
	}
	
	
	
	return 0;	
}
