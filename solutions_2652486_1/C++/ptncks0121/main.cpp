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
#include <time.h>

using namespace std;
typedef long long ll;
const int INF = 987654321;
const ll LINF = 1e15;

void precalc();

const int M_ = 9;
const int K_ = 13;
const int R_ = 8005;
const int N_ = 13;

int TC, TCC;
int N, R, M, K;
ll A[R_][K_];
int S[N_*M_];
string Res[R_];

int main() {
    freopen("input.txt", "r", stdin);

    int i, j, k;

    precalc();
    freopen("output.txt", "w", stdout);

    scanf("%d", &TC);
	srand(time(NULL));

    while(++TCC <= TC) {
        printf("Case #%d: ", TCC);

		scanf("%d%d%d%d", &R, &N, &M, &K);
		for(i = 1; i <= R; i++) {
			for(j = 0; j < K; j++) scanf("%lld", &A[i][j]);
			sort(A[i], A[i]+K);
		}

		int LEN = N*(M-1);
		for(i = 0; i < LEN; i++) S[i] = i/N+2;

		int TEST = 100200, X = 7600;
		puts("");
		while(TEST-- && X > 0) {
			random_shuffle(S, S+LEN);
			set<int> Chk;
			for(i = 0; i < (1 << N); i++) {
				ll r = 1;
				for(j = 0; j < N; j++) if(i&(1<<j)) r *= S[j];
				Chk.insert(r);
			}
			for(int L = 1000; L-- && X > 0; ){
				int x = rand() % R + 1;
				if(!Res[x].empty()) { ++L; continue; }
				for(i = 0; i < K; i++) if(Chk.find(A[x][i]) != Chk.end()) break;
				if(i >= K) {
					for(i = 0; i < N; i++) Res[x] += (char)(S[i]+'0');
					--X;
				}
			}
		}
		
		for(i = 1; i <= R; i++) {
			if(Res[i].empty()) Res[i] = "222222222222";
			puts(Res[i].c_str());
		}
    }
    return 0;
}

void precalc() {
}
