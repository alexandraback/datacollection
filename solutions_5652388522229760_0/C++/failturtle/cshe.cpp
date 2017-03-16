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

int main() {
	freopen("cshe.in","r",stdin);
	freopen("cshe.out","w",stdout);
	int t;
	scanf("%d\n", &t);
	for (int _ = 1; _ <= t; _++) {
		printf("Case #%d: ", _);
		ll n;
		scanf("%lld",&n);
		if (n == 0) {
			puts("INSOMNIA");
			continue;
		}
		int asdf[10];
		memset(asdf,0,sizeof(asdf));
		bool good = 1;
		fo(i,1,123456) {
			good = 1;
			string s = to_string(n*i);
		//	cout << s << endl;
			for (auto c : s) asdf[c-'0']++;
			fo(j,0,10) {
				if (asdf[j] == 0) {
				//	printf("%d is bad!\n",j);
					good = 0;
					break;
				}
			}
			if (good) {
				cout << s << endl;
				break;
			}
		}
		if (!good) {
			puts("INSOMNIA");
		}
	}
	
	return 0;
}
