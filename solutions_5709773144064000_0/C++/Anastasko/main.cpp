//#pragma comment(linker, "/STACK:134217728")
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(int i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair
#define MOD 1000000009
#define INF 1000000007
#define y1 agaga
#define ll long long
#define ull unsigned long long

double s, f, c, x;
double k;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cout.precision(7);
	int t;
	cin >> t;

	FOR(T,0,t)
	{
		cin >> c >> f >> x;

		double kn = c / 2 + x/(2+f);
		double z = 2 + f;
		k = x / 2;

		while (kn < k)
		{
			k = kn;
			kn = kn - (x - c) / z;
			z += f;
			kn += x / z;
		}

		cout << "Case #" << T+1 << ": ";
		cout << fixed << k << endl;
	}

	return 0;
}
