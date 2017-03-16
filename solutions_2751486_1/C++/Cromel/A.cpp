#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <stack>
#include <string.h>
#include <list>
#include <assert.h>

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define PI 3.14159265358979
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define L(s) (int)((s).size())
#define ms(x) memset(x,0,sizeof(x))
#define ms1(x) memset(x,-1,sizeof(x))
#define del(y,x) erase(y.begin()+x)

typedef long long ll;
using namespace std;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;
const int ST = 100010;
const int ST1 = 1000010;
const ll MOD = 1000000007;

ll ABS(ll a)
{
    if(a<0)
        return a*(-1);
    else
        return a;
}

int main()
{
#ifdef _DEBUG
    freopen("A-large (2).in", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int cur = 1,T;
	cin >> T;
	while(cur <= T)
	{
		string a;
		int n;
		ll ans = 0;
		int prev = 0;
		cin >> a >> n;
		int kol = 0;
		int siz = L(a);
		for(int i = 0;i < L(a);i++)
		{
			if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
			{
				kol = 0;
			}
			else
			{
				kol++;
				if(kol >= n)
				{
					ll bef = i-n-prev+2;
					ll aft = siz-i;
					ans+=bef*aft;
					prev = i-n+2;
				}
			}
		}
		printf("Case #%d: %lld\n",cur,ans);
		cur++;
	}

    return 0;
}