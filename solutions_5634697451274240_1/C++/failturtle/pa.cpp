#include <bits/stdc++.h>

#define sz(z) (int)z.size()
#define fo(i,a,b) for (auto (i) = (a); (i) < (b); (i)++)
#define mp make_pair
#define pb push_back

using namespace std;

#define DEBUG

#ifdef DEBUG
#define D(x...) printf(x)
#else
#define D(x...) 
#endif

typedef long long ll;
typedef pair<int,int> ii;

int seen[1<<12];
int cache[1<<12];

int n;
int dp (int at) {
	if (at == (1<<n)-1) return 0;
	if (seen[at]) return cache[at];
	if (seen[at] == 1) return 123123;
	int ar[123];
	seen[at] = 1;
	fo(i,0,n) {
		ar[i] = (((1<<i)&at) > 0) ? 1 : 0;
	}
	cache[at] = 123123123;
	int &ret = cache[at];
	ret = 123123;
	fo(i,0,n) {
		// swap the first i bits
		int nxt = 0;
		for (int j = i; j >= 0; j--) {
			nxt += (1<<(i-j)) * (1-ar[j]);
		}
		for (int j = i+1; j < n; j++) {
			nxt += (1<<(j)) * (ar[j]);
		}
	//	cout << "after flipping first " << i << " bits:";
	//	cout << bitset<10>(at) << ' ' << bitset<10>(nxt) << endl;
		ret = min(ret, dp(nxt)+1);
	}
	seen[at] = 2;
	cache[at] = ret;
	return ret;
}

int main() {
	freopen("pa.in","r",stdin);
	int t;
	cin >> t;
	for (int _ = 1; _ <= t; _++) {
		cout << "Case #" << _ << ": ";
		string s;
		cin >> s;
		n = sz(s);
		/*
		   int at = 0;
		   fo(i,0,n) {
		   at += (1<<i) * (s[i] == '+' ? 1 : 0);
		   }
		   cout << dp(at) << endl;
		   cout << bitset<10>(at) << ' ' << s << endl;
		 */
		bool changed = 1;
		int ans = 0;
		while (changed) {
			changed = 0;
			fo(i,0,n) {
				char at = s[i];
				while (i < n && s[i] == at) {
					i++;
				}
				if (i == n && s[i-1] == '+') {
					break;
				}
				if (i == n && s[i-1] == '-') {
					ans++;
					break;
				}
				while (--i >= 0) {
					if (s[i] == '+')s[i] = '-';
					else s[i] = '+';
				}
				ans++;
				changed = 1;
				break;
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
