//Seikang

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <stdlib.h>
#include <assert.h>

#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>

#include <cmath>
#include <complex>
#include <algorithm>

#include <ctime>
#define gtime clock()

using namespace std;

#define SZ(cont) (int)(cont.size())
#define ALL(cont) (cont).begin(), (cont).end()
#define DEBUG(x) cerr << ">" << #x << ":" << x << endl

typedef long long int64;
typedef pair<int64, int64> ii;
typedef vector<int64> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;

const int64 oo32 = 1ll << 30, oo64 = 1ll << 60;
const double pi = acos(-1.0), eps = 1e-9;
inline bool equal(const double &a, const double &b){return abs(a - b) < eps;}

bool isvocal(char c)
{
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
	{
		return true;
	}
	return false;
}
int main()
{
//	freopen ("in.txt", "rt", stdin);
//	freopen ("out.txt", "wt", stdout);

	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		string s;
		int n;
		cin >> s >> n;
		int64 ans = 0;
		//DEBUG(s);DEBUG(n);
		int a = 0, b = 0, curr =0;
		while(curr < n && b < SZ(s))
		{
			if(isvocal(s[b]))
			{
				curr = 0;
				a = b + 1;
				b = b + 1;
			}
			else
			{
				curr++;
				b = b + 1;
			}
		}
			
		for(int i = 0; curr >= n && i < SZ(s); i++)
		{
			if(i > a)
			{
				curr--;
				a++;
			}
			while(curr < n && b < SZ(s))
			{
				if(isvocal(s[b]))
				{
					curr = 0;
					a = b + 1;
					b = b + 1;
				}
				else
				{
					curr++;
					b = b + 1;
				}
			}
			if(curr >= n)
			{
				ans += SZ(s) - b + 1;
			}
		}
		
		cout << "Case #" << t + 1 << ": " << ans << endl;
	}
	return 0;
}
