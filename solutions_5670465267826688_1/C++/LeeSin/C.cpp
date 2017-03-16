#include <cstdio>
#include <algorithm>
#define N 10005
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t, n, p[N];
long long m;
bool u[12];
int mat[4][4] = {
1, 2, 3, 4,
2, -1, 4, -3,
3, -4, -1, 2,
4, 3, -2, -1
};
char s[N];

int mul(int a, int b){
	int ret = 1;
	if(a < 0){
		a = -a;
		ret *= -1;
	}
	if(b < 0){
		b = -b;
		ret *= -1;
	}
	return ret * mat[a - 1][b - 1];
}

void solve(int z){
	scanf("%d %I64d %s", &n, &m, s);
	p[0] = 1;
	fi(i, 0, n){
		int v = s[i] - 'i' + 2;
		p[i + 1] = mul(p[i], v);
	}
	
	int found = 0, tot = 1, cnt = 0;
	fi(i, 0, m){
		FI(j, 1, n){
			if(!found && mul(tot, p[j]) == 2){
				found = 1;
				cnt = 0;
			}
			if(found == 1 && mul(tot, p[j]) == 4) found = 2;
		}
		tot = mul(tot, p[n]);
		cnt++;
		if(cnt > 4) break;
	}
	
	if(found == 2){
		tot = 1;
		fi(i, 0, m % 4) tot = mul(tot, p[n]);
		if(tot == -1) found++;
	}
	
	printf("Case #%d: %s\n", z, found == 3 ? "YES" : "NO");
}

int main(){
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w+", stdout);
	scanf("%d", &t);
	FI(z, 1, t) solve(z);
	scanf("\n");
}
