#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;

int T;
char s[100];
ll N,RN;

int main(){
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		scanf("%s",s + 1);
		int len = strlen(s + 1);
		ll bot = 1,top = 9;
		N = RN = 0;
		for(int i = 1; i <= len; ++i){
			N = N * 10LL + (s[i] - '0');
			bot = bot * 10LL + 9LL;
		}
		for(int i = len; i >= 1; --i){
			RN = RN * 10LL + (s[i] - '0');
			top = top * 10LL + 9LL;
		}
		top -= 8LL;
		ll ans = 0;
		ans += (len - 1) * 2 + 1;
		ll ans1 = ans,ans2 = ans,v1,v2;
		
		if(N >= bot) ans1++;
		if(N >= top) ans1++;
		if(RN >= bot) ans2++;
		if(RN >= top) ans2++;
		ans2 += top - RN + 1;
		printf("%lld\n",ans1 < ans2 ? ans1 : ans2);
	}
	return 0;
}


