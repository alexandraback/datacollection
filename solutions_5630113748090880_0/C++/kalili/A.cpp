#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
#define X first
#define Y second

using namespace std;


const int N = 55;
map<int, int> mp;
int main()
{
	int cas = 0;
	freopen("B.in","r",stdin);
    freopen("B.txt","w",stdout);
	int T;
	cin >> T;
	while(T --) {
		int n;
		cin >> n;
		mp.clear();
		for(int i = 1; i <= 2 * n - 1; i ++)
			for(int j = 1; j <= n; j ++) {
				int num;
				scanf("%d", &num);
				mp[num] ++;
			}
		printf("Case #%d:", ++ cas);
		for(auto cur: mp) {
			if(cur.Y % 2) printf(" %d", cur.X);
		}
		puts("");
	}
}
