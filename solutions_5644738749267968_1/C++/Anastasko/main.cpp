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

int n;
double N[1234];
double K[1234];
bool was[1234];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;

	FOR(T, 0, t)
	{
		int b = 0;
		int a = 0;

		cin >> n;

		FOR(i, 0, n)
			cin >> N[i];


		FOR(i, 0, n)
			cin >> K[i];

		FOR(i, 0, n)
		{
			was[i] = false;
		}

		sort(K, K + n);
		sort(N, N + n);

		int pos = 0;
		a = 0;

		while (true)
		{
			while (pos < n && N[pos] < K[a])
			{
				pos++;
			}
			if (pos >= n) break;
			a++;
			pos++;
		}

		FOR(i, 0, n)
		{
			double cur = N[i];

			int j = 0;
			while (j < n && (K[j] < cur || was[j]))
				j++;

			if (j < n)
			{
				was[j] = true;
			}
			else
			{
				b++;
				int y = 0;
				while (was[y])
					y++;
				was[y] = true;
			}
		}


		cout << "Case #" << T+1 << ": ";
		cout << a << " " << b << endl;
	}

	return 0;
}
