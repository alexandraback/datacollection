#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 1020304
#define MaxNode 1020304
#define MD 1000000007

int end = 0;
void win(char c) {
	printf("%c won\n",c); end = true;
}

char s[5][5];
int main() {
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int T; cin >> T;
	For(TTT,1,T) { scanf(" "); printf("Case #%d: ",TTT);
				if(TTT==5){
					int z=TTT;
				}
		For(i,0,3) scanf("%s",s[i]);
		int cnt = 0;
		For(i,0,3) For(j,0,3) if (s[i][j] == '.') ++cnt; end = false ;
		For(i,0,3) {
			char fl = 2;
			For(j,0,3) {
				if (fl != 2 && fl != s[i][j] && s[i][j] != 'T') { fl = 'F'; break ; }
				if (s[i][j] != 'T') fl = s[i][j];
			}
			if (fl == 'X' || fl == 'O') { win(fl); break ; }
		}
		if (!end) For(i,0,3) {
			char fl = 2;
			For(j,0,3) {
				if (fl != 2 && fl != s[j][i] && s[j][i] != 'T') { fl = 'F'; break ; }
				if (s[j][i] != 'T') fl = s[j][i];
			}
			if (fl == 'X' || fl == 'O') { win(fl); break ; }
		}
			char fl = 2;
			if (!end) {
				For(j,0,3) {
					if (fl != 2 && fl != s[j][j] && s[j][j] != 'T') { fl = 'F'; break ; }
					if (s[j][j] != 'T') fl = s[j][j];
				}
				if (fl == 'X' || fl == 'O') { win(fl); }
			}
			fl = 2;
			if (!end) {
				For(j,0,3) {
					if (fl != 2 && fl != s[j][3 - j] && s[j][3 - j] != 'T') { fl = 'F'; break ; }
					if (s[j][3 - j] != 'T') fl = s[j][3 - j];
				}
				if (fl == 'X' || fl == 'O') { win(fl); }
			}
			
		if (!end) {
			if (cnt == 0) puts("Draw"); else puts("Game has not completed");
		}
	}
	return 0;
}

