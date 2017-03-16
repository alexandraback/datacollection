#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <memory.h>
using namespace std;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back
#define ALL(c) (c).begin(), (c).end()
#define RESET(a,b) memset( (a), b, sizeof(a) )
#define ren(a,b,c) for (int a=b; a<c; ++a)
#define red(a,b,c) for (int a=b; a>=c; --a)
#define repi(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)

const double eps = 1e-9;
typedef long long ll;
typedef pair <int,int> pii;

//lintaor1's template

void solve( const int& );

int main()
{
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-small-attempt1.out", "w",stdout);
	int TT;
	cin >> TT; TT++;
	ren (T, 1, TT) solve( T );
	return 0;
}

//-------------------
void solve( const int &T )
{
	int n, i[24], res = -1;
	map < int, vector <int> > o;
	
	cin >> n;
	ren (x,0,n) cin >> i[x];
	ren (x,1,1<<n)
	{
		int sum = 0;
		ren (y,0,20) if ((1<<y)&x) sum+=i[y];
		if (res==-1 && o.count( sum )) res = sum;
		o[sum].pb( x );
	}
	
	//-----
	printf("Case #%d:\n", T);
	if (res == -1) cout << "Impossible" << endl; else
	{
		int w=2;
		repi( it, o[res] )
		{
			bool blm=false;
			ren (y,0,20) if ((1<<y)&(*it))
			{
				cout << ((blm)?" ":"") << i[y];
				if (!blm) blm = !blm;
			}
			cout << endl;
			if (--w == 0) break;
		}
	}
}
