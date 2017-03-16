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
	int T,c=0;
	int A[100][100];
	S(T);
	while(T--) {
		int N,M;
		S(N);S(M);
		c++;
		rep(i,0,N) rep(j,0,M) S(A[i][j]);
		int flag=0;
		rep(i,0,N) {
			rep(j,0,M) {
				int f1=0,f2=0;
				rep(k,0,N) if(A[k][j] > A[i][j]) f1=1;
				rep(k,0,M) if(A[i][k] > A[i][j]) f2=1;
				
				if(f1+f2 == 2) {flag=1;break;}
			}
			if(flag) break;
		}
		if(flag) {
			printf("Case #%d: NO\n",c);
		} else {
			printf("Case #%d: YES\n",c);
		}
	}
	return 0;
}
