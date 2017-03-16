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

map<int,vector<VI> >mp;
bool isValid(VI a, VI b)
{
	FR(i,a.size())
	{
		FR(j,b.size())
			if(a[i]==b[j]) return false;
	}
	return true;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int tnum;int q=1;
	for(cin>>tnum;tnum--;)
	{
		mp.clear();
		printf("Case #%d:\n",q++);
		int N; cin>>N;
		VI a(N); FR(i,N) cin>>a[i];
		for(int i=0;i<(1<<N);i++)
		{
			VI b;
			FR(j,N)
			{
				if((1<<j) & i)
					b.push_back(a[j]);
			}
			int sum=0;
			FR(l,b.size()) sum += b[l];
			mp[sum].push_back(b);
			if(mp[sum].size()>1)
			{
				vector<VI> t = mp[sum];
				FR(idx,t.size())
					if(isValid(t[idx],b))
					{
						FR(ind,t[idx].size())
							if(ind==0)cout << t[idx][ind];
							else cout << " " << t[idx][ind];
						cout << endl;
						FR(ind,b.size())
							if(ind==0)cout << b[ind];
							else cout << " " << b[ind];
						cout << endl;
						goto next;
					}
			}
		}
next:;
	}
}