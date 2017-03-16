#include <cstdio>
#include <algorithm>
#define N 4
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int z;
char b[N][N + 1], buf[N + 1];

void check(int &w){
	int a = 0, b = 0;
	fi(i, 0, N){
		if(buf[i] == 'O') a++;
		else if(buf[i] == 'X') b++;
		else if(buf[i] == 'T') a++, b++;
	}
	if(a == 4) w = 1;
	else if(b == 4) w = 2;
}

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("lout.txt", "w", stdout);
	scanf("%d", &z);
	FI(t, 1, z){
		fi(i, 0, N) scanf("%s", b[i]);
		
		int w = 0, d = 0;
		fi(i, 0, N) fi(j, 0, N) d += b[i][j] != '.';
		
		fi(i, 0, N){
			fi(j, 0, N) buf[j] = b[i][j];
			check(w);
			fi(j, 0, N) buf[j] = b[j][i];
			check(w);
		}
		
		fi(i, 0, N) buf[i] = b[i][i];
		check(w);
		fi(i, 0, N) buf[i] = b[i][N - i - 1];
		check(w);
		
		printf("Case #%d: ", t);
		if(w == 1) puts("O won");
		else if(w == 2) puts("X won");
		else if(d == 16) puts("Draw");
		else puts("Game has not completed");
	}
}
