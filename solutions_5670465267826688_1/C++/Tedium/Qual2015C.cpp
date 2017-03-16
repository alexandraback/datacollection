#include <list>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <ext/hash_map>
#include <stdint.h>
#include <ctime>
#include <queue>
#include <sstream>
#include <sys/time.h>
#include <fstream>
#include <vector>

using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef long long LL;
typedef unsigned char BYTE;

#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define FORU(i, s, e) for (int i = (s); i <= (e); ++i)
#define FORD(i, s, e) for (int i = (s); i >= (e); --i)
#define ALL(x) x.begin(),x.end()
#define FOREACH(i, v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define SIZE(x) ((int)x.size())
#define MP make_pair
#define PB push_back
#define BIT(x, b) (((x) >> (b)) & 1)
#define SWAP(a, b, t) do {t = a; a = b; b = t;} while (0);
#define INF 1000000000
#define EPS 1e-9
#define TIME_LEFT_UNTIL(end) ((curTime=getTime()-startTime) < (end))
#define TIME_LEFT() TIME_LEFT_UNTIL(MAX_TIME)
#define INIT_TIME() startTime = getTime()

inline double getTime () {
   timeval tv;
   gettimeofday(&tv, 0);
   return tv.tv_sec + tv.tv_usec * 1e-6;
}

#define P1 0
#define Pi 1
#define Pj 2
#define Pk 3
#define N1 4
#define Ni 5
#define Nj 6
#define Nk 7

int mult[8][8];
int inverse[8];
int v[12345];
int prodUp[12345];
int prodDown[12345];

bool small (int L, int X) {
	int LX = L * X;
	FORU(i, L, LX-1)
		v[i] = v[i % L];

	prodUp[0] = v[0];
	FORU(i, 1, LX-1)
		prodUp[i] = mult[prodUp[i-1]][v[i]];
	prodDown[LX-1] = v[LX-1];
	FORD(i, LX-2, 0)
		prodDown[i] = mult[v[i]][prodDown[i+1]];

	FOR(i, LX) {
		if (prodUp[i] != Pi)
			continue;
		FORU(j, i+2, LX-1)
			if (prodDown[j] == Pk && mult[inverse[prodUp[i]]][prodUp[j-1]] == Pj)
				return 1;
	}
	return 0;
}

int main () {
	double time = getTime();
	mult[P1][P1] = P1;
	mult[P1][Pi] = Pi;
	mult[P1][Pj] = Pj;
	mult[P1][Pk] = Pk;

	mult[Pi][P1] = Pi;
	mult[Pi][Pi] = N1;
	mult[Pi][Pj] = Pk;
	mult[Pi][Pk] = Nj;

	mult[Pj][P1] = Pj;
	mult[Pj][Pi] = Nk;
	mult[Pj][Pj] = N1;
	mult[Pj][Pk] = Pi;

	mult[Pk][P1] = Pk;
	mult[Pk][Pi] = Pj;
	mult[Pk][Pj] = Ni;
	mult[Pk][Pk] = N1;

	FOR(i, 8)
		FOR(j, 8) {
			if ((i > 3) ^ (j > 3))
				mult[i][j] = (mult[i % 4][j % 4] + 4) % 8;
			else
				mult[i][j] = mult[i % 4][j % 4];
		}

	inverse[P1] = P1;
	inverse[Pi] = Ni;
	inverse[Pj] = Nj;
	inverse[Pk] = Nk;
	inverse[N1] = N1;
	inverse[Ni] = Pi;
	inverse[Nj] = Pj;
	inverse[Nk] = Pk;

	int T;
	scanf("%d", &T);
	FOR(itr, T) {
		int L, X;
		scanf("%d%d\n", &L, &X);

		FOR(i, L) {
			char c;
			scanf("%c", &c);
			if (c == 'i')
				v[i] = Pi;
			else if (c == 'j')
				v[i] = Pj;
			else if (c == 'k')
				v[i] = Pk;
			else {
				cerr << "Bad input: '" << c << "'" << endl;
				return 0;
			}
		}

		prodUp[0] = v[0];
		FORU(i, 1, L-1)
			prodUp[i] = mult[prodUp[i-1]][v[i]];
		prodDown[L-1] = v[L-1];
		FORD(i, L-2, 0)
			prodDown[i] = mult[v[i]][prodDown[i+1]];

		int tot[4];
		tot[0] = P1;
		FORU(i, 1, 3)
			tot[i] = mult[tot[i-1]][prodDown[0]];
		if (mult[tot[3]][prodDown[0]] != P1) {
			cerr << "Group Fail" << endl;
			return 0;
		}

		bool out = 0;
		int p1, p2, p2a, p2b, p3, Xleft;
		FOR(i, L) {
			p1 = prodUp[i];
			bool possible = 0;
			for (int j = 0; j < 4 && j < X; ++j)
				if (mult[tot[j]][p1] == Pi) {
					possible = 1;
					break;
				}
			if (!possible)
				continue;

			FOR(j, L) {
				if (X == 1 && j-i < 1)
					continue;
				p3 = prodDown[j];
				if (X > 1) {
					Xleft = X-2;
					p2a = (i == L-1 ? P1 : prodDown[i+1]);
					p2b = (j == 0 ? P1 : prodUp[j-1]);

					for (int k = 0; k <= Xleft && k < 4; ++k) {
						if (mult[tot[k]][p1] != Pi)
							continue;
						for (int m = 0; k+m <= Xleft && m < 4; ++m)
							if (mult[mult[p2a][tot[m]]][p2b] == Pj && mult[p3][tot[(Xleft-k-m)%4]] == Pk) {
								out = 1;
								break;
							}
					}
					if (out)
						break;
				}
				if (j - i > 1) {
					Xleft = X-1;
					p2 = mult[inverse[prodUp[i]]][prodUp[j-1]];
					if (p2 != Pj)
						continue;

					for (int k = 0; k <= Xleft && k < 4; ++k) {
						if (mult[tot[k]][p1] == Pi && mult[p3][tot[(Xleft-k)%4]] == Pk) {
							out = 1;
							break;
						}
					}
					if (out)
						break;
				}
			}
			if (out)
				break;
		}

//		if (small(L, X) != out) {
//			cerr << "Case " << itr+1 << endl;
//		}

		if (out)
			printf("Case #%d: YES\n", itr+1);
		else
			printf("Case #%d: NO\n", itr+1);
	}
	cerr << getTime() - time << endl;
}
