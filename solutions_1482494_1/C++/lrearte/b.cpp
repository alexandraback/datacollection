#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define all(x) x.begin(),x.end()
#define bits(x) __builtin_popcount(x)
#define FOR(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)


int main() {
	int n,N,tmpa, tmpb;
	cin>>n;
	for (int caso = 1; caso <= n; caso++) {
		cin>>N;
		vector<pair<int, int> > lev(N);
		vector<int> used(N, 0);
		for (int i=0;i<N;i++) {
			cin>>tmpa>>tmpb;
			lev[i]=make_pair(tmpa, tmpb);
		}
		
		int stars=0, totlev=0;
		bool change=true;
		while (change) {
			change = false;
			
			for (int i=0;i<N;i++) if (used[i]<2 && lev[i].second<=stars) {
				change=true;
				stars+=2-used[i];
				used[i]=2;
				totlev++;
			}
			if (!change) {
				int maxi=-1, maxpos=-1;
				for (int i=0;i<N;i++) if (used[i]<1 && lev[i].first<=stars && lev[i].second>maxi) {
					maxi=lev[i].second;
					maxpos=i;
				}
				if (maxpos!=-1) {
					stars+=1-used[maxpos];
					used[maxpos]=1;
					totlev++;
					change=true;
				}
			}
		}
		
		bool ok=true;
		for (int i=0;i<N;i++) if (used[i]<2) {
			ok=false; break;
		}
		
		cout << "Case #" << caso << ": ";
		if (ok) cout<<totlev;
		else cout<<"Too Bad";
		cout<<endl;
	}
	return 0;
}
