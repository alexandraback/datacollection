#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t; scanf("%d", &t);
	for(int _i=0; _i<t; _i++) {
		int n, s, p; scanf("%d %d %d", &n, &s, &p);
		vector<pair<int, int> > ti;
		for(int i=0; i<n; i++) {
			int x; scanf("%d", &x);
			ti.push_back(make_pair(x/3+((x%3)!=0), x));
		}
		sort(ti.begin(), ti.end());
		for(int i=0; i<n && s>0; i++) {
			int x = ti[i].second;
			if(ti[i].first<p && x>1) {
				if(x%3==0) {
					if(x/3+1>=p) {
						ti[i].first=x/3+1;
						s--;
					}
				} else if(x%3==2) {
					if(x/3+2>=p) {
						ti[i].first=x/3+2;
						s--;
					}
				}
			}
				
		}
		int count=0;
		for(int i=0; i<n; i++) {
			if(ti[i].first>=p) {
				count++;
			}
		}
		printf("Case #%d: %d\n", _i+1, count);
	}
}
