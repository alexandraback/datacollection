#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int perm[100];
int MAX_BAN;

void solve( int k, char *KK, char *sol, int n, char *target, int next = 0 )
{
    
    if( k == n )
    {
		int nn = strlen(sol),
		m = strlen(target);

		if( m > nn ) return;

		int cnt = 0;
		for(int i = 0; i <= nn - m; i++ )
		if( strncmp(&sol[i], target, m) == 0 )
			cnt++;
		MAX_BAN = max(MAX_BAN, cnt);
		perm[cnt]++;
		return ;
    }

    int word = strlen(KK);
    
    int i;
    for( i = 0; i < word; i++ ) {
		sol[k] = KK[i];
		solve(k + 1, KK, sol, n, target, next + 1);
		
		for(int cc = 2; cc <= 10; cc++)
			sol[k] = 0;
    }

}

int T, t, K, L, S;
char s[100], target[100];

int main( void ) {
		scanf("%d", &T);

		for( t = 1; t <= T; t++ ) {
		scanf("%d %d %d", &K, &L, &S);
		scanf("%s %s", s, target);

		memset(perm, 0, sizeof(perm));
		char A[100] = {0};
		MAX_BAN = 0;

		solve(0, s, A, S, target);
		double ans = 0.0;
		for(int i = 0; i <= 10; i++ )
			ans += i * perm[i] * 1.0 / pow(K, S);

		printf("Case #%d: %.10f\n", t, MAX_BAN - ans);
    }

    return 0;
}
