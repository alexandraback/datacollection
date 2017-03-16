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

int main(){
	int t;
	char c;
	scanf("%d", &t);
	REP(cas, t){
		int ans = 0;
		int tot = 0;
		int smax;
		scanf("%d", &smax);
		REP(i, smax+1){
			scanf(" %c", &c);
			if(c > '0'){
				ans += max(0,i-tot);
				tot += max(0,i-tot);
				tot += c - '0';
			}
		}


		printf("Case #%d: %d\n", cas+1, ans);
	}
	return 0;
}