#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>

#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld epsylon = 1e-9;
typedef unsigned int ui;

ll a, b;

int main()
{
	freopen("Fair and Square numbers under 10^14.txt", "r", stdin);
	vector <ll> fairs;
	ll num;
	while (!cin.eof())
	{
		cin >> num;
		if (num != -1)
			fairs.push_back(num);
		num = -1;
	}
	freopen("Fair and Square.in","r",stdin);
	freopen("Fair and Square1.out","w",stdout);
	//program
	int tests;
	scanf("%d\n", &tests);
	for (int Case = 1; Case <= tests; Case++)
	{
		scanf("%lld %lld", &a, &b);
		int res = 0;
		for (int i = 0; i < fairs.size(); ++i)
		{
			if (fairs[i] >= a && fairs[i] <= b) res++;
		}
		printf("Case #%d: %d\n", Case, res);
	}
	//end program
	return 0;
}






