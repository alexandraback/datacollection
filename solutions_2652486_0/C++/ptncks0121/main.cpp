#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>

using namespace std;
typedef long long ll;
const int INF = 987654321;
const ll LINF = 1e15;

void precalc();

const int M_ = 6;
const int K_ = 13;

int TC, TCC;
map<int, int> T[M_][M_][M_];
int N, R, M, K;
int S[K_];
int C[200];
int main() {
    freopen("input.txt", "r", stdin);

    int i, j, k;

    precalc();
    freopen("output.txt", "w", stdout);

    scanf("%d", &TC);
    while(++TCC <= TC) {
        printf("Case #%d: ", TCC);

		for(i = 2; i <= 5; i++) {
			for(j = 2; j <= 5; j++) {
				for(k = 2; k <= 5; k++) {
					++T[i][j][k][1];
					++T[i][j][k][i];
					++T[i][j][k][j];
					++T[i][j][k][k];
					++T[i][j][k][i*j];
					++T[i][j][k][i*k];
					++T[i][j][k][j*k];
					++T[i][j][k][i*j*k];
				}
			}
		}

		scanf("%d%d%d%d", &R, &N, &M, &K);
		puts("");
		while(R--) {
			bool ret = 1;  memset(C,0,sizeof C);
			for(i = 1; i <= K; i++) scanf("%d", &S[i]), ++C[S[i]];
			for(i = 2; i <= 5 && ret; i++) {
				for(j = 2; j <= 5 && ret; j++) {
					for(k = 2; k <= 5 && ret; k++) {
						int t;
						for(t = 1; t <= K; t++) if(!!T[i][j][k][S[t]] != !!C[S[t]]) break;
						if(t > K){ 
							printf("%d%d%d\n", i, j, k); ret = 0; 
						}
					}
				}
			}
			if(ret) puts("555");
		}
    }
    return 0;
}

void precalc() {
}
