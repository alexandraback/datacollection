#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<float.h>
using namespace std;
#define PII pair<int,int>
#define LL long long
#define X first
#define Y second
#define PB push_back
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FOE(i,a,b) for (int i=(a);i<=(b);i++)
#define REP(i,n) FOR(i,0,n)
int n, m;
LL r, t;
int main(){
	int T;
	scanf("%d", &T);
	FOE(cc,1,T){
		int ans = 0;
		scanf("%lld%lld", &r, &t);
		while( (2 * r + 1) <= t ){
			ans++;
			t -= 2 * r + 1;
			r += 2;
		}
		printf("Case #%d: %d\n", cc, ans);
	}
	return 0;
}

