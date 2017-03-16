#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;

typedef long long 			int8;
typedef vector<int>			vi;
typedef vector<string>			vs;
typedef vector<double>			vd;
typedef pair<int,int>			pii;
typedef vector<pair <int, int> >	vpii;

// Loops...
#define forn(i, n) 		for (int i = 0; i < (int)(n); i++)
#define fornd(i, n)		for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b)		for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, a, b)		for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) 		for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

// Containers...
#define all(v)			(v).begin(), (v).end()
#define zero(a)			memset(a, 0, sizeof(a))
#define fl(a,c)			memset(&a, c, sizeof(a))
#define pb			push_back
#define mp			make_pair
#define sz(a)			(int)(a).size()
	
template<typename T> inline T sqr(T a) { return a*a; }

int main()
{
	int		_T, caseno = 1;
	
	for (cin >> _T; _T != 0; _T--)
	{
		vd		v;
		int		A, B;
		cin >> A >> B;
		
		v.pb(1);
		for (int i = 1; i <= A; i++)
		{
			double		p;

			cin >> p;
			v.pb(p * v[i - 1]);
		}
		double allright = v[A];
		double choice3 = 1 + B + 1;
		double choice1 = allright * ((B - A) + 1) + (1 - allright) * (B + 1 + (B - A) + 1);
		double _min = min(choice1, choice3);
		for (int i = 1; i <= A; i++)
		{
			double _choice2 = (v[A - i] * (2 * i + (B - A) + 1)) + ((1 - v[A - i]) * (2 * i + (B - A) + 1 + B + 1));
			_min = min(_min, _choice2);
		}
		printf("Case #%d: %.6f\n", caseno++, _min);
	}
	return 0;
}
