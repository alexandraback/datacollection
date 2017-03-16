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

char s[10];
bool vis[10];

int main(){
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int T, i0;
	scanf("%d", &T);
	for(i0 = 1; i0 <= T; i0++){
		int n, m;
		int i, j, k;
		scanf("%d", &n);
		if(n == 0){
			printf("Case #%d: INSOMNIA\n", i0);
			continue;
		}
		memset(vis, false, sizeof vis);
		m = n;
		while(true){
			sprintf(s, "%d", m);
			for(i = 0; s[i]; i++)
				vis[s[i]-'0'] = true;
			for(i = 0; i < 10; i++)
				if(!vis[i])
					break;
			if(i == 10)
				break;
			m += n;
		}
		printf("Case #%d: %d\n", i0, m);
	}
	return 0;
}
