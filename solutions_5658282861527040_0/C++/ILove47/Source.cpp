#include <ctime>
#include <iterator>
#include <string>
#include <vector>
#include <map>
#include <list>
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
 
 
#define PB	push_back
#define MP  make_pair
#define ALL(a) 	(a).begin(), (a).end()
#define FILL(a,v) memset(a,v,sizeof(a))

#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define ABS(A) ((A) < 0 ? (-(A)) : (A))
#define SQR(x) (x)*(x)

const double PI = acos(-1.0);
const double EPS = 1e-7;

const int INF = 2000000000;
 

void solve()
{
	int a,b,c;
	cin >> a >> b >> c;

	int res = 0;
	for (int i = 0; i < a; ++i)
		for (int j = 0; j < b; ++j)
			if ((i&j) < c)
				++res;
	cout << res;
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test)
	{
		cout << "Case #"<<test<<": ";
		solve();
		cout << endl;
	}





	return 0;
} 
