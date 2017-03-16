#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
typedef long long tint;
using namespace std;

long long DP[64];
long long ady[64][64];

int main()
{
#ifdef ACMTUYO
	freopen("B-small-attempt0(2).in","r",stdin);
	freopen("B-small-attempt0(2).out","w",stdout);
#endif

	int T;
	cin >> T;
	
	forn(tc,T)
	{
		int n, m;
		cin >> n >> m;
		memset(DP,0,sizeof(DP));
		memset(ady,0,sizeof(ady));
		
		DP[0]=1;
		forn(i, n)
		{
			long long k=m;
			for(int j = i-1; j>=0; j--)
			{
				if(DP[j]<=k){
					DP[i]+=DP[j];
					ady[n-i-1][n-j-1]=1;
					k-=DP[j];
				}
			}
		}
		
		if(DP[n-1]==m)
		{
			cout << "Case #" << tc+1 << ": POSSIBLE";
			cout  << endl;
			forn(i, n)
			{
				forn(j, n)
				{
					cout << ady[i][j];
				}
				cout << endl;
			}
		}
		else
		{
			cout << "Case #" << tc+1 << ": IMPOSSIBLE";
			cout  << endl;
		}
	}
	return 0;
}
