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

vector<vector<int> > ans;

int main()
{
#ifdef ACMTUYO
	freopen("C-small-attempt0(2).in","r",stdin);
	freopen("C-small-attempt0(2).out","w",stdout);
#endif

	int T;
	cin >> T;
	
	forn(tc,T)
	{
		ans.clear();
		int a, b, c, k;
		cin >> a >> b >> c >> k;
		k = min(k,c);
		int ac=0;
		forn(i, a)
		{
			forn(j, b)
			{
				forn(l, k)
				{
					vector<int> s(3);
					s[0] = i;
					s[1] = j;
					s[2] = ac;
					ac= (ac+1)%c;
					ans.push_back(s);
				}
				ac= (ac+1+c-k)%c;
			}
			ac= (ac+1+c*b*k-b*k)%c;
		}
		
		int ss=ans.size();
		forn(i, c)
		{
			vector<int> leftbc(b, k), leftac(a, k);
			forn(j, ss)
			if(ans[j][2] == i)
			{
				leftac[ans[j][0]]--;
				leftbc[ans[j][1]]--;
				if(leftac[ans[j][0]]<0 || leftbc[ans[j][1]]<0){ cout << "INVALID" << endl;}
			}
		}
		cout << "Case #" << tc+1 << ": " << ss << endl;
		forn(i, ss) cout << ans[i][0]+1 << " " << ans[i][1]+1 << " " << ans[i][2]+1 << endl;
	}
	return 0;
}
