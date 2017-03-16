#include <cstdio>

int T, n;
int chk[11];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);

	int i, j, t, dig;
	long long tmp, tmpp;

	for(scanf("%d", &T), t=1; T>=1; T--){
		printf("Case #%d: ", t++);
		for(i=0; i<=9; i++) chk[i] = 0;

		scanf("%d", &n);
		if ( n == 0 ){ printf("INSOMNIA\n"); continue; }

		for(j=1, tmp=n, dig=0;; j++){
			tmpp = tmp;
			for(;;){
				if ( !chk[tmpp%10] ){ dig ++, chk[tmpp%10] = 1; }
				if ( dig == 10 ) break;
				tmpp /= 10;
				if ( tmpp == 0 ) break;
			}

			if ( dig == 10 ){
				printf("%d\n", tmp);
				break;
			} tmp += n;
		}
	}

	return 0;
}