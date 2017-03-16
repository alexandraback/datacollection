#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

ll B,M;
int T;

int main() {
	cin >> T;
	for (int cas=1;cas<=T;cas++) {
		cin >> B >> M;
		printf("Case #%d: ",cas);
		if (M<=(1ll<<(B-2))) {
			printf("POSSIBLE\n");
			vvi am(B,vi(B));
			for (int i=0;i<B;i++) for (int j=i+1;j+1<B;j++) am[i][j]=1;
			am[0][B-1]=1;M--;
			for (int i=1;i+1<B;i++) if ((1ll<<(i-1))&M) am[i][B-1]=1;
			for (int i=0;i<B;i++) {
				for (int j=0;j<B;j++) printf("%d",am[i][j]);
				printf("\n");
			}
		}
		else printf("IMPOSSIBLE\n");
	}
}
