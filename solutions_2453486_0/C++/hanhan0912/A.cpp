/* hanhanw v1.1 */
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
// for Online Judge or Contests
#define MSET(x,y) memset(x,y,sizeof(x))
#define REP(x,y,z) for(int x=y; x<=z; x++)
#define FORD(x,y,z) for(int x=y; x>=z; x--)
#define FLST(x,y,z) for(int x=y; x; x=z[x])
#define SZ size
#define PB push_back

using namespace std;
//
typedef long long LL;
typedef unsigned long long uLL;
typedef long double LD;
// start here OAO~

char s[6][6];

void solve(){
	REP(i,1,4)
		scanf("%s", s[i]+1);
	int sign1, sign2;
	sign1 = sign2 = 0;
	REP(i,1,4){
		sign1 = sign2 = 1;
		REP(j,1,4){
			if (s[i][j] == 'O'){
				sign1 = 0;
			} else if (s[i][j] == 'X'){
				sign2 = 0;
			}
			if (s[i][j] == '.'){
				sign1 = sign2 = 0;
			}
		}
		if (sign1 || sign2)
			break;
		sign1 = sign2 = 1;
		REP(j,1,4){
			if (s[j][i] == 'O'){
				sign1 = 0;
			} else if (s[j][i] == 'X'){
				sign2 = 0;
			}
			if (s[j][i] == '.'){
				sign1 = sign2 = 0;
			}
		}
		if (sign1 || sign2)
			break;
	}
	if (!(sign1 || sign2)){
		sign1 = sign2 = 1;
		REP(i,1,4){
			if (s[i][i] == 'O'){
				sign1 = 0;
			} else if (s[i][i] == 'X'){
				sign2 = 0;
			}
			if (s[i][i] == '.'){
				sign1 = sign2 = 0;
			}
		}
	}
	if (!(sign1 || sign2)){
		sign1 = sign2 = 1;
		REP(i,1,4){
			if (s[i][5-i] == 'O'){
				sign1 = 0;
			} else if (s[i][5-i] == 'X'){
				sign2 = 0;
			}
			if (s[i][5-i] == '.'){
				sign1 = sign2 = 0;
			}
		}
	}
	if (sign1)
		puts("X won");
	else if (sign2)
		puts("O won");
	else {
		int cnt=0;
		REP(i,1,4)
			REP(j,1,4)
				if (s[i][j] == '.')
					cnt++;
		if (cnt)
			puts("Game has not completed");
		else
			puts("Draw");
	}
}


int main(){
//	freopen("A-small-attempt0.in", "r",stdin);
//	freopen("A.out", "w", stdout);
	int nT; scanf("%d", &nT);
	REP(i,1,nT){
		printf("Case #%d: ", i);
		solve();
	}
	
	return 0;
}
