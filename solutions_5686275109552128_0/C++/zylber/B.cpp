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

int tot[1024];

int main()
{
#ifdef ACMTUYO
	freopen("B-small-attempt1.in.txt","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
#endif

	int T;
	cin >> T;
	
	forn(tc,T)
	{
		int d;
		cin >> d;
		
		memset(tot,0,sizeof(tot));
		forn(i, d)
		{
			cin >> tot[i];
		}
		
		int ans=1000;
		for(int i=1; i<=1000; i++)
		{
			int sub=0;
			forn(j, d)
			{
				sub+=max(0,(tot[j]-1)/i);
			}
			ans=min(ans, sub+i);
		}
		
		cout << "Case #" << tc+1 << ": " << ans << endl;
	}
	return 0;
}
