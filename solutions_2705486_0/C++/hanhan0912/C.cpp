/* hanhanw v1.2 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
// for Online Judge or Contests
#define MSET(x,y) memset(x,y,sizeof(x))
#define REP(x,y,z) for(int x=y; x<=z; x++)
#define FORD(x,y,z) for(int x=y; x>=z; x--)
#define FLST(x,y,z) for(int x=y; x; x=z[x])
#define FOR(x,y) for(__typeof(y.begin())x=y.begin();x!=y.end();x++)
#define SZ size
#define PB push_back

using namespace std;
//
typedef long long LL;
typedef unsigned long long uLL;
typedef long double LD;
// start here OAO~

const int INF = 2147483647>>1;

int dp[60],done[60],cp[60][60];
int len=0;
char s[53];
vector<string> vc[12];

inline int abs(int a){return a >= 0 ? a : -a; }
inline int min(int x, int y){ return x < y ? x : y; }
inline int calc(int x, int y, char str[]){
	if (cp[x][y] != -1) return cp[x][y];
	int res=INF;
	int l=strlen(str),tmp;
	for (int i=0; i<(int)vc[l].SZ();i++){
		tmp=0;
		REP(j,0,l-1){
			if (vc[l][i][j] != str[j]){
				if (abs(vc[l][i][j]-str[j]) <= 4){
					tmp=INF;
					break;
				}
				tmp++;
			}
		}
		res = min(res,tmp);
	}
	cp[x][y]=res;
	return res;
}
int f(int cur){
	if (cur >= len) return 0;
	if (done[cur]) return dp[cur];
	done[cur] = 1;
	dp[cur]=INF;
	int ed=min(len-1,cur+9);
	int pos=0;
	char s2[50];
	REP(i,cur,ed){
		s2[pos++] = s[i];
		s2[pos]=0;
		if (f(i+1) >= dp[cur])
			continue;
		cp[cur][i] = calc(cur,i,s2);
		dp[cur] = min(dp[cur], f(i+1) + cp[cur][i]);
		
	}
	return dp[cur];
}
void solve(int T){
	MSET(cp,-1);
	MSET(done,0);
	scanf("%s", s);
	len=strlen(s);
	printf("Case #%d: %d\n", T, f(0));
}
int main(){
	FILE *fin;
	fin = fopen("garbled_email_dictionary.txt", "r");
	while (fscanf(fin,"%s", s) != EOF){
		len = (int)strlen(s);
		vc[len].PB(string(s));
	}
	int nT; scanf("%d", &nT);
	REP(i,1,nT)
		solve(i);
	return 0;
}
