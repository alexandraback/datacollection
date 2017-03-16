#include <iostream>
#include <string.h>
#include <string>
#include <cstdio>
#include <math.h>

#define REP(i,a,b) for(int i=a;i<=b;i++)
#define sf scanf
#define pf printf
#define ll long long 

using namespace std;
const int MAXN = 105;
const int MOD = 1000000007;

int n;
char s[MAXN][MAXN];
int map[MAXN][MAXN];
int cmap[MAXN][MAXN];
int sum[MAXN];
bool visited[MAXN];

int getans(int n){
	int res = 1;
	REP(i,1,n){
		res *= i;
		res %= MOD;
	}
	return res;
}

struct NODE{
	int from , to;
}node[MAXN];

int main(){

	int t; sf("%d",&t);
	REP(it,1,t){
		sf("%d",&n);
		REP(i,1,n) sf("%s" , s[i]);
		
		REP(i,1,n) REP(j,1,n) map[i][j] = 0;
		REP(i,1,n) REP(j,1,n)
			if ( s[i][0]==s[j][strlen(s[j])-1] ) map[i][j] = 1;
		
		int ans = 0;
		REP(i,1,n) {
			int len = strlen(s[i]);
			REP(j,0,len-1) REP(k,j+2,len-1){
				if ( s[i][k]==s[i][j]&&s[i][k-1]!=s[i][k] ) ans = -1;
			}
		}
		
		if ( ans>=0 ){
			
			memset(cmap,0,sizeof(cmap));
			REP(i,1,n){
				int len = strlen(s[i]);
				REP(j,0,len-2){
					int a1 = s[i][j]-'a' , a2 = s[i][j+1]-'a';
					if ( a1==a2 ) continue;
					if ( cmap[a1][a2]>0 ) {
						ans = -1 ; break;
					}
					cmap[a1][a2] = 1;
				}
				if ( ans<0 ) break;
			}
			REP(i,1,30) sum[i] = 0;
			REP(i,1,n) if ( s[i][0]==s[i][strlen(s[i])-1] )
				sum[s[i][0]-'a']++;
			
			bool has[35];
			memset(has,false,sizeof(has));
			REP(i,1,n){
				int len = strlen(s[i]);
				REP(j,0,len-1) has[s[i][j]-'a'] = true;
			}
			
			if ( ans>=0 ){
				ans = 1;
				REP(i,0,30) if ( sum[i]>0 ) {
					ans*=getans(sum[i]);
					ans %= MOD;
				}
				int cnt = 0;
				REP(i,0,30) visited[i] = false;
				REP(i,0,26)if (has[i]){
					if (!visited[i]) { cnt++; }
					visited[i] = true;
					REP(j,0,26){
						if ( cmap[i][j]>0 ){
							if ( !visited[j] ) visited[j]=true;
						}
					}
				}
				ans *= getans(cnt);
				ans %= MOD;
			}
		}
		pf("Case #%d: ",it);
		if ( ans<0 ) ans = 0; pf("%d\n" ,ans);
	}

	return 0;
}