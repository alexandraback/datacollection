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


int main()
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
	
	int T;	cin >> T;
	for (int cas = 1; cas <= T; ++ cas)
	{
		double C, F, X;
		cin >> C >> F >> X;
		double D = 2;
		double ans = X / 2;
		double sum = 0.0;
		while (D < (X - C) * F / C + 1e-6)
		{
			sum += C / D;
			D += F;
			ans = min (ans, sum + X / D);	
		}	
		printf ("Case #%d: %.10f\n", cas, ans);
	}
	
	
	
	return 0;	
}
