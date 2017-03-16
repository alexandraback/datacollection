#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

const long long N = 123456, K = 100, B = 66, BA = 11;
bool pr[N], T = 101;
long long d[BA][K][B];

void pre(){
	for(long long i=2; i<N; i++) pr[i] = 1;
	for(long long i=2; i<N; i++){
		if( pr[i] ){
			for(long long j=i+i; j<N; j+=i)
				pr[j] = 0;
		}
	}

	for(long long base=2; base<=10; base++){
		for(long long i=2; i<K; i++){
			d[base][i][0] = 1;
			for(long long j=1; j<B; j++){
				d[base][i][j] = (d[base][i][j-1]*base) % i;
			}
		}
	}
}

void solve(){
	
	pre();
	long long n, J;
	scanf("%lld %lld", &n, &J);
	puts("");
	for(long long i=0; i<(1LL<<(n-2)); i++){
		long long cur = (1LL<<(n-1))+(i<<1)+1;
		vector <long long> s;
		bool can = 1;
		for(long long base=2; base<=10; base++){
			bool ok = 0;
			for(long long k=2; k<K; k++){
				long long lef = 0;
				for(long long j=n-1; j>=0; j--){
					if( cur & (1LL<<j) ){
						lef = (lef + d[base][k][j]) % k;
					}
				}
				if( lef == 0 ){
					s.push_back( k );
					ok = 1;
					break;
				}
			}
			if( !ok ){
				can = 0;
				break;
			}
				
		}
		if( J <= 250 ) break;
		if( can ){
			--J;
			//printf("%lld\n", cur);
			for(long long i=n-1; i>=0; i--){
				if( cur & (1LL<<i) ) printf("1");
				else printf("0");
			}
			for(long long i=0; i<9; i++)
				printf(" %d", s[i]);
			puts("");
		}
	}

	for(long long i=(1LL<<(n-2))-1; i>=0; i--){
		long long cur = (1LL<<(n-1))+(i<<1)+1;
		vector <long long> s;
		bool can = 1;
		for(long long base=2; base<=10; base++){
			bool ok = 0;
			for(long long k=2; k<K; k++){
				long long lef = 0;
				for(long long j=n-1; j>=0; j--){
					if( cur & (1LL<<j) ){
						lef = (lef + d[base][k][j]) % k;
					}
				}
				if( lef == 0 ){
					s.push_back( k );
					ok = 1;
					break;
				}
			}
			if( !ok ){
				can = 0;
				break;
			}
				
		}
		if( J <= 0 ) break;
		if( can ){
			--J;
			//printf("%lld\n", cur);
			for(long long i=n-1; i>=0; i--){
				if( cur & (1LL<<i) ) printf("1");
				else printf("0");
			}
			for(long long i=0; i<9; i++)
				printf(" %d", s[i]);
			puts("");
		}
	}
}

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int R=1; R<=T; R++){
		printf("Case #%d: ", R);
		solve();
	}
}