#include <iostream>
#include <vector>
#include <set>
using namespace std;

int was[2222];
int one[2222],two[2222];
int main() {
	int n;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++) {	
		int t,a,b;
		//vector < pair <int, pair <int,int> > > one,two;

		memset(was,0,sizeof(was));
		int ans = 0, used = 0;
		
		scanf("%d",&t);
		for (int i=0;i<t;i++) {
			scanf("%d %d",&one[i],&two[i]);
			//one.insert(make_pair(a,make_pair(-b,i)));
			//two.insert(make_pair(b,make_pair(-a,i)));
		}
		int stars = 0;
		while (used != t) {
			ans++;
			int ix = -1;
			for (int i=0;i<t;i++) {
				if (two[i]<=stars && was[i]<2) {
					if (ix == -1) ix = i; else if (!was[i]) ix = i;
				}
			}
			if (ix != -1) {
				stars += !was[ix] ? 2 : 1;
				was[ix] = 2;
				used++;
			} else {
				ix = -1;
				for (int i=0;i<t;i++) {
					if (one[i]<=stars && !was[i]) {
						if (ix == -1) ix = i; else if (two[i]>two[ix]) ix = i;
					}
				}
				if (ix == -1) break;
				was[ix] = 1;
				stars++;
			}
		}
		if (used == t) printf("Case #%d: %d\n",i+1,ans); else printf("Case #%d: Too Bad\n",i+1);
		/*while (!two.empty()) {
			ans++;
			set < pair <int, pair <int,int> > >::iterator it = two.begin();
			if (it->first <= stars) {
				stars += was[it->second.second] ? 1 : 2;
				was[it->second.second] = true;
				two.erase(it);
			} else {
				while (!one.empty() && was[one.begin()->second.second]) one.erase(one.begin());
				if (one.empty()) break;
				it = one.begin();
				if (it->first > stars) break;
				was[it->second.second] = true;
				stars++;
				one.erase(it);
			}
		}

		if (two.empty()) printf("Case #%d: %d\n",i+1,ans); else printf("Case #%d: Too Bad\n",i+1);*/
	}
}
