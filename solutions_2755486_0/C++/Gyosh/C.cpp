#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <map>

#define REP(a,b) for (int a=0; a<b; a++)
#define FOR(a,b,c) for (int a=b; a<=c; a++)
#define FORD(a,b,c) for (int a=b; a>=c; a--)
#define RESET(a,b) memset(a, b, sizeof a)

#define INF 1023123123
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define PII pair<int,int> 
#define PDD pair<double,double>

#define __ puts("")
using namespace std;

int nkasus;
int wol[1000001];
int n,num[11],d[11],a[11],b[11],s[11],dd[11],dp[11],ds[11];

int main(){
	scanf("%d", &nkasus);
	REP(jt,nkasus){
		scanf("%d", &n);
		REP(i,n){
			scanf("%d%d%d%d%d%d%d%d",&d[i], &num[i], &a[i], &b[i], &s[i], &dd[i], &dp[i], &ds[i]);
			
			a[i] = a[i]*2 + 500000;
			b[i] = b[i]*2 + 500000; 
		}
		
		RESET(wol,0);
		
		int ans = 0;
		REP(h,676061){
			vector<pair<PII,int> > upd;
			
			REP(i,n){
				if (h >= d[i] && (h - d[i]) % dd[i] == 0){
					//today attack?				
					int th = (h-d[i])/dd[i];
					
					if (th+1 <= num[i]){
						int pow = s[i] +  th*ds[i];
						int ra = a[i] + dp[i] * th * 2;
						int rb = b[i] + dp[i] * th * 2;
						
						//printf("%d %d serang %d %d, %d\n",h, i+1, (ra-500000)/2, (rb-500000)/2, pow);
						
						int suc = 0;
						FOR(j,ra,rb){
							if (wol[j] < pow){
								suc = 1;
							}
						}
						
						if (suc){
							ans++;
							upd.PB(MP(MP(ra,rb),pow));
						}
					}					
				}
			}
			
			REP(i,upd.size()){
				FOR(j,upd[i].F.F, upd[i].F.S){
					wol[j] = max(wol[j], upd[i].S);
				}
			}
		}
		
		printf("Case #%d: %d\n", jt+1, ans);
	}
	
	return 0;
}
