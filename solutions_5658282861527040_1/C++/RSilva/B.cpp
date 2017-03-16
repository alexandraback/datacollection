#include<cstdio>
#include<algorithm>

using namespace std;
typedef long long int lint;

int casos, a, b, k;
lint memo[64][3][3][3];

int ligado(int x, int pos){
	return ((x&(1<<pos)) > 0) ? 1 : 0;
}

int nxt(int vai, int bit, int estrito){
	return (estrito && vai == bit) ? 1 : 0;
}

lint pd(int pos, int ek, int ea, int eb){
	int bitk, bita, bitb, nek, nea, neb;
	lint x = 0LL;
	
	if(pos == -1) return (ek||ea||eb) ? 0LL : 1LL;
	if(memo[pos][ek][ea][eb] != -1LL) return memo[pos][ek][ea][eb];
	
	memo[pos][ek][ea][eb] = 0LL;
	bitk = (ek && !ligado(k, pos)) ? 0 : 1;
	bita = (ea && !ligado(a, pos)) ? 0 : 1;
	bitb = (eb && !ligado(b, pos)) ? 0 : 1;
	for(int l=0;l<=bitk;l++){
		for(int i=0;i<=bita;i++){
			for(int j=0;j<=bitb;j++){
				if((i&j) != l) continue;
				nek = nxt(l, bitk, ek);
				nea = nxt(i, bita, ea);
				neb = nxt(j, bitb, eb);
				memo[pos][ek][ea][eb] += pd(pos-1, nek, nea, neb);
			}
		}
	}
	return memo[pos][ek][ea][eb];
}

int main(){
	scanf(" %d", &casos);
	for(int inst=1;inst<=casos;inst++){
		scanf(" %d %d %d", &a, &b, &k);
		for(int x=0;x<=32;x++)
			for(int y=0;y<2;y++)
				for(int z=0;z<2;z++)
					for(int w=0;w<2;w++)
						memo[x][y][z][w] = -1LL;
		pd(30, 1, 1, 1);
		printf("Case #%d: %lld\n", inst, memo[30][1][1][1]);	
	}
	return 0;
}