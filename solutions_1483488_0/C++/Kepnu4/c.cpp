#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <ctime>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <cassert>
#include <climits>
#include <fstream>

using namespace std;

#define Filename ""
#define sqr(a) (a)*(a)

typedef long long lng;
typedef long double ldb;

const double EPS = 1e-8;

int A, B, was[2000005];

void Load()
{
	cin >> A >> B;
}

int get (int a) {
	int res = 0;
 	vector <int> b;
 	for (int i = a;i > 0;i /= 10)
 		b.push_back (i % 10);

 	for (int i = 0;i < b.size() - 1;i++) {
 	 	b.push_back (b[0]);
 	 	b.erase (b.begin());
 	 	if (b[b.size() - 1] == 0) continue;
 	 	int cur = 0;
 	 	for (int j = b.size() - 1;j >= 0;j--)
 	 		cur = cur * 10 + b[j];
 	 	if (cur < A || cur > B || was[cur]) continue;
 	 	was[cur] = 1;
 	 	res++;
 	}
 	return res;
}

void Solve()
{
	memset (was, 0, sizeof (was));
	long long ans = 0;
	for (int i = A;i <= B;i++) {
	 	if (was[i]) continue;

	 	was[i] = 1;
	 	int q = get (i);
	 	ans += q * (q + 1) / 2;
	 	//cerr << i << " " << q << endl;
	}
	cout << ans << endl;
}

int main()
{
	//freopen(Filename".in", "r", stdin);
	//freopen(Filename".out", "w", stdout);

	int t;
	cin >> t;

	for (int i = 0;i < t;i++) {

		printf ("Case #%d: ", i + 1);
		Load();

		Solve();
	}

	return 0;
}
