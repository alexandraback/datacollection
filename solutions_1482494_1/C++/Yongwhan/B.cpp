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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime> 
using namespace std;

typedef pair<int,int> pii;

int main() {
	int t; cin>>t;
	for (int c=1; c<=t; c++) {
		int n, ans=0; cin>>n;
		vector<pii> v(n);
		for (int i=0; i<n; i++) {
			int x,y; cin>>x>>y;
			v[i]=make_pair(x,y);
		}

		vector<bool> vis(n);
		for (int i=0; i<n; i++) vis[i]=false;

		int cur=0;
		bool ok=true;
		while(1) {
			int sz=v.size();
			if(!sz) break;

			int idx=-1;
			for (int i=0; i<sz; i++) {
				if(v[i].second<=cur) {
					idx=i; cur++;
					if(!vis[i]) cur++;
					break;
				}
			}

			if(idx!=-1) {
//				cout << "! " << v[idx].first << " " << v[idx].second << endl;
				v.erase(v.begin()+idx);
				vis.erase(vis.begin()+idx);
				ans++;
			} else {
				int xx=-1, yy=-1, idx=-1;
				for (int i=0; i<sz; i++) {
					if(v[i].first<=cur && !vis[i]) {
						if(yy==-1) {
							idx=i; yy=v[i].second;
						} else {
							if(yy<v[i].second) {
								idx=i;
								yy=v[i].second;
								xx=v[i].first;
							} else {
								if(yy==v[i].second) {
									if(xx<v[i].first) {
										idx=i;
										xx=v[i].first;
									}
								}
							}
						}
					}
				}
				if(idx==-1)  { ok=false; break; }
				else {
//					cout << "# " << v[idx].first << " " << v[idx].second << endl;
					cur++; ans++; vis[idx]=true;
				}
			}
			if(!ok) break;
		}

		if(!ok) cout << "Case #" << c << ": " << "Too Bad" << endl;
		else cout << "Case #" << c << ": " << ans << endl;
	}
	return 0;
}
