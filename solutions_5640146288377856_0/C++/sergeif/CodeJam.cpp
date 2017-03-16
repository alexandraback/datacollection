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

int field[30];
int prob[30];

bool placeNoHitShip(int c, int l, int prob[], int field[]) {
	memset(prob, 0, sizeof(int) * c);
	bool bCan = false;
	for (int i=0; i<c-l+1; i++) {
		bool bCanPlace = true;
		for (int j=0; j<l && i+j<c; j++) {
			if (field[i+j] > 0) {
				bCanPlace = false;
				break;
			}
		}
		if (bCanPlace) {
			bCan = true;
			for (int j=0; j<l && i + j < c; j++) {
				prob[i+j] += 1;
				
			}
		}
	}
	return bCan;
}
bool placeHittedShip(int c, int l, int prob[], int field[]) {
	memset(prob, 0, sizeof(int) * c);
	bool bCan = false;
	for (int i=0; i<c-l+1; i++) {
		bool bHitted = false;
		for (int j=0; j<l && i+j<c; j++) {
			if (field[i+j] > 0) {
				bHitted = true;
			}
		}
		bool bNHitted = false;
		for (int j=l; j<c && i+j<c; j++) {
			if (field[i+j] > 0)
				bNHitted = true;
		}
		if (bHitted && ! bNHitted) {
			for (int j=0; j<l && i+j<c; j++) {
				if (field[i+j] == 0){
					prob[i+j] += 1;
					bCan = true;
				}
			}
		}
	}
	return bCan;
}

int solve(int r, int c, int x)
{
	int res = 0;

	memset(field, 0, sizeof(int) * c);
	while (placeNoHitShip(c, x, prob, field)) {
		int imax = 0;
		for (int i=0; i<c; i++) {
			if (prob[i] > prob[imax]) imax = i;
		}
		res += 1;
		field[imax] = 1;
	}
	while (placeHittedShip(c, x, prob, field)) {
		int imax = 0;
		for (int i=0; i<c; i++) {
			if (prob[i] > prob[imax]) imax = i;
		}
		res += 1;
		field[imax] = 1;
	}
	return res;
}

int main()
{
	int t, T;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		int N, R, C;
		cin >> R >> C >> N;
		int res = solve(R, C, N);
		cout << "Case #" << t << ": " << res << endl;
	}

	return 0;
}
