#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <cmath>

#define S(x) scanf("%d",&x)
#define P(x) printf("%d\n",x)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
using namespace std;

typedef long long int LL;
typedef vector<int > VI;

int main() {
	int T;
	int c=0;
	char s[4][4],a[4][4];
	S(T);
	while(T--) {
		int flag;
		c++;
		rep(i,0,4) scanf("%s",s[i]);
		
		rep(i,0,4) rep(j,0,4) {
			if(s[i][j] == 'T') a[i][j] = 'X';
			else a[i][j] = s[i][j];
		}
		
		flag=0;
		rep(i,0,4) {
			if(a[i][0] == 'X' && a[i][1] == 'X' && a[i][2] == 'X' && a[i][3] == 'X') {
				printf("Case #%d: X won\n",c);flag=1;
				break;
			}
			if(a[0][i] == 'X' && a[1][i] == 'X' && a[2][i] == 'X' && a[3][i] == 'X') {
				printf("Case #%d: X won\n",c);flag=1;
				break;
			}
		}
		if(flag) continue;
		
		if(a[0][0] == 'X' && a[1][1] == 'X' && a[2][2] == 'X' && a[3][3] == 'X') {
			printf("Case #%d: X won\n",c);
			continue;
		}
		
		if(a[0][3] == 'X' && a[1][2] == 'X' && a[2][1] == 'X' && a[3][0] == 'X') {
			printf("Case #%d: X won\n",c);
			continue;
		}
		
		
		
		rep(i,0,4) rep(j,0,4) {
			if(s[i][j] == 'T') a[i][j] = 'O';
			else a[i][j] = s[i][j];
		}
		
		flag=0;
		rep(i,0,4) {
			if(a[i][0] == 'O' && a[i][1] == 'O' && a[i][2] == 'O' && a[i][3] == 'O') {
				printf("Case #%d: O won\n",c);flag=1;
				break;
			}
			if(a[0][i] == 'O' && a[1][i] == 'O' && a[2][i] == 'O' && a[3][i] == 'O') {
				printf("Case #%d: O won\n",c);flag=1;
				break;
			}
		}
		if(flag) continue;
		
		if(a[0][0] == 'O' && a[1][1] == 'O' && a[2][2] == 'O' && a[3][3] == 'O') {
			printf("Case #%d: O won\n",c);
			continue;
		}
		
		if(a[0][3] == 'O' && a[1][2] == 'O' && a[2][1] == 'O' && a[3][0] == 'O') {
			printf("Case #%d: O won\n",c);
			continue;
		}
		
		flag=0;
		rep(i,0,4) {
			rep(j,0,4) if(s[i][j] == '.') {
				flag=1;
				printf("Case #%d: Game has not completed\n",c);
				break;
			}
			if(flag) break;
		}
		
		if(flag) continue;
		
		printf("Case #%d: Draw\n",c);
	}
	return 0;
}
