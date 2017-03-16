#include <bits/stdc++.h>

using namespace std;
// Constants and macros
#define INF 		(int)1e9
#define EPS 		1e-9
#define bitcount 	__builtin_popcount
#define gcd 		__gcd
#define forall(i,a,b) 	for(int i=a;i<b;i++)
#define pb 		push_back
#define mp		make_pair
#define MAX(a,b)	( (a)>(b) ? (a):(b))
#define MIN(a,b)	( (a)<(b) ? (a):(b))
#define s(a)		scanf("%d", &a)
#define ss(a,b)		scanf("%d %d", &a,&b)
#define sss(a,b,c)	scanf("%d %d %d", &a,&b,&c)
#define sl(a)		scanf("%I64d", &a)

int T, N, h;
int co[2555];

int main(){
	s(T);
	forall(i,0,T){
		s(N);
		memset(co,0,sizeof co);
		forall(i,0,2*N-1){
			forall(i,0,N){
				s(h);
				co[h]++;
			}
		}
		printf("Case #%d:", i+1);
		forall(j,0,2555){
			if (co[j]%2==1) printf(" %d", j);
		}
		cout << endl;
	}
}
