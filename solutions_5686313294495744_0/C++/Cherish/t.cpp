#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 1
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < n; ++i)
#define Rep(i,n) for(int i = 1; i <= n; ++i)

pair<string, string>p[20];
pair<ULL, ULL>x[20];
int val[1024*64], id[1024*64], ma[1024*64], pre[1024*64], s[100];
//set<ULL>ls[1024*64], rs[1024*64];

int get(int m, int n) {
	for(int k = 1; k < n; ++k) {
		int temp = k;
		while(temp) {
			++val[k]; temp -= temp & -temp;
		}
		++s[val[k]];
	}
	Rep(i, m) s[i] += s[i-1];
	for(int i = 1; i < n; ++i) id[s[val[i]]--] = i;
	for(int _ = 1; _ < n; ++_) {
		int k = id[_];
//		if(k == 62) {
//			puts("------------------");
//		}
		rep(i, m) if((1<<i) & k) {
			bool ls = false, rs = false;
			int temp = k ^ (1<<i);
			rep(j, m) if((1<<j) & temp) {
				if(x[i].first == x[j].first) ls = true;
				if(x[i].second == x[j].second) rs = true;
			}
			if(ls && rs) {
				if(ma[temp]+1 > ma[k]) ma[k] = ma[temp]+1, pre[k]=temp;
			}
			else if(ma[k] < ma[temp]) ma[k] = ma[temp], pre[k]=temp;
		}	
	}
//	int u = n-1;
//	while(u) {
//		cout << u << endl;
//		u = pre[u];
//	}
	return ma[n-1];
}

int main()
{
	int t, cas = 0;
	cin >> t;
	while(cas++ < t) {
		memset(val, 0, sizeof val);
		memset(id, 0, sizeof id);
		memset(ma, 0, sizeof ma);
		memset(s, 0, sizeof s);
		int n;
		cin >> n;
		rep(i, n) cin >> p[i].first >> p[i].second;
		rep(i, n) {
			ULL v = 0;
			rep(j, p[i].first.size()) {
				v = v * 173 + p[i].first[j];
			}
			x[i].first = v;
			v = 0;
			rep(j, p[i].second.size()) {
				v = v * 173 + p[i].second[j];
			}
			x[i].second = v;
		}
		printf("Case #%d: %d\n", cas, get(n, 1<<n));
	}
	return 0;
}

