

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

int T,v[20] = {0,1,10,29,138,337,1436,3435,14434,34433,
	144432,344431,1444430,3444429,14444428};
char s[100];
ll N,RN;

int main(){
	freopen("A2.out","w",stdout);
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
       	scanf("%lld",&N);
		printf("Case #%d: ",tt); 
		if(N <= 20){
            printf("%lld\n",N);
            continue;
        }
		N--;
		ll tN = N;
		int len = 0;
		for(int i = 1; tN; ++i,++len){
			s[i] = tN % 10 + '0';
			tN /= 10;
		}
		for(int i = 1; i <= len / 2; ++i)
			swap(s[i],s[len - i + 1]);
		RN = s[1] - '0';
		RN--;
		for(int i = 2; i <= len; ++i)
			RN = RN * 10LL + (s[i] - '0');
		//for(int i = 1; i <= len; ++i)
		//	printf("%c",s[i]);
		//puts("");
		ll ans = v[len];
		ll res = v[len] + RN;
		int mid = len / 2;
		ll tmp = 0;
		for(int i = mid; i >= 1; --i)
			tmp = tmp * 10LL + (s[i] - '0');
		ans += tmp + 1;
		tmp = 0;
		for(int i = mid + 1; i <= len; ++i)
			tmp = tmp * 10LL + (s[i] - '0');
		ans += tmp - 1;
		printf("%lld\n",min(ans + 1,res + 1));
	}
	return 0;
}



