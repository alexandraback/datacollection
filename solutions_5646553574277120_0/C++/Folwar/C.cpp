#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

#include<algorithm>
#include<utility>
#include<string>

#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>

using namespace std;

#define REP(i,N) for (int i = 0; i < (N); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, b, a) for (int i = (b) - 1; i >= a; i--)
#define DP(arg...) fprintf(stderr, ## arg) //COMPILER SPECIFIC!!!

typedef long long ll;

int T;
int C, D, V;

#define EXP 17

bool POS[1000];
bool inp[1000];
bool pos[40];

int zkus(int kod) {
	int r = 0;
	for (int i = 1; i <= V; i++)
		pos[i] = POS[i];
	for (int d = 1; d <= EXP && d <= V; d++) {
		if (!inp[d]) {
			if (kod & (1<<(d-1))) {
				r++;
				vector<int> n;
				n.push_back(d);
				for (int i = 1; i <= V-d;i++) {
					if (pos[i]) n.push_back(i+d);
				}
				for (auto x:n) pos[x] = true;
			}
		}
	}
	for (int i = 1; i<= V; i++)
		if (!pos[i]) return 100;
	//DP("r %d\n", r);
	return r;

}

void solve(int _case) {
	scanf("%d%d%d", &C, &D, &V);
	int sol = 1000;
	for (int v = 1; v <= V; v++) {
		inp[v] = false;
		POS[v] = false;
	}
	REP(d,D) {
		int w; scanf("%d", &w);
		inp[w] = true;
		vector<int> n;
		n.push_back(w);
		for (int v = 1; v <= V; v++) {
			if (POS[v])
				n.push_back(v+w);
		}
		for (auto x:n) POS[x] = true;
	}
	for (int i = 0; i < (1<<(EXP+1)); i++)
		sol = min(sol,zkus(i));
	/*
	for (int i = 1; i <= V; i++) DP("%d-%d ", i, POS[i]);
	int kolik = 0;
	for (int i = 1; i <= V; i++) kolik += (POS[i]?1:0);
	DP("kolik %d\n", kolik);
	int kl = 1;
	while (kolik < V) {
		int val = 0;
		for (int i = 1; i <= V; i++){
			if (!POS[i]) { val = i; break; }}
		while (kl*2 <= val) kl *= 2;
		DP("val %d kl %d\n", val, kl);
		sol++;
		vector<int> n;
		n.push_back(kl);
		for (int i = 1; i <= V-kl; i++) {
			if (POS[i]) {
				if (!POS[i+kl]) {
					kolik++;
				}
				n.push_back(i+kl);
			}
		}
		if (!POS[kl]) kolik++;
		POS[kl] = true;
		for (auto x:n) POS[x] = true;
		DP("kolik %d\n", kolik);
	}
	*/
	printf("Case #%d: %d\n", _case, sol);
}

int main() {
	scanf("%d", &T);
	REP(t,T) solve(t+1);
	return 0;
}
