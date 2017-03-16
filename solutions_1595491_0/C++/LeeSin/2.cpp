#include <cstdio>
#include <algorithm>
#include <vector>
#define N 105
#define fi(a, b, c) for(int a = b; a < c; a++)
#define fd(a, b, c) for(int a = b; a > c; a--)
#define FI(a, b, c) for(int a = b; a <= c; a++)
#define FD(a, b, c) for(int a = b; a >= c; a--)
using namespace std;

int t, n, s, p, x, A;

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B.out", "w", stdout);
	
	scanf("%d", &t);
	FI(i, 1, t){
		A = 0;
		scanf("%d %d %d", &n, &s, &p);
		
		while(n--){
			scanf("%d", &x);
			if(x + 2 >= 3 * p) A++;
			else if(x && s && x + 4 >= 3 * p){
				s--;
				A++;
			}
		}
		
		printf("Case #%d: %d\n", i, A);
	}
	
	scanf("\n");
}
