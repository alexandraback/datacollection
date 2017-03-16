#include <cstdio>
#include <cstring>
using namespace std;

int N, J;
int mod2[11][50], mod3[11][50], mod5[11][50], mod7[11][50];
int bit[50];
int now2[11], now3[11], now5[11], now7[11];

void show() {
	for(int i=N-1; i>=0; --i)
		putchar(bit[i] + '0');
	for(int i=2; i<=10; ++i) {
		if     ( now2[i]%2 == 0 ) printf(" 2");
		else if( now3[i]%3 == 0 ) printf(" 3");
		else if( now5[i]%5 == 0 ) printf(" 5");
		else printf(" 7");
	}
	puts("");
}
bool ok() {
	int okNum = 0;
	for(int i=2; i<=10; ++i)
		if( now2[i]%2==0 || now3[i]%3==0 
			|| now5[i]%5==0 || now7[i]%7==0 )
			++okNum;
	return okNum == 9;
}
void next() {
	int id = 1;
	while( bit[id]==1 ) {
		bit[id] = 0;
		for(int i=2; i<=10; ++i) {
			now2[i] = (now2[i]-mod2[i][id]+2)%2;
			now3[i] = (now3[i]-mod3[i][id]+3)%3;
			now5[i] = (now5[i]-mod5[i][id]+5)%5;
			now7[i] = (now7[i]-mod7[i][id]+7)%7;
		}
		++id;
	}
	bit[id] = 1;
	for(int i=2; i<=10; ++i) {
		now2[i] = (now2[i]+mod2[i][id])%2;
		now3[i] = (now3[i]+mod3[i][id])%3;
		now5[i] = (now5[i]+mod5[i][id])%5;
		now7[i] = (now7[i]+mod7[i][id])%7;
	}
}

int main() {
	for(int i=2; i<=10; ++i) {
		int v2=1, v3=1, v5=1, v7=1;
		for(int j=0; j<50; ++j) {
			mod2[i][j] = v2;
			mod3[i][j] = v3;
			mod5[i][j] = v5;
			mod7[i][j] = v7;
			v2 = v2*i % 2;
			v3 = v3*i % 3;
			v5 = v5*i % 5;
			v7 = v7*i % 7;
		}
	}

	int T;
	scanf("%d", &T);
	for(int NOWCASE=1; NOWCASE<=T; ++NOWCASE) {
		scanf("%d%d", &N, &J);
		printf("Case #%d:\n", NOWCASE);
		memset(bit, 0, sizeof(bit));
		bit[0] = bit[N-1] = 1;
		for(int i=2; i<=10; ++i) {
			now2[i] = (mod2[i][0] + mod2[i][N-1])%2;
			now3[i] = (mod3[i][0] + mod3[i][N-1])%3;
			now5[i] = (mod5[i][0] + mod5[i][N-1])%5;
			now7[i] = (mod7[i][0] + mod7[i][N-1])%7;
		}
		while( J-- ) {
			while( !ok() )
				next();
			show();
			next();
		}
	}
	return 0;
}
