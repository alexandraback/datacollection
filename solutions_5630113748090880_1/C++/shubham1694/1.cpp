#include <bits/stdc++.h>

using namespace std;

#define sd(x) scanf("%d", &x)
#define boost ios_base::sync_with_stdio(false);
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define f first
#define s second

typedef pair<int, int> pii;
typedef long long ll;

const int mod = 1000000007;
const int inf = 50000000;
const int maxn = 3010;

int cnt[maxn];
vector<int> ans;

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	int t, cn = 1, n, i, j, val;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		ans.clear();
		for(i=0; i<maxn; i++)
			cnt[i] = 0;
		for(i=1; i<=2*n-1; i++){
			for(j=1; j<=n; j++){
				scanf("%d", &val);
				cnt[val]++;
			}
		}
		for(i=0; i<maxn; i++){
			if(cnt[i]&1)
				ans.pb(i);
		}
		printf("Case #%d:", cn++);
		for(auto it:ans)
			printf(" %d", it);
		printf("\n");
	}
	
	return 0;
}
