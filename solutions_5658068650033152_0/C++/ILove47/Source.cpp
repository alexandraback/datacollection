#include <ctime>
#include <bitset>
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



int n, m, k;

char a[22][22];

void fill(int i, int j)
{
	if (i<0 || j<0 || i>n+1 || j>m+1)
		return;
	if (a[i][j]=='.')
	{
		a[i][j]='+';
		fill(i-1,j);
		fill(i+1,j);
		fill(i,j-1);
		fill(i,j+1);
	}
}

bool check_mask(int mask)
{
	FILL(a,'.');
	for (int i = 0; i < m*n; ++i)
	{
		int p = mask&1;
		mask >>= 1;
		if (p)
			a[1+i/m][1+i%m]='#';
	}
	int r = 0;
	fill(0,0);
	for (int i = 1; i <=n; ++i)
	{
		for (int j = 1; j <=m; ++j)
		{
			if (a[i][j]!='+')
				++r;
		}
	}
	if (r>=k)
		return true;
	return false;
}

void solve()
{
	cin >> n >> m >> k;
	int MASK_MAX = 1;
	for (int i = n*m; i >0; --i)
		MASK_MAX *= 2;
	int mn = 1000000000;
	for(int mask = 0; mask < MASK_MAX; ++mask)
	{
		if (check_mask(mask))
		{
			int kkk = bitset<22>(mask).count();
			mn = MIN(mn,kkk);
		}
	}
	cout << mn;
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
/*

13/16
8/8			5/8
4/4			1/4
1/2		0/1
1/1		0






3/8
0 3/4
1 1/2
0 1

3/8
1/4 2/4
0 1/2 0 1
0 1

*/