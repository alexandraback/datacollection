/*
** In the name of God **
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iterator>

using namespace std;
#define FR(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,c,n) for(int (i)=(c);(i)<(n);(i)++)
#define REP(it,v,cont) for(cont::iterator (it)=(v).begin();(it)!=(v).end();++(it))
#define CLR(a,c) memset((a),(c),sizeof (a))
#define ALL(v) (v).begin(),(v).end()
#define EPS 1e-6
#define MOD 1000000007
#define INF 100000000
#define SQR(a) ((a)*(a))
#define e(a,b) (fabs(a-b)<EPS)
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int tnum;int q=1;
	for(cin>>tnum;tnum--;)
	{
		int N; cin>>N; int x=0;
		VI a(N);
		FR(i,N){ cin >> a[i]; x+=a[i];}
		printf("Case #%d: ",q++);
		FR(i,N)
		{
			double low=0;double high=100;
			double ans = 0;
			while(low + EPS < high)
			{
				double mid = (low+high)/2;
				double y = a[i] + mid/100 * x;
				double rem = 100-mid;
				FR(j,N)
				{
					if(i==j) continue;
					if( y < a[j]) continue;
					double z = (y-a[j])/x*100;
					rem -= z;
				}
				if(rem > EPS)
					low = mid;
				else {
					ans = mid;
					high = mid;
				}
			}
			if(i==0) cout << setprecision(5) << fixed << ans;
			else cout << setprecision(5) << fixed << " " << ans;
		}
		cout << endl;
	}
}