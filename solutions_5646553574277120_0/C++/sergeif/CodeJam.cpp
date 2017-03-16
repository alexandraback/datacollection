#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;
#define FOR(k,a,b) for(typeof(a) k=(a); k <= (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define REPD(k,a) for(int k=(a)-1; k >= 0; --k)
#define PB push_back 
#define MP make_pair

int coins[100];
int check[100];
int candidate[100];
int bcoins[100];

bool rev(int C, int c, int V) {
	if (V < 0) return false;
	if (V == 0) return true;
	if (c == C) return false;
	return rev(C, c+1, V - coins[c]) || rev(C, c+1, V); 
}

bool CheckAll(int C, int V) {
	bool bRes = true;
	for (int i=1; i<=V; ++i) {
		if ( ! rev(C, 0, V)) bRes = false;
	}
	return bRes;
}

int main()
{
	int t, T;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		int D,C,N;
		auto ures = 0;
		cin >> C >> D >> N;
		memset(bcoins, 0, sizeof(int) * (N+1));
		for (int i=0; i<D; ++i) {
			cin >> candidate[i];
			bcoins[candidate[i]] = 1;
		}
		if (bcoins[1] == 0 && N >= 1) {
			bcoins[1] = 1;
			D++;
			ures++;
		}
		if (bcoins[2] == 0 && N >= 2) {
			bcoins[2] = 1;
			D++;
			ures++;
		}
		if (bcoins[4] == 0 && N >= 4 && bcoins[3] == 0) {
			bcoins[4] = 1;
			D++;
			ures++;
		}
		if (bcoins[5] == 0 && N >= 5 && bcoins[3] == 0 && bcoins[4] == 0) {
			bcoins[4] = 1;
			D++;
			ures++;
		}
		for (int i=6; i<=N; i++) {
			if (bcoins[i] == 1) continue;
			bool bOk = false;
			for (int j=1; j<i && ! bOk; j++) {
				if (bcoins[j] == 1 && bcoins[i-j] == 1) bOk = true;
			}
			if (bOk) continue;
			for (int j=1; j<i; j++) {
				if (bcoins[j] == 0 && bcoins[i-j] == 1) {
					ures++;
					bcoins[j] = 1;
					break;
				}
			}
		}

		cout << "Case #" << t << ": " << ures << endl;
	}

	return 0;
}
