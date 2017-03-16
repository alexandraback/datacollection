#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iostream>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define x first
#define y second
#define pb push_back

using namespace std;

long double P[2][1000010];
long double r;

int main(){
	int Z;
	scanf("%d", &Z);
	FWD(z,1,Z+1){
		printf("Case #%d: ", z);
		int n, x, y;
		scanf("%d %d %d", &n, &x, &y);
		int w = (abs(x) + y)/2;
		int b = 0;
		FWD(i,0,w)
			b += 4*i+1;
		int f = 4*w+1;
		/*
		printf("\t%d %d %d\n", n, x, y);
		printf("\twarstwa: %d\n", w);
		printf("\twczesniej: %d\n", b);
		printf("\tzapelnienie: %d\n", f);
		printf("\tpozycja: %d\n", y);
		*/
		if(n - b >= f){
			printf("1.0\n");
		}else if(y == 2*w){
			printf("0.0\n");
		}else if(n - b - 2*w >= y + 1){
			printf("1.0\n");
		}else{
			n -= b;
			P[1][0] = 1;
			FWD(i,1,n+1) P[1][i] = 0;
			FWD(i,0,n){
				P[i&1][0] = P[1-(i&1)][0]/2;
				FWD(j,1,n+1)
					P[i&1][j] = (P[1-(i&1)][j-1] + P[1-(i&1)][j])/2;
			}
			r = 0;
			FWD(i,y+1,n+1)
				r += P[1-(n&1)][i];
			printf("%.7Lf\n", r);
		}
	}	
	return 0;
}

