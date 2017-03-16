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
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))

using namespace std;

const int maxn = 401010;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);	
#endif
	int T; cin >> T;
	for (int t = 1; t <= T; t ++)
	{
		cout << "Case #" << t << ": ";
		double curSpeed = 2.0, sum = 0.0;
		double C, F, X, ans = 1e20;
		
		cin >> C >> F >> X;
		for (int i = 0; i <= 1000000; i ++)
		{
			if (sum + X / curSpeed < ans)
				ans = sum + X / curSpeed;
			sum += C / curSpeed;			
			curSpeed += F;
		}
		
		printf("%.7lf\n", ans);
	}
	return 0;
}		
