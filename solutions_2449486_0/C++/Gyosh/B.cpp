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
int r,c;
int h[102][102];
int rp[102],cp[102];
bool rs[102][102],cs[102][102],ada[102];
bool ya;

int main(){
	scanf("%d", &nkasus);
	REP(jt,nkasus){
		RESET(ada,0);
	
		scanf("%d%d", &r,&c);
		REP(i,r){
			REP(j,c){
				scanf("%d", &h[i][j]);
				ada[h[i][j]] = 1;
			}
		}
		
		RESET(rs,0);
		REP(i,r){
			REP(j,c){
				rs[i][h[i][j]] = 1;
			}
		}
		
		RESET(cs,0);
		REP(j,c){
			REP(i,r){
				cs[j][h[i][j]] = 1;
			}
		}
		
		ya = 0;
		RESET(rp,-1);
		RESET(cp,-1);
		REP(k,101){
			if (ada[k]){
				REP(i,r){
					if (rs[i][k] && (rp[i] == -1)){
						//is it stripe?
						bool bs = 1;
						REP(j,c){
							if ((h[i][j] != k) && (cp[j] != h[i][j])){
								bs = 0;
								break;
							}
						}
						if (bs) rp[i] = k;
					}
				}
				
				REP(j,c){
					if (cs[j][k] && (cp[j] == -1)){
						//is it stripe?
						bool bs = 1;
						REP(i,r){
							if ((h[i][j] != k) && (rp[i] != h[i][j])){
								bs = 0;
								break;
							}
						}
						if (bs) cp[j] = k;
					}	
				}
			}
		}
		
		ya = 1;
		REP(i,r){
			if (rp[i] == -1){
				ya = 0;
				break;
			}
		}
		REP(j,c){
			if (cp[j] == -1){
				ya = 0;
				break;
			}
		}
		
		printf("Case #%d: %s\n", jt+1, ya ? "YES" : "NO");
	}
	
	return 0;
}
