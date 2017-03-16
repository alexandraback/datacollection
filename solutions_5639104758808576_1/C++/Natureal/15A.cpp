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

#define MEM(a,b) memset(a,b,sizeof(a))
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int T,N;
char s[110];

int main(){
	freopen("15A.out","w",stdout);
	scanf("%d",&T);
	FOR(tt,1,T){
		scanf("%d",&N);
		scanf("%s",s);
		int sum = 0;
		int ans = 0;
		for(int i = 0; i <= N; ++i){
			if(sum < i){
				ans += i - sum;
				sum = i;
			}
			sum += s[i] - '0';
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}


