#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;

int n,d[1111],da[1111],db[1111],a[1111],b[1111];

int main()
{
	freopen("bsmall.in","r",stdin); freopen("bsmall.out","w",stdout);
	int test;
	cin >> test;
	fr(it,1,test)
	{
		cin >> n;
		rep(i,n) cin >> a[i] >> b[i], da[i]=db[i]=i, d[i]=0;
		rep(i,n)
			fr(j,i+1,n-1)
				if (a[da[i]]>a[da[j]] || (a[da[i]]==a[da[j]] && b[da[i]]<b[da[j]]))
					swap(da[i],da[j]);
		rep(i,n)
			fr(j,i+1,n-1)
				if (b[db[i]]>b[db[j]])
					swap(db[i],db[j]);
		
		int star=0,i=0,j=0,cnt1=0;
		priority_queue < pair<int,int> > q;
		while (j<n)
		{
			while (j<n && star>=b[db[j]]) star+=2-d[db[j++]];
			if (j>=n) break;
			while (i<n && star>=a[da[i]]) q.push(mp(b[da[i]],da[i])), i++;
			int found=0;
			while (!q.empty())
			{
				int y=q.top().se; q.pop();
				if (d[y]) continue;
				d[y]=1; cnt1++; star++;
				found=1; break;
			}
			if (!found) break;
		}
		
		cout << "Case #" << it << ": ";
		if (star==n*2) cout << cnt1+n << endl;
		else puts("Too Bad");
	}
}
