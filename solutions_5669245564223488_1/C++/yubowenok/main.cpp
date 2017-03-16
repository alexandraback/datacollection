#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <cassert>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 100005
#define MOD 1000000007

int N;
string car[105];
bool ap[26];
bool contain[105][26];
ll ff[105];
ll cc[26][26], ac[26], ca[26];
int main(){
	ff[0] = 1;
	REP(i,1,105) ff[i] = ff[i-1]*i%MOD;
	int cs;
	cin >> cs;
	REP(csn,1,cs+1){
		cerr << csn << endl;
		printf("Case #%d: ", csn);
		cin >> N;
		FILL(ap,0);
		bool fail = 0;
		FILL(contain,0);
		REP(i,0,N){
			cin >> car[i];
			if(fail) continue;
			car[i] = car[i].substr(0, unique(car[i].begin(),car[i].end())-car[i].begin());
			int len = car[i].length();
			FILL(contain[i],0);
			REP(j,0,len) {
				int c = car[i][j]-'a';
				if(!contain[i][c]) contain[i][c] = 1;
				else {
					fail = 1;
					break;
				}
			}
			if(len>1 && car[i][0]==car[i][len-1]) {
				fail = 1;
				break;
			}
		}
		if(fail) {puts("0");continue;}
		REP(i,0,N){
			string &s = car[i];
			int len = s.length();
			REP(j,0,N){
				if(i==j) continue;
				
				REP(k,1,len-1){
					int c = s[k]-'a';
					if(contain[i][c] && contain[j][c]){
						fail = 1;
						break;
					}
				}
				if(fail)break;
			}
			if(fail)break;
		}
		if(fail) {puts("0");continue;}
		FILL(cc,0);
		REP(i,0,N){
			int len = car[i].length();
			int s = car[i][0]-'a', t = car[i][len-1] - 'a';
			cc[s][t]++;
		}
		REP(i,0,26){
			REP(j,0,26){
				if(j==i) continue;
				if(cc[i][j]>1){
					fail = 1;
					break;
				}
			}
		}
		if(fail) {puts("0");continue;}

		while(1){
			bool mod = 0;
			REP(x,0,26){
				REP(i,0,26){
					if(i==x) continue;
					REP(j,0,26){
						if(j==x || j==i) continue;

						if(cc[i][x] && cc[x][j]){
							//printf("%c %c %c\n", i+'a', x+'a', j+'a');
							cc[i][j] = ff[cc[x][x]];
							cc[i][x] = cc[x][j] = cc[x][x] = 0;
							mod = 1;
							break;
						}
						
					}
					if(mod) break;
				}
				if(mod) break;
			}
			if(!mod) break;
		}
		while(1){
			bool mod = 0;
			REP(x,0,26){
				REP(i,0,26){
					if(i==x) continue;
					if(cc[i][x] && cc[x][x]){
						//printf("%c %c\n", i+'a', x+'a');
						cc[i][x] *= ff[cc[x][x]];
						cc[i][x] %= MOD;
						cc[x][x] = 0;
						mod = 1;
					}
					if(mod)break;
					if(cc[x][i] && cc[x][x]){
						//printf("%c %c\n", x+'a', i+'a');
						cc[x][i] *= ff[cc[x][x]];
						cc[x][i] %= MOD;
						cc[x][x] = 0;
						mod = 1;
					}
					if(mod)break;
				}
				if(mod)break;
			}
			if(!mod)break;
		}
		REP(i,0,26){
			ll ax=0, xa=0;
			REP(j,0,26){
				if(j==i) continue;
				if(cc[i][j]) {
					ax ++;
				}
				if(cc[j][i]){
					xa ++;
				}
			}
			if(ax+xa>1){
				fail = 1;
				break;
			}
		}
		if(fail) {puts("0");continue;}
		ll ans = 1;
		int cnt = 0;
		REP(i,0,26){
			if(cc[i][i]){
				ans *= ff[cc[i][i]];
				ans %= MOD;
				cnt++;
			}
			REP(j,0,26){
				if(i==j) continue;
				if(cc[i][j]){
					ans *= cc[i][j];
					ans %= MOD;
					cnt ++;
				}
			}
		}
		ans *= ff[cnt];
		ans %= MOD;
		cout << ans << endl;
	}
	return 0;
}