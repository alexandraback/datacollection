//#pragma comment(linker, "/stack:16777216")
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define FILL(a,v) memset(a,v,sizeof(a))

const double PI = acos(-1.0);
const double EPS = 1e-7;

typedef long long ll;
typedef unsigned long long ull;

int me;
int a[1000];
int r[1000];
int n;

void solve()
{
	cin >> me >> n;
	for (int i = 0; i != n; ++i)
	{
		cin >> a[i];
	}
	sort(a, a+n);
	a[n] = 1000000000;
	int p = 0;
	for (int i = 0; i < n; ++i)
	{
		while (me > a[p])
		{
			me += a[p++];
		}
		r[i] = i + n - p;
		me = me + me - 1;
	}
	int mm = 1000000000;
	for (int i = 0; i < n; ++i)
	{
		if (r[i] < mm)
			mm = r[i];
	}
	cout << mm << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int tests;
	scanf("%d", &tests);
	++tests;
	for (int i = 1; i != tests; ++i)
	{
		printf("Case #%d: ", i);
		int time = clock();
		solve();
		cerr<<"Case #"<<i<<"\t time="<<clock()-time<<endl;
	}
}