// Template
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define fi first
#define sc second
#define MP make_pair
#define pb push_back
#define PI acos(-1.0) //alternative #define PI (2.0 * acos(0.0))
#define vi vector<int>
#define vii vector<pii>
#define ALL(c) (c).begin(), (c).end()
#define RESET( c,a ) memset( (c), a, sizeof(c) )
#define REP( a,b,c ) for ( int a=b, _c=c; a<_c; ++a )
#define RED( a,b,c ) for ( int a=b, _c=c; a>=_c; --a )
#define REPI( it, c ) for ( __typeof( (c).begin() ) it=(c).begin(); it!=(c).end(); ++it )

const int big = 1000000000;
const double INF = 1e9;
const double EPS = 1e-9;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;

bool check(char a, char b, char c, char d, char chk){
	if(a!=chk && a!='T') return 0;
	if(b!=chk && b!='T') return 0;
	if(c!=chk && c!='T') return 0;
	if(d!=chk && d!='T') return 0;
	return 1;
}


int main(){
	int tc;
	scanf("%d",&tc);
	REP(tci,1,tc+1){
		char table[4][4];
		RESET(table,'.');
		char c;
		int ct = 0;
		while(scanf("%c",&c)!=EOF && ct<16){
			if(c=='X' || c=='.' || c=='O' || c=='T'){
				int i = ct/4; 
				int j = ct%4;
				table[i][j] = c;
				++ct;
			}
		}
		bool xwon = 0;
		bool owon = 0;
		bool draw = 0;
		bool notc = 0;
		
		REP(i,0,4){
			if(check(table[i][0],table[i][1],table[i][2],table[i][3],'O')){
				owon = true;
				break;
			}
			if(check(table[i][0],table[i][1],table[i][2],table[i][3],'X')){
				xwon = true;
				break;
			}
			if(check(table[0][i],table[1][i],table[2][i],table[3][i],'O')){
				owon = true;
				break;
			}
			if(check(table[0][i],table[1][i],table[2][i],table[3][i],'X')){
				xwon = true;
				break;
			}
		}
		
		if(check(table[0][0],table[1][1],table[2][2],table[3][3],'O')){
			owon = true;
		}
		
		if(check(table[0][0],table[1][1],table[2][2],table[3][3],'X')){
			xwon = true;
		}
		
		if(check(table[3][0],table[2][1],table[1][2],table[0][3],'O')){
			owon = true;
		}
		
		if(check(table[3][0],table[2][1],table[1][2],table[0][3],'X')){
			xwon = true;
		}
		
		if(!xwon && !owon){
			bool ret = 0;
			REP(i,0,4){
				REP(j,0,4){
					if(table[i][j]=='.'){
						ret = 1;
					}
				}
			}
			if(ret) notc=1; else draw = 1;
		}
		
		
		printf("Case #%d: ",tci);
		if(xwon) printf("X won\n");
		else if(owon) printf("O won\n");
		else if(draw) printf("Draw\n");
		else if(notc) printf("Game has not completed\n");
	}
	return 0;
}
