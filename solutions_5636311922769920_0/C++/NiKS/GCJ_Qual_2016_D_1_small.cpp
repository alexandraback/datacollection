#include<cstdio>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int T, K, C, S; //S is not long long as S==K

int main(){
	scanf("%d", &T);
	REP(t, 1, T+1){
		printf("Case #%d:", t);
		scanf("%d%d%d", &K, &C, &S);
		REP(i, 1, S+1) printf(" %d", i);
		printf("\n");
	}
	return 0;
}
