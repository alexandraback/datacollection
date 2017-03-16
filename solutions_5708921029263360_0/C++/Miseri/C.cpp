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

int T, J, P, S, K;

vector<pair<int,int>> p;

void mp(int poff, int soff){
	if (P == 0 || S == 0) return;
	forall(pp, 1, MIN(K,MIN(S,P))+1){
			forall(ss, 1, MIN(K,S)+1){
					p.pb({(pp+poff),(ss+soff)});
			}
	}
	P -= MIN(K,P);
	S -= MIN(K,S);
	mp(MIN(K,P),MIN(K,S));
}

int main(){
	s(T);
	forall(i,0,T){
		sss(J,P,S);
		s(K);
		printf("Case #%d: ", i+1);
		p.clear();
		mp(0,0);
		int lll = p.size(); //cout << "size is" << p.size() << endl;
		printf("%d\n", lll );
		forall(jj, 1, 2){
		forall(j,0, lll){
			printf("%d %d %d\n", jj, p[j].first, p[j].second);
		}
		}
	}
}
