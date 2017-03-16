
#include <cstdio>
#include <cstdlib>
#include <cstring>

int s[4] = {2, 3, 4, 5};
int r[3];
int hash[64][120];

long long Q(long long x) {return x*x; }

int sch(int lev, int lmt, int code){
	if(lev == lmt){
		for(int i=0; i<14000; ++i){
			int mul = 1;
			for(int j=0; j<3; ++j){
				if(rand()&1){
					mul *= r[j];
				}
			}
			hash[code][mul]++;
		}
		return 0;
	}

	for(int i=0; i<4; ++i){
		r[lev] = s[i];
		sch(lev+1, lmt, code+(i<<(2*lev)));
	}
	return 0;
}

int main(){
	
	int t; scanf("%d", &t);
	int r, n, m, k; scanf("%d %d %d %d", &r, &n, &m, &k);

	memset(hash, 0, sizeof(hash));
	sch(0, 3, 0);

	int ttt[120];
	double ratio[64][120];

	printf("Case #1:\n");

	for(int i=0; i<r; ++i){
		memset(ttt, 0, sizeof(ttt));
		for(int j=0; j<k; ++j){
			int x;
			scanf("%d", &x);
			ttt[x] += 2000;
		}

		int ans = 0; long long error = -1;

		for(int j=0; j<64; ++j){
			int fail = 0;
			long long terr = 0;
			for(int k=0; k<120; ++k){
				if(ttt[k] != 0 && hash[j][k] == 0){
					fail = 1;
					break;
				}else{
					terr += Q(ttt[k]-hash[j][k]);
				}
			}
			if(!fail && (error == -1 || terr < error)){
				ans = j;
			}
		}
		
		for(int i=0; i<3; ++i){
			printf("%d", ans%4+2);
			ans/=4;
		}
		printf("\n");
	}

	return 0;
}
