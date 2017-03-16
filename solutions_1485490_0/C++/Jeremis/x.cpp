#include <iostream>
#include <vector>
#include <set>
#include <memory.h>
#include <map>
#include <algorithm>
#include <string>
using namespace std;


int n,m;
__int64 calc(vector < pair <__int64,int> > a,vector < pair <__int64,int> > &b) {
	__int64 ans = 0;
	for (int i=0;i<=m;i++) {
		for (int j=i;j<=m;j++) {
			__int64 c[3] = {0ll, 0ll, 0ll};
			for (int l=0;l<i;l++) 
				if (b[l].second == a[0].second) c[0]+=b[l].first;
			c[0] = min(c[0],a[0].first);
			for (int l=i;l<j;l++) 
				if (b[l].second == a[1].second) c[1]+=b[l].first;
			c[1] = min(c[1],a[1].first);
			for (int l=j;l<m;l++) 
				if (b[l].second == a[2].second) c[2]+=b[l].first;
			c[2] = min(c[2],a[2].first);
			ans = max(ans,c[0]+c[1]+c[2]);
		}
	}
	return ans;
}

int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int t;
	cin >> t;
	for (int z=0;z<t;z++) {
		cin >> n >> m;
		vector < pair <__int64,int> > a,b;
		a.resize(3,make_pair(0ll,-1));
		b.resize(m);
		for (int i=0;i<n;i++) 
			cin >> a[i].first >> a[i].second;
		for (int i=0;i<m;i++) 
			cin >> b[i].first >> b[i].second;
		cout << "Case #" << z+1 << ": ";
		__int64 ans = 0;
		ans = calc(a,b);
		if (a[0].second == a[1].second == a[2].second) {
			vector < pair <__int64,int> > z;
			z.resize(3,make_pair(0ll,-1));
			z[0] = make_pair(a[0].first+a[1].first+a[2].first,a[0].second);
			ans = max(ans,calc(z,b));
		} else {
			vector < pair <__int64,int> > z;
			z = a;
			if (a[0].second == a[1].second) {
				z[0] = make_pair(a[0].first+a[1].first,a[0].second);
				z[1] = make_pair(0ll,-1);
			} else if (a[1].second == a[2].second) {
				z[1] = make_pair(a[1].first+a[2].first,a[1].second);
				z[2] = make_pair(0ll,-1);			
			} else if (a[0].second == a[2].second) {
				z[0] = make_pair(a[0].first+a[2].first,a[0].second);
				z[1] = make_pair(0ll,-1);
				z[2] = make_pair(0ll,-1);
			}
			ans = max(ans,calc(z,b));
		}
		cout << ans << endl;
	}
}