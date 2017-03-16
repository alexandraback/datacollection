#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define ll long long
#define ii pair<int,int>
#define mp make_pair
#define pb push_back
#define INF 1000000000
//vector<vector<int> > v;
int tc,n;
map<int,int> cnt;
int main() {
	scanf("%d",&tc);
	for (int kk=1;kk<=tc;kk++) {
		scanf("%d",&n);
		cnt.clear();
		for (int i=0;i<2*n-1;i++) {
			int x;
			for (int j=0;j<n;j++) {
				scanf("%d",&x);
				cnt[x]++;
			}
		}
		printf("Case #%d:", kk);
		for (ii x:cnt) {
			if (x.second%2) {
				printf(" %d",x.first);
			}
		}
		printf("\n");
		/*
		v.clear();
		memset(used,0,sizeof(used));
		for (int i=0;i<2*n-1;i++) {
			vector<int> x;
			int y;
			for (int j=0;j<n;j++) {
				scanf("%d",&y);
				x.pb(y);
			}
			v.pb(x);
		}
		for (int k=0;k<n;k++) {
			int m=INF;
			for (int i=0;i<sz(v);i++) {

			}
		}

		vector<int> cur;
		cur.pb(m);
		vector<int> idx;
		for (int i=0;i<sz(v);i++) {
			bool can=1;
			for (int j=0;j<sz(cur);j++) {
				if (v[i][j]!=cur[j]) {
					can=0;
					break;
				}
			}
			if (can) idx.pb(i);
		}
	*/
	}
}