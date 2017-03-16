#include <bits/stdc++.h>
using namespace std;

#define rREP(i,n) for(int i = (n)-1; i >= 0; i--)
#define REP(i,n) for(int i = 0; i < (n); i++)
#define rFOR(i,a,b) for(int i = (b); i > (a); i--)
#define FOR(i,a,b) for(int i = (a); i < (b); i++)

typedef long long lint;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> vvi;

int v[1200];

int divide(int a, int b){
	int ret = a/b;
	if(b*ret < a)
		ret++;
	return ret;
}

int main(){
	int t,d;
	int tot, num;
	scanf("%d", &t);
	REP(cas, t){
		int ans = 1000;
		scanf("%d", &d);
		REP(i, d){
			scanf("%d", &num);
			v[i] = num;
		}
		for(int wait = 1; wait <= 1000; wait++){
			int divisions = 0;
			REP(i, d){
				divisions += divide(v[i], wait) - 1;
			}
			ans = min(ans, wait+divisions);
		}
		printf("Case #%d: %d\n", cas+1, ans);
	}
	return 0;
}