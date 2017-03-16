#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
using namespace std;    
const int N = int(3e5), mod = int(1e9) + 7;

bool a[12];

bool check(ll n){
	while(n > 0){
		a[n % 10] = 1;
		n /= 10;
	}
	for(int i=0;i<10;i++) if(!a[i]) return 0;
	return 1;
}

ll solve(int n){
	if(n == 0) return -1;
	ll res = n;
	memset(a,0,sizeof(a));
	while(true){
		if(check(res)) return res;
		res += n;
	}
}

int main () {
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int t;
	int n;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		scanf("%d",&n);
		ll res = solve(n);
		printf("Case #%d: ",tt);
		if(res == -1){
			puts("INSOMNIA");
		}
		else printf("%lld\n",res);
	}

return 0;
}