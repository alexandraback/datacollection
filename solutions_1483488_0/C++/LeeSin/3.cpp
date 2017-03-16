#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#define N 7
#define fi(a, b, c) for(int a = b; a < c; a++)
#define fd(a, b, c) for(int a = b; a > c; a--)
#define FI(a, b, c) for(int a = b; a <= c; a++)
#define FD(a, b, c) for(int a = b; a >= c; a--)
using namespace std;

int t, a, b, A, pw[N];
set<int> odp;

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C.out", "w", stdout);
	pw[0] = 1;
	
	fi(i, 1, N) pw[i] = pw[i - 1] * 10;
	scanf("%d", &t);
	
	FI(i, 1, t){
		scanf("%d %d", &a, &b);
		A = 0;
		
		FI(j, 1, b){
			int d = 0, x = j;
			for(int y = x; y; d++, y /= 10);
			
			bool flag = 1;
			odp.clear();
			
			FI(k, 1, d){
				int nd = x % 10;
				x = (x / 10) + nd * pw[d - 1];
				
				nd = 0;
				for(int y = x; y; nd++, y /= 10);
				
				if(nd != d) continue;
				
				if(x < j){
					flag = 0;
					break;
				}
				
				if(a <= x && x <= b) 
					odp.insert(x);
			}
			
			if(!flag) continue;
			
			int tot = odp.size();
			A += tot * (tot - 1) >> 1;
		}
		
		printf("Case #%d: %d\n", i, A);
	}
}
