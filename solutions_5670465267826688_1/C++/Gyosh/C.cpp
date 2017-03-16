#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>

#define REP(a,b) for (int a = 0; a < b; a++)
#define FOR(a,b,c) for (int a = b; a <= c; a++)
#define RESET(a,b) memset(a,b,sizeof a)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define PII pair<int,int>

#define MAXN 10005
#define LL long long
using namespace std;

int T;
int L;
LL X;
char sc[MAXN];

LL pref[MAXN], suff[MAXN];
LL ai[MAXN], ak[MAXN], all;
LL mu, lambda;

int mtable[5][5] = 
	{{0, 0, 0, 0, 0},
	 {0, 1, 2, 3, 4},
	 {0, 2, -1, 4, -3},
	 {0, 3, -4, -1, 2},
	 {0, 4, 3, -2, -1}};

int toInt(char c){
	if (c == 'i') return 2;
	if (c == 'j') return 3;
	if (c == 'k') return 4;
	return 1; //invalid
}

int mul(int a, int b){
	int sig = (a * b < 0) ? -1 : 1;
	return mtable[abs(a)][abs(b)] * sig;
}

void prec(){
	all = 1;
	REP(i,L){
		all = mul(all, toInt(sc[i]));
	}

	// for i
	int now = 1;
	REP(i,L){
		now = mul(now, toInt(sc[i]));
		pref[i] = now;

		if (now == toInt('i')){
			ai[i] = 0;
		}else{
			ai[i] = -1;
			int temp = now;
			REP(j,4){
				temp = mul(all, temp);
				if (temp == toInt('i')){
					ai[i] = j+1;
					break;
				}
			}
		}
	}

	// for k
	now = 1;
	for (int i = L-1; i >= 0; i--){
		now = mul(toInt(sc[i]), now);
		suff[i] = now;

		if (now == toInt('k')){
			ak[i] = 0;
		}else{
			ak[i] = -1;
			int temp = now;
			REP(j,4){
				temp = mul(temp, all);
				if (temp == toInt('k')){
					ak[i] = j+1;
					break;
				}
			}
		}
	}

	// REP(i,L){
	// 	printf("%d %d %d\n", i, ai[i], ak[i]);
	// }
}

void findCycle(){
	map<int,int> peta;

	int cnt = 1;
	int now = all;
	
	while (peta.count(now) == 0){
		peta[now] = cnt++;
		now = mul(now, all);
	}
	mu = peta[1];
	lambda = cnt - peta[now];
}

bool separated(){
	REP(i,L){
		REP(j,L){
			// no way!
			if ((ai[i] == -1) || (ak[j] == -1)) continue;

			LL ni = ai[i];
			LL nk = ak[j];

			int chead = (i+1 < L) ? suff[i+1] : 1;
			int ctail = (j-1 >= 0) ? pref[j-1] : 1;
			LL nj = -1;
			REP(k,4){
				int cnow = chead;
				REP(ex,k){
					cnow = mul(cnow, all);
				}
				cnow = mul(cnow, ctail);

				if (cnow == toInt('j')){
					nj = k;
					break;
				}
			}

			if (nj == -1) continue;

			// needed
			LL xt = X - ni - nj - nk - 2;
			if (xt < 0) continue;

			// success without blocks
			if (xt == 0) return 1;

			// must spent some blocks
			if ((xt - 3*mu) % lambda == 0) return 1;
		}
	}
	return 0;
}

bool merged(){
	REP(i,L){
		int middle = 1;
		FOR(j,i+2,L-1){
			middle = mul(middle, toInt(sc[j-1]));

			// no way!
			if ((ai[i] == -1) || (ak[j] == -1)) continue;
			if (middle != toInt('j')) continue;

			LL ni = ai[i];
			LL nk = ak[j];

			LL xt = X - ni - nk - 1;
			if (xt < 0) continue;
			if (xt == 0) return 1;
			if ((xt - 2*mu) % lambda == 0) return 1;
		}
	}
	return 0;
}

bool work(){
	return merged() || ((X > 1) && separated());
}

int main(){		
	scanf("%d", &T);
	REP(jt,T){
		scanf("%d %lld", &L, &X);
		scanf("%s", sc);

		prec();
		findCycle();
		bool ans = work();

		printf("Case #%d: %s\n", jt+1, ans ? "YES" : "NO");
		fflush(stdout);
	}
	return 0;
}
