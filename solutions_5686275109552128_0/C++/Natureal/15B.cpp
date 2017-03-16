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
const int MAXN = 1010;

int T,D;
int num[MAXN],num_st[MAXN];

int main(){
	freopen("B.out","w",stdout);
	int a,tmax = 0;
	scanf("%d",&T);
	FOR(tt,1,T){
		MEM(num,0);
		scanf("%d",&D);
		REP(i,D){
			scanf("%d",&a);
			num[a]++;
			tmax = max(tmax,a);
		}
		for(int i = 1; i <= tmax; ++i) num_st[i] = num[i];
		int ans = INF;
		for(int top = tmax; top >= 1; --top){
			if(top < tmax) memcpy(num,num_st,sizeof(num_st));
			int res = 0;
			for(int i = tmax; i >= 1; --i) if(num[i]){
				if(i > top){
					int cnt = i / top;
					if(i % top){
						cnt++;
						num[top] += (cnt - 1) * num[i];
						num[i % top] += num[i];
					}
					else num[top] += cnt * num[i];
					res += (cnt - 1) * num[i];
				}
				else{
					res += i;
					break;
				}
			}
			ans = min(ans,res);
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}
 
