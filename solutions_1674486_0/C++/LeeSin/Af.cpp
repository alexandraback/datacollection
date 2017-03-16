#include <cstdio>
#include <algorithm>
#include <vector>
#define N 1005
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
using namespace std;

int t, n, v, d[N][N], c;
bool y;

bool floyd(){
	FI(i, 1, n) FI(j, 1, n) if(d[j][i]) FI(k, 1, n){
		d[j][k] += d[j][i] * d[i][k];
		if(d[j][k] > 1) return 1;
	}
	return 0;
}

int main(){
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-out.txt", "w", stdout);
	
	scanf("%d", &t);
	
	FI(z, 1, t){
		scanf("%d", &n);
		
		FI(i, 1, n) FI(j, 1, n) d[i][j] = 0;
		
		FI(i, 1, n){
			scanf("%d", &v);
			while(v--) scanf("%d", &c), d[i][c] = 1;
		}
		
		printf("Case #%d: %s\n", z, floyd() ? "Yes" : "No");
	}
	
	scanf("\n");
}
