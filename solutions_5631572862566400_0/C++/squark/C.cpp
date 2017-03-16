#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

const int MAXN = 1123;

int a[MAXN];
int f[MAXN];
int deg[MAXN];
bool vis[MAXN];

int main(){
#ifdef LOCAL
	freopen("C-small-attempt0.in", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int T, i0;
	scanf("%d", &T);
	for(i0 = 1; i0 <= T; i0++){
		printf("Case #%d:", i0);
		int n;
		int i, j, k;
		memset(f, 0, sizeof f);
		memset(deg, 0, sizeof deg);
		memset(vis, 0, sizeof vis);
		scanf("%d", &n);
		for(i = 0; i < n; i++){
			scanf("%d", &a[i]);
			a[i]--;
			deg[a[i]]++;
		}
		while(true){
			bool flag = false;
			for(i = 0; i < n; i++)
				if(!vis[i] && deg[i] == 0){
					vis[i] = true;
					f[a[i]] = max(f[a[i]], f[i]+1);
					deg[a[i]]--;
					flag = true;
				}
			if(!flag)
				break;
		}
		int ans = 0;
		for(i = 0; i < n; i++)
			if(!vis[i] && a[a[i]] == i){
				vis[i] = true;
				vis[a[i]] = true;
				ans += 2 + f[i] + f[a[i]];
			}
		for(i = 0; i < n; i++){
			if(!vis[i]){
				j = i;
				k = 0;
				do{
					j = a[j];
					vis[j] = true;
					k++;
				}while(j != i);
				ans = max(ans, k);
			}
		}
		printf(" %d\n", ans);
	}
	return 0;
}
