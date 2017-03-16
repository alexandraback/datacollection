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

int mas[ST];
int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int test = 1,T;
	cin >> T;
	while(test <= T)
	{
		int ans = INF;
		int n,A;
		cin >> A >> n;
		for(int i = 0;i < n;i++)
		{
			cin >> mas[i];
		}
		sort(mas,mas+n);
		for(int u = 0;u <= n;u++)
		{
			for(int add = 0;add+u <= n;add++)
			{
				int a = A;
				int ca = 0;
				int cd = 0;
				bool can = true;
				for(int i = 0;i < n;i++)
				{
					if(a <= mas[i])
					{
						if(ca < add)
						{
							a+=(a-1);
							i--;
							ca++;
						}
						else
						{
							if(cd < u)
							{
								cd++;
							}
							else
							{
								can = false;
								break;
							}
						}
					}
					else
					{
						a+=mas[i];
					}
				}
				if(can)
				{
					ans = min(ans,u+add);
				}
			}
		}
		printf("Case #%d: %d\n",test,ans);
		test++;
	}

    return 0;
}