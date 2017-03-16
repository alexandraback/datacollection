#include <cstdio>
#include <algorithm>
#define N 52
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t, n, m, c, x[N];
char s[N][N];

void solve(){
	scanf("%d %d %d", &n, &m, &c);
	fi(i, 0, n) fi(j, 0, m) s[i][j] = '.';
	
	bool ok = 0;
	
	if(m == 1){
		fi(i, 0, c) s[i][0] = '*';
		s[n - 1][0] = 'c';
		ok = 1;
	}else if(n == 1){
		fi(i, 0, c) s[0][i] = '*';
		s[0][m - 1] = 'c';
		ok = 1;
	}else if(n * m - c == 1){
		fi(i, 0, n) fi(j, 0, m) s[i][j] = '*';
		s[0][0] = 'c';
		ok = 1;
	}else{
		FI(i, 0, n - 2){
			int d = c - i * m;
			if(d < 0) break;
			if((n - i) * (m - 2) < d) continue;
			
			fi(k, 0, i) x[n - k - 1] = m;
			
			fi(j, 0, n - i - 2){
				x[n - i - j - 1] = min(m - 2, d);
				if(j == n - i - 3 && (x[n - i - j - 1] + d) % 2) x[n - i - j - 1]--;
				d -= x[n - i - j - 1];
			}
			
			if(d % 2) continue;
			x[0] = x[1] = d / 2;
			if(n > 2 && x[1] > x[2]) continue;
			
			ok = 1;
			break;
		}
		
		if(ok){
			s[0][m - 1] = 'c';
			fi(i, 0, n) fi(j, 0, x[i]) s[i][j] = '*';
		}
	}
	
	if(ok){
		int cnt = 0;
		fi(i, 0, n){
			fi(j, 0, m){
				printf("%c", s[i][j]);
				if(s[i][j] == '*') cnt++;
			}
			puts("");
		}
		if(cnt != c){
			printf("WA %d %d %d\n", n, m, c);
		}
	}else puts("Impossible");
	
}

int main(){
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-small-attempt1.out", "w", stdout);
	
	scanf("%d", &t);
	FI(z, 1, t){
		printf("Case #%d:\n", z);
		solve();
	}
	scanf("\n");
}
